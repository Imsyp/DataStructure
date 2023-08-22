#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
    pstack->head = NULL;
}   

int SIsEmpty(Stack * pstack)
{
    if(pstack->head==NULL)
        return TRUE;
    else
        return FALSE;
}     

void SPush(Stack * pstack, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = pstack->head;  
    pstack->head = newNode;  
} 

Data SPop(Stack * pstack) 
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    Node * rpos = pstack->head;
    Data rdata = rpos->data;

    pstack->head=pstack->head->next;

    free(rpos);
    return rdata; 
}     

Data SPeek(Stack * pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Memory Error!");
        exit(-1);
    }

    return pstack->head->data;
}             