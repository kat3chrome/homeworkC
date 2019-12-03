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
      if (currentElement->parent == NULL)
      {
        printf(" %d ", currentElement->value);
      }
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

int minimumValueInSubtree(SetElement* setElement)
{
  while (setElement->leftChild != NULL)
  {
    setElement = setElement->leftChild;
  }

  return setElement->value;
}

SetElement* recursionRemoveElement(int value, SetElement* setElement)
{
  if (setElement == NULL)
  {
    return setElement;
  }
  else if (setElement->value < value)
  {
    setElement->rightChild = recursionRemoveElement(value, setElement->rightChild);
  }
  else if (setElement->value > value)
  {
    setElement->leftChild = recursionRemoveElement(value, setElement->leftChild);
  }
  else if (setElement != NULL && setElement != NULL)
  {
    setElement->value = minimumValueInSubtree(setElement->rightChild);
    setElement->rightChild = recursionRemoveElement(setElement->value, setElement->rightChild);
  }
  else
  {
    if (setElement->leftChild != NULL)
    {
      setElement = setElement->leftChild;
    }
    else if (setElement->rightChild != NULL)
    {
      setElement = setElement->rightChild;
    }
    else
    {
      setElement = NULL;
    }
  }

  return setElement;
}

void removeElement(int value, Set* set)
{
  recursionRemoveElement(value, set->root);
}
