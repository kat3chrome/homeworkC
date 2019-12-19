#include "graph.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Graph Graph;
typedef struct Vertix Vertix;
typedef struct Class Class;

struct Vertix
{
  int number;
  int numberOfClass;
  bool isMarked;
};

struct Graph
{
  int numberOfVertex;
  int numberOfEdges;
  int numberOfClasses;
  int numberOfUnclassedVertix;
  Vertix* vertix;
  int** adjacencyMatrix;
  int* numberVertixInClass;
  Vertix** classes;
};

Graph* createGraph(int numberOfVertex, int numberOfEdges)
{
  Graph* graph = calloc(1, sizeof(Graph));
  graph->numberOfVertex = numberOfVertex;
  graph->numberOfEdges = numberOfEdges;
  graph->numberOfClasses = 0;
  graph->numberOfUnclassedVertix = numberOfVertex;
  graph->vertix = calloc(numberOfVertex, sizeof(Vertix));

  for (int i = 0; i < numberOfVertex; i++)
  {
    graph->vertix[i].number = i;
    graph->vertix[i].numberOfClass = -1;
  }

  graph->numberVertixInClass = calloc(1, sizeof(int));
  graph->classes = calloc(1, sizeof(Vertix**));
  graph->classes[0] = (Vertix*)calloc(1, sizeof(Vertix));

  graph->adjacencyMatrix = (int**)calloc(numberOfVertex, sizeof(int*));

  for (int i = 0; i < numberOfVertex; i++)
  {
    graph->adjacencyMatrix[i] = (int*)calloc(numberOfVertex, sizeof(int));
  }

  return graph;
}

void prtintGraphAdjacencyMatrix(Graph* graph)
{
  for (int i = 0; i < graph->numberOfVertex; i++)
  {
    for (int j = 0; j < graph->numberOfVertex; j++)
    {
      printf("%d", graph->adjacencyMatrix[i][j]);
    }
    printf("\n");
  }
}

void scanWeightsOfEdges(Graph* graph)
{
  for (int i = 0; i < graph->numberOfEdges; i++)
  {
    int indexA = 0;
    int indexB = 0;
    int weight = 0;
    scanf("%d %d %d", &indexA, &indexB, &weight);

    graph->adjacencyMatrix[indexA][indexB] = weight;
    graph->adjacencyMatrix[indexB][indexA] = weight;
  }
}

void scanMarkOfVertix(Graph* graph)
{
  int numberOfMarked = 0;
  scanf("%d", &numberOfMarked);
  graph->numberOfClasses = numberOfMarked;
  graph->numberOfUnclassedVertix = graph->numberOfVertex - numberOfMarked;

  graph->numberVertixInClass = realloc(graph->numberVertixInClass, numberOfMarked * sizeof(int));
  graph->classes = (Vertix**)realloc(graph->classes, numberOfMarked * sizeof(Vertix*));
  for (int i = 0; i < numberOfMarked; i++)
  {
    graph->classes[i] = (Vertix*)calloc(1, sizeof(Vertix));
  }

  for (int i = 0; i < numberOfMarked; i++)
  {
    int numberOfVertex = 0;
    scanf("%d", &numberOfVertex);

    graph->vertix[numberOfVertex].numberOfClass = i;
    graph->vertix[numberOfVertex].isMarked = true;

    graph->numberVertixInClass[i] = 1;
    graph->classes[i][0] = graph->vertix[numberOfVertex];
  }
}

void printMarkStatusOfVertix(Graph* graph)
{
  for (int i = 0; i < graph->numberOfVertex; i++)
  {
    printf("Vertix number %d has status %d and belongs to %d class\n", i, graph->vertix[i].isMarked, graph->vertix[i].numberOfClass);
  }
}

void printClassesAndTheirVertix(Graph* graph)
{
  for (int i = 0; i < graph->numberOfClasses; i++)
  {
    printf("Class number %d: ", i);
    for (int j = 0; j < graph->numberVertixInClass[i]; j++)
    {
      printf("%d ", graph->classes[i][j].number);
    }
    printf("\n");
  }
}

void addVertexToCurrentClass(Graph* graph, int index);
{
  
}

void divideGraphByClasses(Graph* graph)
{
  int index = 0;

  while (true)
  {
    index %= graph->numberOfClasses;

    addVertexToCurrentClass(graph, index);

    if (graph->numberOfUnclassedVertix == 0)
    {
      return;
    }
  }
}
