#include "SimpleHeap.h"

void HeapInit(Heap * ph)
{
    ph ->numOfData;
}

int HIsEmpty(Heap * ph)
{
    if(ph->numOfData==0)
        return TRUE;
    else
        return FALSE;
}

int GetParentIDX(int idx)
{
    return idx/2;
}

int GetLChildIDX(int idx)
{
    return idx*2;
}

int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx)+1;
}

int GetHiPriChildIDX(Heap * ph, int idx)
{
    if(GetLChildIDX(idx)>ph->numOfData)
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else
    {

        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX;
    }
}

void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph->numOfData+1;
    HeapElem nelem = {pr, data};

    while(idx != 1)
    {
        if(ph->heapArr[GetParentIDX(idx)].pr>pr)
        {
            ph->heapArr[idx]=ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
        
    }
}

HData HDelete(Heap * ph)
{
    HData retData = ph->heapArr[1].data;
    HeapElem lastElem = ph->heapArr[ph->numOfData];

    int parentIdx = 1;  //��Ʈ ��尡 ��ġ�ؾ� �� �ε��� �� ����
    int childIdx;

    //��Ʈ ����� �켱������ ���� �ڽ� ��带 �������� �ݺ��� ����
    while(childIdx==GetHiPriChildIDX(ph, parentIdx))
    {
        if(lastElem.pr<=(ph->heapArr[childIdx]).pr) //�ڽĳ�庸�� �켱������ ������ stop!
            break;
        ph->heapArr[parentIdx]=ph->heapArr[childIdx];
        parentIdx=childIdx;
    }

    ph->heapArr[parentIdx]=lastElem;
    ph->numOfData -= 1;
    return retData;
}