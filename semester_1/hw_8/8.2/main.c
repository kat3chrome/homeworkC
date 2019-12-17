#include "map.h"
#include <stdio.h>

int main()
{
  int numberOfRoads = 4;
  int numberOfCities = 4;

  int array[3 * numberOfRoads];
  for (int i = 0; i < numberOfRoads; i++)
  {
    scanf("%d %d %d", &array[i * 3], &array[i * 3 + 1], &array[i * 3 + 2]);
  }

  int numberOfCapitals = 2;
  int capitals[numberOfCapitals];
  for (int i = 0; i < numberOfCapitals; i++)
  {
    scanf("%d", &capitals[i]);
  }

  Map* map = setMap(array, numberOfCities, numberOfRoads);
  World* world = setWorld(map);
  setCapitals(world, capitals, numberOfCapitals);

  // printWorld(world);

  divideWorldByCountry(world);

  printWorld(world);

  return 0;
}
