#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringInitialization(char *inputString, int lengthOfInputString)
{
  for (size_t i = 0; i < lengthOfInputString; i++)
  {
    inputString[i] = '\0';
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

void addToQueue(char token, char *queue)
{
  queue[strlen(queue)] = token;
}

void addToStack(char token, char *stack, int sizeOfStack)
{
  for(int i = sizeOfStack - 1; i > 0; i--)
  {
    stack[i] = stack[i - 1];
  }

  stack[0] = token;
}

void popFromStackToCharacter(char *temporaryCharacter, char *stack, int sizeOfArray)
{
  temporaryCharacter[0] = stack[0];

  for (int i = 0; i < sizeOfArray - 1; i++)
  {
    stack[i] = stack[i + 1];
  }

  stack[sizeOfArray - 1] = '\0';
}

void processWhenCurrentTokenIsClosingBracket(char token, char *stack, char *queue ,int sizeOfArray)
{
  char temporaryCharacter[1];

  while (stack[0] != '(')
  {
    popFromStackToCharacter(temporaryCharacter, stack, sizeOfArray);
    queue[strlen(queue)] = temporaryCharacter[0];
  }

  popFromStackToCharacter(temporaryCharacter, stack, sizeOfArray);

  if (typeOfToken(stack[0]) == 1)
  {
    popFromStackToCharacter(temporaryCharacter, stack, sizeOfArray);
    queue[strlen(queue)] = temporaryCharacter[0];
  }
}

void actionsWithToken(char token, char *stack, char *queue, int sizeOfArray)
{
  int typeOfCurrentToken = typeOfToken(token);

  switch (typeOfCurrentToken)
  {
    case 0:
      addToQueue(token, queue);
      break;
    case 1:
      addToStack(token, stack, sizeOfArray);
      break;
    case 2:
      if (token == '(')
      {
        addToStack(token, stack, sizeOfArray);
      }
      else
      {
        processWhenCurrentTokenIsClosingBracket(token, stack, queue, sizeOfArray);
      }
      break;
  }
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

int main()
{
  int sizeOfArray = 32;
  char token;
  char stack[sizeOfArray];
  char queue[sizeOfArray];
  stringInitialization(stack, sizeOfArray);
  stringInitialization(queue, sizeOfArray);

  printf("Enter an expression in infix form : ");
  while ((token = getchar())!='\n')
  {
    actionsWithToken(token, stack, queue, sizeOfArray);
  }

  char temporaryCharacter[1];
  while (strlen(stack) != 0)
  {
    popFromStackToCharacter(temporaryCharacter, stack, sizeOfArray);
    queue[strlen(queue)] = temporaryCharacter[0];
  }

  printf("Expression in postfix form : ");
  printQueue(queue);
  return 0;
}
