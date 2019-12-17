#include "map.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Road Road;
typedef struct Map Map;
typedef struct City City;
typedef struct World World;

struct Road
{
  int cityA;
  int cityB;
  int length;
};

struct Map
{
  int numberOfCities;
  int numberOfRoads;
  Road* roads;
};

struct City
{
  int number;
  int numberOfCountry;
  bool isCapital;
  int numberOfCities;
  int* cities;
  int* distances;
};

struct World
{
  int numberOfCities;
  int numberOfCountries;
  City* cities;
};

void printRoad(Road road)
{
  printf("%d %d %d\n", road.cityA, road.cityB, road.length);
}

void printMap(Map* map)
{
  for (int i = 0; i < map->numberOfRoads; i++)
  {
    printRoad(map->roads[i]);
  }
}

void printCity(City city)
{
  printf("\nCity number %d\n", city.number);
  printf("City's country %d\n", city.numberOfCountry);
  printf("Capital status %d\n", city.isCapital);
  printf("Number of cities %d\n", city.numberOfCities);
  for (int i = 0; i < city.numberOfCities; i++)
  {
    printf("city -> %d -> %d\n", city.distances[i], city.cities[i]);
  }
}

void printWorld(World* world)
{
  for (int i = 0; i < world->numberOfCities; i++)
  {
    printCity(world->cities[i]);
  }
}

Road* setRoad(int cityA, int cityB, int length)
{
  Road* road = malloc(sizeof(Road));

  road->cityA = cityA;
  road->cityB = cityB;
  road->length = length;

  return road;
}

Map* setMap(int* arrayOfRoads, int numberOfCities, int numberOfRoads)
{
  Map* map = malloc(sizeof(Map));
  map->numberOfCities = numberOfCities;
  map->numberOfRoads = numberOfRoads;
  map->roads = malloc(sizeof(Road) * numberOfRoads);

  for (int i = 0; i < numberOfRoads; i++)
  {
    map->roads[i] = *setRoad(arrayOfRoads[i * 3], arrayOfRoads[i * 3 + 1], arrayOfRoads[i * 3 + 2]);
  }

  return map;
}

City* createCity(int number)
{
  City* city = malloc(sizeof(City));

  city->number = number;
  city->numberOfCountry = -1;
  city->isCapital = false;
  city->numberOfCities = 0;
  city->cities = malloc(sizeof(int));
  city->distances = malloc(sizeof(int));

  return city;
}

City* setCity(int number, Map* map)
{
  City* city = createCity(number);
  for (int i = 0; i < map->numberOfRoads; i++)
  {
    if (map->roads[i].cityA == number || map->roads[i].cityB == number)
    {
      city->numberOfCities++;
      city->cities = realloc(city->cities, city->numberOfCities * sizeof(int));
      city->distances = realloc(city->distances, city->numberOfCities * sizeof(int));

      city->distances[city->numberOfCities - 1] = map->roads[i].length;
      if (map->roads[i].cityA == number)
      {
        city->cities[city->numberOfCities - 1] = map->roads[i].cityB;
      }
      else
      {
        city->cities[city->numberOfCities - 1] = map->roads[i].cityA;
      }
    }
  }

  return city;
}

World* setWorld(Map* map)
{
  World* world = malloc(sizeof(World));
  world->numberOfCities = map->numberOfCities;
  world->cities = malloc(sizeof(City) * map->numberOfCities);

  for (int i = 0; i < map->numberOfCities; i++)
  {
    world->cities[i] = *setCity(i,  map);
  }

  return world;
}

void setCapitals(World* world, int* capitals, int numberOfCapitals)
{
  world->numberOfCountries = numberOfCapitals;
  for (int i = 0; i < numberOfCapitals; i++)
  {
    world->cities[capitals[i]].isCapital = true;
    world->cities[capitals[i]].numberOfCountry = i;
  }
}

int getNumberOfNearestTown(City city)
{
  int minimumDistance = city.distances[0];
  int indexOfNearestTown = 0;

  for (int i = 0; i < city.numberOfCities; i++)
  {
    if (city.distances[i] < minimumDistance)
    {
      minimumDistance = city.distances[i];
      indexOfNearestTown = city.cities[i];
    }
  }

  return indexOfNearestTown;
}

void divideWorldByCountry(World* world)
{
  bool wasChanged = false;
  int index = 0;
  int step = 0;

  while (true)
  {

    index %= world->numberOfCities;
    if (world->cities[index].numberOfCountry == -1)
    {
      index++;
      step++;
      continue;
    }

    int numberOfNearestTown = getNumberOfNearestTown(world->cities[index]);
    world->cities[numberOfNearestTown].numberOfCountry = world->cities[index].numberOfCountry;
    index++;
    step++;

    if (step == world->numberOfCities * world->numberOfCities)
    {
      return;
    }
  }
}
