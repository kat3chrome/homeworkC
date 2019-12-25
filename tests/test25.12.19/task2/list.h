#ifndef LIST_H
#define LIST_H

struct List;
typedef struct List List;

List* createList();
List* makeList(int size, int low, int top);
void printList(List* list);
void reverseList(List* list);
void removeList(List* list);

#endif
