#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

bool isOperator(char token)
{
  return token == '+' || token == '-' || token == '*' || token == '/';
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

void fatalError(Stack* stack, char* errorMessage)
{
  while (stackSize(stack) != 0)
  {
    pop(stack);
  }
  free(stack);
  

	perror(errorMessage);
	exit(-1);
}


int main()
{
  Stack* stack = createStack();

  printf("Enter the expression: ");

  char token;
  while ((token = getchar()) != '\n')
  {
    if(isdigit(token))
    {
      push(token - '0', stack);
    }
    else if(isOperator(token))
    {
      push(evaluationSimplestExpression(token, pop(stack), pop(stack)), stack);
    }
    else if (token == ' ')
    {
      continue;
    }
    else
    {
      fatalError(stack, "Unknow token\n");
    }
  }
  
  if (stackSize(stack) == 1)
  {
    printf("expression = %f\n", pop(stack));
    free(stack);
  }
  else
  {
    fatalError(stack, "Incorrect expression\n");    
  }
}
