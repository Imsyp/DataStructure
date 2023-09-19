#ifndef __AL_GRAPG_DFS__
#define __AL_GRAPG_DFS__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    List * adjList;
    int * visitInfo;    //Ž���� ����� ������ ����
} ALGraph;

void GraphInit(ALGraph * pg, int nv);

void GrapgDestory(ALGraph * pg);

void AddEdge(ALGraph * pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph * pg);

//������ ���� ���: DFS ���
void DFShowGraphVertex(ALGraph * pg, int startV);

#endif