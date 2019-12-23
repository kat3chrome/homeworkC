#include "graph.h"
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

typedef struct Graph Graph;
typedef struct Vertix Vertix;

struct Vertix
{
  int number;
  int numberOfClass;
};

struct Graph
{
  int numberOfVertex;
  int numberOfClasses;
  int numberOfUnclassedVertix;
  Vertix* vertix;
  int** adjacencyMatrix;
};

Graph* createGraph(int numberOfVertex)
{
  Graph* graph = calloc(1, sizeof(Graph));
  graph->numberOfVertex = numberOfVertex;
  graph->numberOfClasses = 0;
  graph->numberOfUnclassedVertix = numberOfVertex;

  graph->vertix = calloc(numberOfVertex, sizeof(Vertix));
  for (int i = 0; i < numberOfVertex; i++)
  {
    graph->vertix[i].number = i;
    graph->vertix[i].numberOfClass = -1;
  }

  graph->adjacencyMatrix = (int**)malloc(sizeof(int*) * (numberOfVertex));
  for (int i = 0; i < numberOfVertex; i++)
  {
    graph->adjacencyMatrix[i] = (int*)malloc(sizeof(int) * (numberOfVertex));
    for (int j = 0; j < numberOfVertex; j++)
    {
      graph->adjacencyMatrix[i][j] = -1;
    }
  }

  return graph;
}

void setGraphAdjacencyMatrix(Graph* graph, int** edgesOfTheGraph, int numberOfEdges)
{
  for (int i = 0; i < numberOfEdges; i++)
  {
    graph->adjacencyMatrix[edgesOfTheGraph[i][0]][edgesOfTheGraph[i][1]] = edgesOfTheGraph[i][2];
    graph->adjacencyMatrix[edgesOfTheGraph[i][1]][edgesOfTheGraph[i][0]] = edgesOfTheGraph[i][2];
  }
}

void printGraphAdjacencyMatrix(Graph* graph)
{
  printf("   ");
  for (int i = 0; i < graph->numberOfVertex; i++)
  {
    printf("%2d ", i);
  }
  printf("\n");
  for (int i = 0; i < graph->numberOfVertex; i++)
  {
    printf("%2d|",i);
    for (int j = 0; j < graph->numberOfVertex; j++)
    {
      printf("%2d ", graph->adjacencyMatrix[i][j]);
    }
    printf("\n");
  }
}

void setClassesToVertix(Graph* graph, int* classesOfVertix, int numberOfClasses)
{
  graph->numberOfClasses = numberOfClasses;
  for (int i = 0; i < numberOfClasses; i++)
  {
    graph->vertix[classesOfVertix[i]].numberOfClass = i;
  }
  graph->numberOfUnclassedVertix = graph->numberOfVertex - numberOfClasses;
}

void printVertixByClasses(Graph* graph)
{
  int** classes = (int**)malloc(sizeof(int*) * graph->numberOfClasses);
  for (int i = 0; i < graph->numberOfClasses; i++)
  {
    classes[i] = malloc(graph->numberOfVertex * sizeof(int));
    for (int j = 0; j < graph->numberOfVertex; j++)
    {
      classes[i][j] = -1;
    }
  }

  for (int i = 0; i < graph->numberOfVertex; i++)
  {
    int index = 0;
    if (graph->vertix[i].numberOfClass == -1)
    {
      continue;
    }
    while (true)
    {
      if (classes[graph->vertix[i].numberOfClass][index] == -1)
      {
        break;
      }
      index++;
    }
    classes[graph->vertix[i].numberOfClass][index] = graph->vertix[i].number;
  }

  for (int i = 0; i < graph->numberOfClasses; i++)
  {
    printf("%2d: ", i);
    for (int j = 0; j < graph->numberOfVertex; j++)
    {
      if(classes[i][j] == -1)
      {
        break;
      }

      printf("%2d ", classes[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < graph->numberOfClasses; i++)
  {
    free(classes[i]);
  }
  free(classes);
}

void devideVertixByClasses(Graph* graph)
{
  int numberOfNearestVertix = -1;
  int distanseToNearestVertix = INT_MAX;
  for (int numberOfCurrentClass = 0; numberOfCurrentClass < graph->numberOfClasses; numberOfCurrentClass++)
  {
    for (int numberOfCurrentVertix = 0; numberOfCurrentVertix < graph->numberOfVertex; numberOfCurrentVertix++)
    {
      if (graph->vertix[numberOfCurrentVertix].numberOfClass == numberOfCurrentClass)
      {
        for (int numberOfAdjacentVertix = 0; numberOfAdjacentVertix < graph->numberOfVertex; numberOfAdjacentVertix++)
        {

        }
      }
    }
  }

  if (graph->numberOfUnclassedVertix > 0)
  {
    devideVertixByClasses(graph);
  }
}

void removeGraph(Graph* graph)
{
  free(graph->vertix);
  for (int i = 0; i < graph->numberOfVertex; i++)
  {
    free(graph->adjacencyMatrix[i]);
  }
  free(graph->adjacencyMatrix);
  free(graph);
}
