#include <stdio.h>
#include "DLinkedList.h"

int WhoIsPreced(int d1, int d2)	//정렬의 기준이 되는 함수
{
	if(d1<d2)
		return FALSE;
	else
		return TRUE;
}

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	SetSortRule(&list, WhoIsPreced);	//정렬 기준 설정

	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &data))    
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))   
			printf("%d ", data);
	}
	printf("\n\n");

	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}