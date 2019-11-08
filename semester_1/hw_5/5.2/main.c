#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int typeOfToken(char token);
void processingOfCurrentToken(char token, struct Stack* stackOfNumbers, char *queueOfOperands);
void readExpression(struct Stack* stackOfNumbers, char *queueOfOperands);
float evaluationExpression(struct Stack* stackOfNumbers, char *queueOfOperands);
void initializeTheString(char *currentString);
void addToQueue(char token, char *queue);

int main()
{
  struct Stack* stackOfNumbers = createStack();
  int sizeOfQueueOfOperands = 32;
  char queueOfOperands[sizeOfQueueOfOperands];
  initializeTheString(queueOfOperands);
  float result = 0;

  readExpression(stackOfNumbers, queueOfOperands);
  result = evaluationExpression(stackOfNumbers, queueOfOperands);
  printf("%lf\n", result);
  return 0;
}

void printQueue(char *queue)
{
  int sizeOfQueue = strlen(queue);

  for (int i = 0; i < sizeOfQueue; i++)
  {
    printf("%c ", queue[i]);
  }
  printf("\n");
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

  return 2;//not process
}

float characterToFloat(char characer)
{
  return (int)characer - '0';
}

void processingOfCurrentToken(char token, struct Stack* stackOfNumbers, char *queueOfOperands)
{
  int typeOfCurrentToken = typeOfToken(token);

  switch (typeOfCurrentToken)
  {
    case 0:
      push(characterToFloat(token), stackOfNumbers);
      break;
    case 1:
      addToQueue(token, queueOfOperands);
      break;
  }
}

void readExpression(struct Stack* stackOfNumbers, char *queueOfOperands)
{
  char token;
  int index = 0;
  while ((token = getchar())!='\n')
  {
    if (typeOfToken(token) != 2)
    {
      processingOfCurrentToken(token, stackOfNumbers, queueOfOperands);
    }
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

int popEndOfQueue(char *queue)
{
  int endOfQueue = queue[0];
  int sizeOfQueue = strlen(queue);

  for (int i = 0; i < sizeOfQueue - 1; i++)
  {
    queue[i] = queue[i + 1];
  }
  queue[sizeOfQueue - 1] = '\0';

  return endOfQueue;
}


float evaluationExpression(struct Stack* stackOfNumbers, char *queueOfOperands)
{

  printQueue(queueOfOperands);

  while(strlen(queueOfOperands) != 0)
  {
    int operator = popEndOfQueue(queueOfOperands);
    int operand1 = pop(stackOfNumbers);
    int operand2 = pop(stackOfNumbers);
    printf("%d %c %d\n", operand1, operator, operand2);
    push(evaluationSimplestExpression((char)operator, operand1, operand2), stackOfNumbers);
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

void addToQueue(char token, char *queue)
{
  queue[strlen(queue)] = token;
}
