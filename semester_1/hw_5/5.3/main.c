#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void readExpression(char *inputExpression);
void initializeTheString(char *currentString);
void infixToPostfix(char *infixExpression, char *prefixExpression);
float counting(char *expression);

enum token {RIGHTBRACKET, LEFTBRACKET, PLUS, MINUS, MULTIPLY, DIVIDE, ANOTHERTOKEN};
enum tokensType {NUMBER, FUNCTION, BRACKET, ANOTHERTYPE};

int main()
{
  int sizeOfExpression = 128;
  char* inputExpression = calloc(sizeOfExpression, sizeof(char));

  printf("Enter an expression in infix form : ");
  readExpression(inputExpression);

  int sizeOfInfixexpression = strlen(inputExpression);
  char* prefixExpression = calloc(sizeOfInfixexpression, sizeof(char));

  infixToPostfix(inputExpression, prefixExpression);

  float result = counting(prefixExpression);
  printf("result = %lf\n", result);
  free(inputExpression);
  free(prefixExpression);
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

  return ANOTHERTYPE;
}

void addToken(char token, char *inputExpression)
{
  if (typeOfToken(token) != ANOTHERTYPE)
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

float evaluationSimplestExpression(char operator, float operand1, float operand2)
{
  switch (operator)
  {
    case '+':
    {
      return operand1 + operand2;
    }
    case '-':
    {
      return operand1 - operand2;
    }
    case '*':
    {
      return operand1 * operand2;
    }
    case '/':
    {
      return operand1 / operand2;
    }
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
    else if (typeOfToken(currentToken) == BRACKET)
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
  while (!isEmpty(stack))
  {
    prefixExpression[strlen(prefixExpression)] = (char)pop(stack);
  }

  free(stack);
}

int characterToInt(char characer)
{
  return (int)characer - '0';
}

float counting(char *expression)
{
  struct Stack* stackOfNumbers = createStack();

  int sizeOfExpression = strlen(expression);
  for (int i = 0; i < sizeOfExpression; i++)
  {
    char currentToken = expression[i];
    if (typeOfToken(currentToken) == NUMBER)
    {
      int number = characterToInt(currentToken);
      push(number, stackOfNumbers);
    }
    else
    {
      float numberSecond = pop(stackOfNumbers);
      float numberFirst = pop(stackOfNumbers);
      float simplestResult = evaluationSimplestExpression(currentToken, numberFirst, numberSecond);
      push(simplestResult, stackOfNumbers);
    }
  }
  float result = pop(stackOfNumbers);
  free(stackOfNumbers);
  return result;
}
