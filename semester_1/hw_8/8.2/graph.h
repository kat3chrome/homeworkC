#ifndef GRAPH_H
#define GRAPH_H

struct Graph;
typedef struct Graph Graph;

Graph* createGraph(int numberOfVertex, int numberOfEdges);
void prtintGraphAdjacencyMatrix(Graph* graph);
void scanWeightsOfEdges(Graph* graph);
void scanMarkOfVertix(Graph* graph);
void printMarkStatusOfVertix(Graph* graph);

#endif
