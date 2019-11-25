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

void addElement(int value, struct Set* set)
{
  if (set->root == NULL)
  {

  }
}
