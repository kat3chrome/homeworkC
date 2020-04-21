#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack.h"

bool readExpression(char *inputExpression);
bool infixToPostfix(char *infixExpression, char *prefixExpression);

enum token {RIGHTBRACKET, LEFTBRACKET, PLUS, MINUS, MULTIPLY, DIVIDE, SPACE, ANOTHERTOKEN};
enum tokensType {NUMBER, FUNCTION, BRACKET, ANOTHERTYPE};

int main()
{
  const int sizeOfExpression = 128;
  bool condition = false;
  char* inputExpression = calloc(sizeOfExpression, sizeof(char));

  printf("Enter an expression in infix form : ");
  condition = readExpression(inputExpression);

  int sizeOfInfixExpression = strlen(inputExpression) * 2;
  char* prefixExpression = calloc(sizeOfInfixExpression, sizeof(char));

  if (condition)
  {
    condition = infixToPostfix(inputExpression, prefixExpression);
  }

  if (condition)
  {
    printf("Expression in postfix form : %s\n", prefixExpression);
  }

  free(inputExpression);
  free(prefixExpression);
  return 0;
}

int getPriorityOfToken(char token)
{
  switch (token)
  {
    case '(':
    return RIGHTBRACKET;
    case ')':
    return LEFTBRACKET;
    case '+':
    return PLUS;
    case '-':
    return MINUS;
    case '*':
    return MULTIPLY;
    case '/':
    return DIVIDE;
    default:
    return ANOTHERTOKEN;
  }
}

int typeOfToken(char token)
{
  int tokenNumber = (int)token;

  if (tokenNumber - '0' >= 0 && tokenNumber - '9' <= 0)
  {
    return NUMBER;
  }
  else if (tokenNumber == '+' || tokenNumber == '-' || tokenNumber == '*' || tokenNumber == '/')
  {
    return FUNCTION;
  }
  else if (tokenNumber == '(' || tokenNumber == ')')
  {
    return BRACKET;
  }
  else if (tokenNumber == ' ')
  {
    return SPACE;
  }

  return ANOTHERTYPE;
}

bool addToken(char token, char *inputExpression)
{
  if (typeOfToken(token) != ANOTHERTYPE)
  {
    inputExpression[strlen(inputExpression)] = token;
    return true;
  }
  else
  {
    printf("Error with input charasters!\n");
    return false;
  }
}

bool readExpression(char *inputExpression)
{
  char token;
  bool condition = false;
  while ((token = getchar()) != '\n')
  {
    condition = addToken(token, inputExpression);
    if (!condition)
    {
      return condition;
    }
  }
  return true;
}

bool infixToPostfix(char *infixExpression, char *prefixExpression)
{
  struct Stack* stack = createStack();

  int sizeOfExpression = strlen(infixExpression);
  for (int i = 0; i < sizeOfExpression; i++)
  {
    char currentToken = infixExpression[i];
    int typeOfCurrentToken = typeOfToken(currentToken);
    if (typeOfCurrentToken == NUMBER)
    {
      prefixExpression[strlen(prefixExpression)] = currentToken;
    }
    else if (typeOfCurrentToken == FUNCTION)
    {
      if (isEmpty(stack) || (char)peek(stack) == '(')
      {
        push((float)currentToken, stack);
      }
      else if (getPriorityOfToken(currentToken) > getPriorityOfToken((char)peek(stack)))
      {
        push((float)currentToken, stack);
      }
      else if (getPriorityOfToken(currentToken) <= getPriorityOfToken((char)peek(stack)))
      {
        while (getPriorityOfToken(currentToken) <= getPriorityOfToken((char)peek(stack)) && (char)peek(stack) != '(')
        {
          prefixExpression[strlen(prefixExpression)] = (char)pop(stack);
          if (isEmpty(stack))
          {
            break;
          }
        }
        push((float)currentToken, stack);
      }
    }
    else if (typeOfCurrentToken == BRACKET)
    {
      if (currentToken == '(')
      {
        push(currentToken, stack);
      }
      else
      {
        while (!isEmpty(stack) && (char)peek(stack) != '(')
        {
          prefixExpression[strlen(prefixExpression)] = (char)pop(stack);
        }
        if (!isEmpty(stack))
        {
          pop(stack);
        }
        else
        {
          printf("Error with bracket!\n");
          free(stack);
          return false;
        }
      }
    }
  }
  int index = strlen(prefixExpression);
  while (!isEmpty(stack))
  {
    if ((char)peek(stack) == '(')
    {
      printf("Error with bracket!\n");
      deleteStack(stack);
      return false;
    }

    prefixExpression[index] = (char)pop(stack);
    index++;
  }
  free(stack);
  return true;
}
