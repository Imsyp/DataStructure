#ifndef __AL_GRAPG_DFS__
#define __AL_GRAPG_DFS__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    List * adjList;
    int * visitInfo;    //탐색이 진행된 정점의 정보
} ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GrapgDestory(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph * pg);

//정점의 정보 출력: DFS 기반
void DFShowGraphVertex(ALGraph * pg, int startV);

#endif