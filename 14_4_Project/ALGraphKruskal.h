#ifndef __AL_GRAPG_DFS__
#define __AL_GRAPG_DFS__

#include "DLinkedList.h"
#include "PriorityQueue.h"
#include "ALEdge.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    List * adjList;
    int * visitInfo;  
    PQueue pqueue;  //간선의 가중치 정보 저장
} ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GraphDestory(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV, int weight);

void ShowGraphEdgeInfo(ALGraph * pg);

void DFShowGraphVertex(ALGraph * pg, int startV);

//최소 비용 신장 트리의 구성
void ConKruskalMST(ALGraph * pg);

void ShowGraphEdgeWeightInfo(ALGraph * pg);

#endif