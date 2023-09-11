#include "ListBaseQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    if(QIsEmpty(pq)==TRUE)
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq)==TRUE)
    {
        printf("Queue Memory Error!");
        exit(-1);
    }

    Node * rpos = pq->front;
    Data rdata = rpos->data;

    pq->front = pq->front->next;
    free(rpos);

    return rdata;
}
