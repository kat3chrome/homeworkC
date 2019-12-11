#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "set.h"

typedef struct Set Set;
typedef struct SetElement SetElement;

struct SetElement
{
  int value;
  SetElement* parent;
  SetElement* leftChild;
  SetElement* rightChild;
};

struct Set
{
  SetElement* root;
};

Set* createSet()
{
  Set* set = malloc(sizeof(Set));
  set->root = NULL;

  return set;
}

SetElement* createSetElement(int value)
{
  SetElement* setElement = malloc(sizeof(SetElement));
  setElement->value = value;
  setElement->parent = NULL;
  setElement->leftChild = NULL;
  setElement->rightChild = NULL;

  return setElement;
}

void addElement(int value, Set* set)
{
  if (set->root == NULL)
  {
    set->root = createSetElement(value);
  }
  else
  {
    SetElement* currentElement = set->root;
    SetElement* parent = NULL;

    while(currentElement != NULL)
    {
      if (currentElement->value < value)
      {
        parent = currentElement;
        currentElement = currentElement->rightChild;
      }
      else if (currentElement->value > value)
      {
        parent = currentElement;
        currentElement = currentElement->leftChild;
      }
      else
      {
        return;
      }
    }

    if (parent->value < value)
    {
      parent->rightChild = createSetElement(value);
      parent->rightChild->parent = parent;
    }
    else
    {
      parent->leftChild = createSetElement(value);
      parent->leftChild->parent = parent;
    }
  }
}

void printSetFromTheCurrentElement(SetElement* currentElement)
{
  if (currentElement != NULL)
  {
    printf("(");
    if (currentElement->leftChild == NULL && currentElement->rightChild == NULL)
    {
      printf(" %d null null ", currentElement->value);
    }
    else if (currentElement->leftChild == NULL)
    {
      printf(" %d null ", currentElement->value);
      printSetFromTheCurrentElement(currentElement->rightChild);
    }
    else if (currentElement->rightChild == NULL)
    {
      printf(" %d ", currentElement->value);
      printSetFromTheCurrentElement(currentElement->leftChild);
      printf(" null ");
    }
    else
    {
      printf(" %d ", currentElement->value);
      printSetFromTheCurrentElement(currentElement->leftChild);
      printSetFromTheCurrentElement(currentElement->rightChild);
    }
    printf(")");
  }
}

void printSet(Set* set)
{
  printSetFromTheCurrentElement(set->root);
}

SetElement* findSetElement(int value, Set* set)
{
  SetElement* currentElement = set->root;

  while (true)
  {
    if (currentElement == NULL)
    {
      return currentElement;
    }
    else if (currentElement->value == value)
    {
      return currentElement;
    }
    else if (currentElement->value < value)
    {
      currentElement = currentElement->rightChild;
    }
    else
    {
      currentElement = currentElement->leftChild;
    }
  }
}

bool isInTheSet(int value, Set* set)
{
  if (findSetElement(value, set) != NULL)
  {
    return true;
  }

  return false;
}

bool isRightChild(SetElement* setElement)
{
  if (setElement->parent != NULL)
  {
    if(setElement->parent->value < setElement->value)
    {
      return true;
    }
  }

  return false;
}



void removeElement(int value, Set* set)
{
  
}

void printSetInAscendingOrder(SetElement* setElement)
{
  if (setElement != NULL)
  {
    printSetInAscendingOrder(setElement->leftChild);
    printf("%d ", setElement->value);
    printSetInAscendingOrder(setElement->rightChild);
  }
}

void printSetInDescendingOrder(SetElement* setElement)
{
  if (setElement != NULL)
  {
    printSetInDescendingOrder(setElement->rightChild);
    printf("%d ", setElement->value);
    printSetInDescendingOrder(setElement->leftChild);
  }
}

void printSetInSpecificOrder(bool isAscendingOrder, Set* set)
{
  if (isAscendingOrder)
  {
    printSetInAscendingOrder(set->root);
  }
  else
  {
    printSetInDescendingOrder(set->root);
  }
}
