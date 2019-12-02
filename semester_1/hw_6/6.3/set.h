#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct Set Set;
struct Set;

Set* createSet();
void addElement(int value, struct Set* set);


void print(struct Set* set);
#endif
