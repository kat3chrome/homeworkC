#include <stdlib.h>
#include <stdio.h>
#include "set.h"

struct Set
{
    struct SetElement* root;
};

struct SetElement
{
    int value;
    struct SetElement* parent;
    struct SetElement* leftChild;
    struct SetElement* rightChild;
};

typedef struct Set Set;
typedef struct SetElement SetElement;

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
  setElement->leftChild = NULL;

  return setElement;
}

void addElement(int value, struct Set* set)
{
  SetElement* setElement = createSetElement(value);

  while ()
  {

  }
}

void print(struct Set* set)
{
  printf("%d\n", set->root->value);
}
