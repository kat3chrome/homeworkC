#ifndef LIST_H
#define LIST_H

struct List;
typedef struct List List;

List* createList();
void printList(List* list);
void addElementByIndex(List* list, int value, int index);
void removeElementByIndex(List* list, int index);
void removeList(List* list);

#endif
