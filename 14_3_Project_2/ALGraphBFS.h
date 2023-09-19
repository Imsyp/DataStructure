#ifndef __AL_GRAPG_BFS__
#define __AL_GRAPG_BFS__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    List * adjList;
    int * visitInfo;    
} ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GraphDestory(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph * pg);

//정점의 정보 출력: BFS 기반
void BFShowGraphVertex(ALGraph * pg, int startV);

#endif