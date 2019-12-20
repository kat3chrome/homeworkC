#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

float counting(char *expression);
void readExpression(char *inputExpression);
void initializeTheString(char *currentString);

enum tokensType {NUMBER, FUNCTION, ANOTHERTYPE};

int main()
{
  int sizeOfExpression = 32;
  char *inputExpression = calloc(sizeOfExpression, sizeof(char));

  printf("Enter the expression : ");
  readExpression(inputExpression);

  float result = counting(inputExpression);
  printf("result = %lf\n", result);

  free(inputExpression);
  return 0;
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

void initializeTheString(char *currentString)
{
  int stringLenght = strlen(currentString);
  for (int i = 0; i < stringLenght; i++)
  {
    currentString[i] = '\0';
  }
}

int characterToInt(char characer)
{
  return (int)characer - '0';
}

float counting(char *expression)
{
  struct Stack* stackOfNumbers = createStack();

  int sizeOfExpression = strlen(expression) * 2;
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
