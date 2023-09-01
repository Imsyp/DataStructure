#ifndef __USEFUL_HEAP_H__
#define __USEFUL_HEAP_H__

#define TRUE        1
#define FALSE       0

#define HEAP_LEN    100

typedef char HData;  
typedef int PriorityComp(HData d1, HData d2);   //책에는 typedef int (*PriorityComp)(HData d1, HData d2);로 돼있는데, 그렇게 하면 아래 선언할 때 이중포인터 선언이 돼버림 

typedef struct _heap
{
    PriorityComp * comp;  
    int numOfData;
    HData heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph, PriorityComp pc);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data);
HData HDelete(Heap * ph);

#endif