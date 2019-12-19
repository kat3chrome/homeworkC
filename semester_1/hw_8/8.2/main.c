#include "graph.h"
#include <stdio.h>

int main()
{
  int numberOfCities = 3;
  int numberOfRoads = 3;

  Graph* graph = createGraph(numberOfCities, numberOfRoads);
  scanWeightsOfEdges(graph);
  prtintGraphAdjacencyMatrix(graph);

  int numberOfCapitals = 2;
  scanMarkOfVertix(graph);

  printMarkStatusOfVertix(graph);
  printClassesAndTheirVertix(graph);

  return 0;
}
