#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
  int numberOfSoldiers = 0;
  printf("Enter the number of Soldiers : ");
  scanf("%d", &numberOfSoldiers);

  struct Troop* troop = createTroop();
  for (int i = 0; i < numberOfSoldiers; i++)
  {
    addSoldier(i + 1, troop);
  }

  int stepOfDeath = 0;
  printf("Enter the step of death : ");
  scanf("%d", &stepOfDeath);

  for (int i = 0; i < numberOfSoldiers - 1; i++)
  {
    for (int i = 0; i < stepOfDeath; i++)
    {
      nextSoldier(troop);
    }
    killCurrentSoldier(troop);
  }

  printf("Number of the last living soldier : %d \n", getNumberOfLastSoldier(troop));

  free(troop);
  return 0;
}
