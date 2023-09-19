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
    PQueue pqueue;  //������ ����ġ ���� ����
} ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GraphDestory(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV, int weight);

void ShowGraphEdgeInfo(ALGraph * pg);

void DFShowGraphVertex(ALGraph * pg, int startV);

//�ּ� ��� ���� Ʈ���� ����
void ConKruskalMST(ALGraph * pg);

void ShowGraphEdgeWeightInfo(ALGraph * pg);

#endif