
#include "ALGraph.h"

void GraphInit(ALGraph * pg, int nv)
{
    int i;

    pg->adjList = (List*)malloc(sizeof(List)*nv);

    pg->numV = nv;
    pg->numE = 0;
}

void GraphDestroy(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph * pg);