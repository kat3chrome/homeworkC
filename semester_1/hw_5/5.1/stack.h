#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct Stack;

struct Stack* createStack();
int stackSize(struct Stack* stack);
void push(float value, struct Stack* stack);
float pop(struct Stack* stack);
float peek(struct Stack* stack);
bool isEmpty(struct Stack* stack);
void deleteStack(struct Stack* stack);

#endif
