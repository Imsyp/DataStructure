#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"


void ListInit(List * plist)
{
    plist -> head = NULL;
    plist -> numOfData = 0;
}

void LInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;

    if(plist -> head == NULL)
    {
        newNode -> prev = NULL;
        newNode -> next = NULL;
        plist -> head = newNode;
    }
    else
    {
        newNode -> next = plist -> head;
        plist -> head -> prev = newNode;
        plist -> head = newNode;
        newNode -> prev = NULL;
    }
    (plist -> numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if(plist -> head == NULL)   
        return FALSE;
    
    plist -> cur = plist -> head;
    *pdata = plist -> cur -> data;
    return TRUE;
}

int LNext(List * plist, Data * pdata)
{
    if(plist -> cur -> next == NULL)  
        return FALSE;
    else
    {
        plist->cur = plist->cur->next;
        *pdata = plist->cur->data;
        return TRUE;
    }
}

int LPrevious(List * plist, Data * pdata)
{
    if(plist -> cur -> prev == NULL)  
        return FALSE;
    else
    {
        plist->cur = plist->cur->prev;
        *pdata = plist->cur->data;
        return TRUE;
    }
}

int LCount(List * plist)
{
    return plist -> numOfData;
}