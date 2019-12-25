#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct List List;
typedef struct ListElement ListElement;

struct ListElement
{
  int value;
  ListElement* nextElement;
  ListElement* previousElement;
};

struct List
{
  ListElement* first;
};

List* createList()
{
  List* list = malloc(sizeof(List));
  list->first = NULL;
}

ListElement* createListElement(int low, int top)
{
  ListElement* listElement = malloc(sizeof(ListElement));
  listElement->value = rand() % (top - low + 1) + low;
  listElement->nextElement = NULL;
  listElement->previousElement = NULL;
}

List* makeList(int size, int low, int top)
{
  List* list = malloc(sizeof(List));
  list->first = NULL;

  list->first = createListElement(low, top);
  ListElement* currentListElement = list->first;
  for (int i = 0; i < size-1; i++)
  {
    currentListElement->nextElement = createListElement(low, top);
    currentListElement->nextElement->previousElement = currentListElement;
    currentListElement = currentListElement->nextElement;
  }

  return list;
}

void reverseList(List* list)
{
  ListElement* currentListElement = list->first;
  while (currentListElement != NULL)
  {
    ListElement* nextElement = currentListElement->nextElement;
    ListElement* previousElement = currentListElement->previousElement;
    currentListElement->nextElement = previousElement;
    currentListElement->previousElement = nextElement;
    if (nextElement == NULL)
    {
      list->first = currentListElement;
    }
    currentListElement = nextElement;
  }
}

void printList(List* list)
{
  ListElement* currentListElement = list->first;
  while (currentListElement != NULL)
  {
    printf("%d ", currentListElement->value);
    currentListElement = currentListElement->nextElement;
  }
  printf("\n");
}

void removeList(List* list)
{
  ListElement* currentListElement = list->first;
  while (currentListElement != NULL)
  {
    ListElement* nextElement = currentListElement->nextElement;
    free(currentListElement);
    currentListElement = nextElement;
  }
  free(list);
}
