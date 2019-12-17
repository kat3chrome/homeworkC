#ifndef MAP_H
#define MAP_H

struct Map;
typedef struct Map Map;
struct World;
typedef struct World World;

Map* setMap(int* arrayOfRoads, int numberOfCities, int numberOfRoads);
void printMap(Map* map);

World* setWorld(Map* map);
void printWorld(World* world);

void setCapitals(World* world, int* capitals, int numberOfCapitals);

void divideWorldByCountry(World* world);
#endif
