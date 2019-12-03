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

  return list;
}

ListElement* createListElement(int value)
{
  ListElement* listElement = malloc(sizeof(ListElement));
  listElement->value = value;
  listElement->nextElement = NULL;
}

void addValue(int value, List* list)
{
  ListElement* listElement = createListElement(value);
  if (list->first == NULL)
  {
    list->first = listElement;
  }
  else
  {
    ListElement* currentListElement = list->first;
    while (currentListElement->nextElement != NULL)
    {
      currentListElement = currentListElement->nextElement;
    }
    currentListElement->nextElement = listElement;
  }
}

void insertionSort(List* list)
{
  int sizeOfList = 0;

  ListElement* currentListElement = list->first;
  while (currentListElement != NULL)
  {
    sizeOfList++;
    currentListElement = currentListElement->nextElement;
  }

  for (int i = 0; i < sizeOfList - 1; i++)
  {
    for (int j = i + 1; j < sizeOfList; j++)
    {
      ListElement* currentFirstListElement = list->first;
      ListElement* currentSecondListElement = list->first;

      for (int a = 0; a < i; a++)
      {
        currentFirstListElement = currentFirstListElement->nextElement;
      }
      for (int a = 0; a < j; a++)
      {
        currentSecondListElement = currentSecondListElement->nextElement;
      }

      if (currentFirstListElement->value > currentSecondListElement->value)
      {
        int temporary = currentFirstListElement->value;
        currentFirstListElement->value > currentSecondListElement->value;
        currentSecondListElement->value = temporary;
      }
    }
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
}
