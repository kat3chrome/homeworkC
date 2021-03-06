#include <stdlib.h>
#include "stack.h"

struct Stack
{
  int size;
  struct StackElement* first;
};

struct StackElement
{
  float value;
  struct StackElement* next;
};

typedef struct Stack Stack;
typedef struct StackElement StackElement;

Stack* createStack()
{
  Stack* stack = malloc(sizeof(struct Stack));
  stack->first = NULL;
  return stack;
}

bool isEmpty(Stack* stack)
{
  return stack->first == NULL;
}

void push(float value, Stack* stack)
{
  stack->size++;
  StackElement* pushed = malloc(sizeof(struct StackElement));
  pushed->value = value;
  pushed->next = stack->first;
  stack->first = pushed;
}

float pop(Stack* stack)
{
  if (isEmpty(stack))
  {
    return 0;
  }

  stack->size--;
  StackElement* popped = stack->first;
  stack->first = popped->next;
  float value = popped->value;
  free(popped);

  return value;
}

float peek(struct Stack* stack)
{
  return stack->first->value;
}

int stackSize(Stack* stack)
{
  return stack->size;
}

void removeStack(StackElement* stackElement)
{
  StackElement* currentStackElement = stackElement;
  while (currentStackElement->next != NULL)
  {
    StackElement* nextStackElement = currentStackElement->next;
    free(currentStackElement);
    currentStackElement = nextStackElement;
  }
  free(currentStackElement);
}

void deleteStack(Stack* stack)
{
  StackElement* currentStackElement = stack->first;
  while (currentStackElement->next != NULL)
  {
    StackElement* nextStackElement = currentStackElement->next;
    free(currentStackElement);
    currentStackElement = nextStackElement;
  }
  free(currentStackElement);
  free(stack);
}
