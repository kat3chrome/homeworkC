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
  return (findSetElement(value, set) != NULL);
}

void setChild(SetElement* child, SetElement* parent, Set* set)
{
  if (parent == NULL)
  {
    set->root = child;
  }
  else if (child->value > parent->value)
  {
    parent->rightChild = child;
  }
  else if (child->value < parent->value)
  {
    parent->leftChild = child;
  }

  child->parent = parent;
}

SetElement* getMaximumElement(SetElement* setElement)
{
  if (setElement->rightChild == NULL)
  {
    return setElement;
  }

  return getMaximumElement(setElement->rightChild);
}

void deleteCurrentElement(SetElement* setElement, Set* set)
{
  if (setElement->rightChild == NULL && setElement->leftChild == NULL)
  {
    if (setElement->parent == NULL)
    {
      set->root = NULL;
    }
    else if (setElement->parent->leftChild == setElement)
    {
      setElement->parent->leftChild = NULL;
    }
    else if (setElement->parent->rightChild == setElement)
    {
      setElement->parent->rightChild = NULL;
    }
    free(setElement);
  }
  else if (setElement->leftChild != NULL && setElement->rightChild == NULL)
  {
    setChild(setElement->leftChild, setElement->parent, set);
    free(setElement);
  }
  else if (setElement->leftChild == NULL && setElement->rightChild != NULL)
  {
    setChild(setElement->rightChild, setElement->parent, set);
    free(setElement);
  }
  else
  {
    SetElement* maximumElementOfTheCurrentElement = getMaximumElement(setElement->leftChild);
    setElement->value = maximumElementOfTheCurrentElement->value;
    deleteCurrentElement(maximumElementOfTheCurrentElement, set);
  }
}

void removeElement(int value, Set* set)
{
  if (set->root == NULL)
  {
    return;
  }

  SetElement* deletedElement = findSetElement(value, set);
  if (deletedElement != NULL)
  {
    deleteCurrentElement(deletedElement, set);
  }
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

void deletePartOfSet(SetElement* setElement)
{
  if (setElement != NULL)
  {
    deletePartOfSet(setElement->rightChild);
    deletePartOfSet(setElement->leftChild);
    free(setElement);
  }
}

void removeSet(Set* set)
{
  if (set->root == NULL)
  {
    free(set);
    return;
  }

  deletePartOfSet(set->root);
  free(set);
}
