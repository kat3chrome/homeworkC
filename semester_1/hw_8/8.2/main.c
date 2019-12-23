#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE* input = fopen("input","r");
  int numberOfCities = 0;
  int numberOfRoads = 0;
  int numberOfCapitals = 0;
  fscanf(input, "%d", &numberOfCities);
  fscanf(input, "%d", &numberOfRoads);

  Graph* graph = createGraph(numberOfCities);

  int** roads = (int**)malloc(sizeof(int*) * (numberOfRoads));
  for (int i = 0; i < numberOfRoads; i++)
  {
    roads[i] = (int*)malloc(sizeof(int) * (3));
    fscanf(input,"%d %d %d", &roads[i][0], &roads[i][1], &roads[i][2]);
  }
  setGraphAdjacencyMatrix(graph, roads, numberOfRoads);

  fscanf(input, "%d", &numberOfCapitals);
  int* capitals = (int*)malloc(sizeof(int) * (numberOfCapitals));
  for (int i = 0; i < numberOfCapitals; i++)
  {
    fscanf(input, "%d", &capitals[i]);
  }
  setClassesToVertix(graph, capitals, numberOfCapitals);
  devideVertixByClasses(graph);

  printf("Number of contry: city1, city2, ...\n");
  printVertixByClasses(graph);

  for (int i = 0; i < numberOfRoads; i++)
  {
    free(roads[i]);
  }
  free(roads);
  free(capitals);
  removeGraph(graph);
  fclose(input);

  return 0;
}
