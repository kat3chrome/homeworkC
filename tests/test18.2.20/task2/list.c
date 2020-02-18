#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct List List;
typedef struct ListElement ListElement;

struct ListElement
{
  int value;
  ListElement* nextElement;
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

ListElement* createListElement(int value)
{
  ListElement* listElement = malloc(sizeof(ListElement));
  listElement->value = value;
  listElement->nextElement = NULL;
}

void addElementByIndex(List* list, int value, int inputIndex)
{
  if ((inputIndex < 0) || (list->first == NULL && inputIndex != 0))
  {
    return;
  }
  else if (list->first == NULL)
  {
    list->first = createListElement(value);
    return;
  }

  ListElement* temporaryListElement = list->first;
  for (int i = 0; i < inputIndex - 1; i++)
  {
    if (temporaryListElement->nextElement == NULL && inputIndex - 1 != i)
    {
      return;
    }
    temporaryListElement = temporaryListElement->nextElement;
  }

  ListElement* currentListElement = createListElement(value);
  ListElement* nextListElementFromTemporaryListElement = temporaryListElement->nextElement;
  temporaryListElement->nextElement = currentListElement;
  currentListElement->nextElement = nextListElementFromTemporaryListElement;
}

void removeElementByIndex(List* list, int inputIndex)
{
  if ((inputIndex < 0) || (list->first == NULL))
  {
    return;
  }
  else if (inputIndex == 0)
  {
    if (list->first->nextElement == NULL)
    {
      list->first = NULL;
      return;
    }
    else
    {
      ListElement* firstElement = list->first;
      list->first = firstElement->nextElement;
      free(firstElement);
      return;
    }
  }

  ListElement* temporaryListElement = list->first;
  for (int i = 0; i < inputIndex - 1; i++)
  {
    if (temporaryListElement->nextElement == NULL)
    {
      return;
    }
    temporaryListElement = temporaryListElement->nextElement;
  }
  ListElement* removedListElement = temporaryListElement->nextElement;
  temporaryListElement->nextElement = temporaryListElement->nextElement->nextElement;
  free(removedListElement);
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
