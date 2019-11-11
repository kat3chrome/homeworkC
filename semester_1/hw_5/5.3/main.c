#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void readExpression(char *inputExpression);
void initializeTheString(char *currentString);
void infixToPostfix(char *infixExpression, char *prefixExpression);
float counting(char *expression);

int main()
{
  int sizeOfExpression = 128;
  char inputExpression[sizeOfExpression];
  initializeTheString(inputExpression);

  printf("Enter an expression in infix form : ");
  readExpression(inputExpression);

  int sizeOfInfixexpression = strlen(inputExpression);
  char prefixExpression[sizeOfInfixexpression];
  initializeTheString(prefixExpression);

  infixToPostfix(inputExpression, prefixExpression);

  float result = counting(prefixExpression);
  printf("result = %lf\n", result);
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
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 3;
    case '*':
      return 4;
    case '/':
      return 4;
    default:
      return 5;
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
    return 2;//separator
  }

  return 3;//not process
}

void actionsWithToken(char token, char *inputExpression)
{
  if (typeOfToken(token) != 3)
  {
    inputExpression[strlen(inputExpression)] = token;
  }
}

void readExpression(char *inputExpression)
{
  char token;
  while ((token = getchar())!='\n')
  {
    actionsWithToken(token, inputExpression);
  }
}

float evaluationSimplestExpression(char operator, float operand1, float operand2)
{
  switch (operator)
  {
    case '+':
      return operand1 + operand2;
    case '-':
      return operand1 - operand2;
    case '*':
      return operand1 * operand2;
    case '/':
      return operand1 / operand2;
  }
}

void infixToPostfix(char *infixExpression, char *prefixExpression)
{
    struct Stack* stack = createStack();

    int sizeOfExpression = strlen(infixExpression);
    for (int i = 0; i < sizeOfExpression; i++)
    {
      char currentToken = infixExpression[i];
      if (typeOfToken(currentToken) == 0)
      {
        prefixExpression[strlen(prefixExpression)] = currentToken;
      }
      else if (typeOfToken(currentToken) == 1)
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
      else if (typeOfToken(currentToken) == 2)
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
    if (typeOfToken(currentToken) == 0)
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
  return result;
}
