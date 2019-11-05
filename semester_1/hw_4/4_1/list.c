#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct Troop Troop;
typedef struct Soldier Soldier;

struct Troop
{
  Soldier* current;
};

struct Soldier
{
  int number;
  Soldier* right;
  Soldier* left;
};

Troop* createTroop()
{
  Troop* troop = malloc(sizeof(Troop));
  troop->current = NULL;

  return troop;
}

Soldier* summonSoldier()
{
    Soldier* soldier = malloc(sizeof(Soldier));
    soldier->number = 0;
    soldier->left = NULL;
    soldier->right = NULL;

    return soldier;
}

void addSoldier(int number, struct Troop* troop)
{
  Soldier* soldier = summonSoldier();
  soldier->number = number;

  if (troop->current == NULL)
  {
    soldier->right = soldier;
    soldier->left = soldier;
    troop->current = soldier;
  }
  else
  {
    Soldier* left = troop->current;
    Soldier* right = troop->current->right;

    soldier->right = right;
    right->left = soldier;

    soldier->left = left;
    left->right = soldier;
  }
}

void nextSoldier(struct Troop* troop)
{
  troop->current = troop->current->right;
}

void killCurrentSoldier(struct Troop* troop)
{
  troop->current->left->right = troop->current->right;
  troop->current->right->left = troop->current->left;
  free(troop->current);
  troop->current = troop->current->right;
}

int getNumberOfLastSoldier(struct Troop* troop)
{
  return troop->current->number;
}
