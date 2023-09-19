#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLinkedList.h"
#include "ALGraphKruskal.h"
#include "ArrayBaseStack.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2);

void GraphInit(ALGraph * pg, int nv)
{
    int i;

    pg->adjList = (List*)malloc(sizeof(List)*nv);
    pg->numE = 0;
    pg->numV = nv;

    for(i=0; i<nv; i++)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    pg->visitInfo = (int*)malloc(sizeof(int) * (pg->numV));

    memset(pg->visitInfo, 0, sizeof(int) * (pg->numV));

    PQueueInit(&(pg->pqueue), PQWeightComp);
}

void GraphDestory(ALGraph * pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList);
    
    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    Edge edge = {fromV, toV, weight};

    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);

    pg->numE +=1;

    PEnqueue(&(pg->pqueue), edge);
}

void RemoveWayEdge(ALGraph * pg, int fromV, int toV)    //한쪽 방향의 간선 소멸
{
    int edge;

    if(LFirst(&(pg->adjList[fromV]), &edge))
    {
        if(edge == toV)
        {
            LRemove(&(pg->adjList[fromV]));
            return;
        }

        while(LNext(&(pg->adjList[fromV]), &edge))
        {
            if(edge == toV)
            {
                LRemove(&(pg->adjList[fromV]));
                return;
            }
            
        }
    }
}

void RemoveEdge(ALGraph * pg, int fromV, int toV)   //간선의 소멸
{
    RemoveWayEdge(pg, fromV, toV);
    RemoveWayEdge(pg, toV, fromV);
    (pg->numE)--;
}

void RecoverEdge(ALGraph * pg, int fromV, int toV, int weight)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);
    (pg->numE)++;
}

int VisitVertex(ALGraph * pg, int visitV)
{
    if (pg->visitInfo[visitV] == 0) 
    {
        pg->visitInfo[visitV] = 1;  
        //printf("%c ", visitV + 65);
        return TRUE;
    }
    return FALSE;
}

int IsConnVertex(ALGraph * pg, int v1, int v2)
{
    Stack stack;
    int visitV = v1;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)   
    {
        int visitFlag = FALSE;

        //정점을 돌아다니는 도중 목표를 찾으면 TRUE 반환
        if(nextV == v2)
        {
            memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
            return TRUE;
        }

        if(VisitVertex(pg, nextV) == TRUE)
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)    //첫 시도가 이미 방문한 상태인 경우 다른 정점 방문
            {
                if (nextV == v2)
                {
                    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
                    return TRUE;
                }

                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if(visitFlag == FALSE)  //현재 정점에 연결된 모든 정점이 모두 방문한 상태인 경우
        {
            if(SIsEmpty(&stack) == TRUE)    //시작점으로 돌아온 경우
                break;
            else
                visitV = SPop(&stack);      //왔던 길 되돌아가는 과정
        }
    }

    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
    return FALSE;   //목표를 찾지 못함 -> 연결되지 않음
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
    int i;
    int vx;

    for(i=0; i<pg->numV; i++)
    {
        printf("%c와 연결된 정점: ", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx));
        {
            printf("%c ", vx + 65);

            while(LNext(&(pg->adjList[i]), &vx))
                printf("%c ", vx + 65);
        }

        printf("\n");
    }
}

void DFShowGraphVertex(ALGraph * pg, int startV)
{
    Stack stack;
    int visitV = startV;
    int nextV;

    StackInit(&stack);
    VisitVertex(pg, visitV);
    SPush(&stack, visitV);

    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)   //첫 정점에 연결된 정점 방문
    {
        int visitFlag = FALSE;

        if(VisitVertex(pg, nextV) == TRUE)
        {
            SPush(&stack, visitV);
            visitV = nextV;
            visitFlag = TRUE;
        }
        else
        {
            while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)    //첫 시도가 이미 방문한 상태인 경우 다른 정점 방문
            {
                if(VisitVertex(pg, nextV) == TRUE)
                {
                    SPush(&stack, visitV);
                    visitV = nextV;
                    visitFlag = TRUE;
                    break;
                }
            }
        }

        if(visitFlag == FALSE)  //현재 정점에 연결된 모든 정점이 모두 방문한 상태인 경우
        {
            if(SIsEmpty(&stack) == TRUE)    //시작점으로 돌아온 경우
                break;
            else
                visitV = SPop(&stack);      //왔던 길 되돌아가는 과정
        }
    }

    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void ConKruskalMST(ALGraph * pg)
{
    Edge recvEdge[20];  //복원할 간선 정보 저장
    Edge edge;
    int eidx = 0;
    int i;

    while(pg->numE+1 > pg->numV)    //MST 간선의 수 + 1 = 정점의 수
    {
        edge = PDequeue(&(pg->pqueue));     //가중치가 가장 높은 간선부터 순서대로 꺼낸다.
        RemoveEdge(pg, edge.v1, edge.v2);

        if(!IsConnVertex(pg, edge.v1, edge.v2))     //간선을 삭제하고 나서 두 정점을 연결하는 경로가 있는지 확인
        {
            RecoverEdge(pg, edge.v1, edge.v2, edge.weight); //우선순위 큐에 다시 넣지 않는 이유는, 한 번 검토한 간선은 재검토하지 않기 위해서
            recvEdge[eidx++] = edge;
        }
    }

    for(i=0; i<eidx; i++)
        PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph * pg)
{
    PQueue copyPQ = pg->pqueue;
    Edge edge;

    while(!PQIsEmpty(&copyPQ))
    {
        edge = PDequeue(&copyPQ);
        printf("(%c-%c), w:%d \n", edge.v1+65, edge.v2+65, edge.weight);
    }
}

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

int PQWeightComp(Edge d1, Edge d2)
{
    return d1.weight - d2.weight;
}
