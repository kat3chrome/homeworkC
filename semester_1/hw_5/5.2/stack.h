#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

struct Stack;
typedef struct Stack Stack;

struct Stack* createStack();
int stackSize(struct Stack* stack);
void push(float value, struct Stack* stack);
float pop(struct Stack* stack);
void removeStack(Stack* stack);

#endif
