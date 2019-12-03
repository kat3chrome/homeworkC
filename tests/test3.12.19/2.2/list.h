#ifndef LIST_H
#define LIST_H

struct List;
typedef struct List List;

List* createList();
void addValue(int value, List* list);
void insertionSort(List* list);
void printList(List* list);

#endif
