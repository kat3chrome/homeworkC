#ifndef SET_H
#define SET_H

#include <stdbool.h>

struct Set;

struct Set* createSet();
void addElement(int value, struct Set* set);

#endif
