#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void readExpression(char *inputExpression);
void initializeTheString(char *currentString);
void infixToPostfix(char *infixExpression, char *prefixExpression);

enum token {RIGHTBRACKET, LEFTBRACKET, PLUS, MINUS, MULTIPLY, DIVIDE, ANOTHER};
enum tokensType {NUMBER, FUNCTION, BRACKET};

int main()
{
  const int sizeOfExpression = 128;
  char inputExpression[sizeOfExpression];
  initializeTheString(inputExpression);

  printf("Enter an expression in infix form : ");
  readExpression(inputExpression);

  int sizeOfInfixExpression = strlen(inputExpression);
  char prefixExpression[sizeOfInfixExpression];
  initializeTheString(prefixExpression);

  infixToPostfix(inputExpression, prefixExpression);

  printf("Expression in postfix form : %s\n", prefixExpression);
  return 0;
}

void initializeTheString(char *currentString)
{
  int stringLenght = strlen(currentString);
  for (int i = 0; i < stringLenght; i++)
  {
    currentString[i] = '\0';
  }
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
      return ANOTHER;
  }
}

int typeOfToken(char token)
{
  int tokenNumber = (int)token;

  if (tokenNumber - '0' >= 0 && tokenNumber - '9' <= 0)
  {
    return 0;//number
  }
  else if (tokenNumber == '+' || tokenNumber == '-' || tokenNumber == '*' || tokenNumber == '/')
  {
    return 1;//function
  }
  else if (tokenNumber == '(' || tokenNumber == ')')
  {
    return 2;//bracket
  }

  return 3;//not process
}

void addToken(char token, char *inputExpression)
{
  if (typeOfToken(token) != 3)
  {
    inputExpression[strlen(inputExpression)] = token;
  }
}

void readExpression(char *inputExpression)
{
  char token;
  while ((token = getchar()) != '\n')
  {
    addToken(token, inputExpression);
  }
}

void infixToPostfix(char *infixExpression, char *prefixExpression)
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
          while ((char)peek(stack) != '(')
          {
            prefixExpression[strlen(prefixExpression)] = (char)pop(stack);
          }
          pop(stack);
        }
      }
    }
    int index = strlen(prefixExpression);
    while (!isEmpty(stack))
    {
      prefixExpression[index] = (char)pop(stack);
      index++;
    }
}
