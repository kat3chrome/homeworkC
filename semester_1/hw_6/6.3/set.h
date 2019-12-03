#ifndef SET_H
#define SET_H

#include <stdbool.h>

typedef struct Set Set;

struct Set;

Set* createSet();
void addElement(int value, Set* set);
bool isInTheSet(int value, Set* set);
void removeElement(int value, Set* set);
void printSet(Set* set);

#endif
