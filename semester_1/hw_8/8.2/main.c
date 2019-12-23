#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int numberOfCities = 4;
  int numberOfRoads = 4;
  int numberOfCapitals = 2;
  Graph* graph = createGraph(numberOfCities);

 //
  int** roads = (int**)malloc(sizeof(int*) * (numberOfRoads));
  for (int i = 0; i < numberOfRoads; i++)
  {
    roads[i] = (int*)malloc(sizeof(int) * (3));
    for (int j = 0; j < 3; j++)
    {
      roads[i][j] = 0;
    }
  }
  roads[0][0] = 0;
  roads[0][1] = 1;
  roads[0][2] = 1;
  roads[1][0] = 0;
  roads[1][1] = 2;
  roads[1][2] = 2;
  roads[2][0] = 1;
  roads[2][1] = 2;
  roads[2][2] = 3;
  roads[3][0] = 2;
  roads[3][1] = 3;
  roads[3][2] = 4;
  //
  setGraphAdjacencyMatrix(graph, roads, numberOfRoads);
  printGraphAdjacencyMatrix(graph);

  //
  int* capitals = (int*)malloc(sizeof(int) * (numberOfCapitals));

  capitals[0] = 0;
  capitals[1] = 2;
  //
  setClassesToVertix(graph, capitals, numberOfCapitals);
  printVertixByClasses(graph);
  //
  for (int i = 0; i < numberOfRoads; i++)
  {
    free(roads[i]);
  }
  free(roads);

  free(capitals);
  //

  removeGraph(graph);
  return 0;
}
