#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	// List의 생성 및 초기화 /////////////////////////////
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	// 5개의 데이터 저장 /////////////////////////////
	LInsert(&list, 3);  
	LInsert(&list, 4);  
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// 리스트에 저장된 데이터를 연속 3회 출력 /////////////////////////
	if(LFirst(&list, &data))   
	{
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)*3-1; i++)	//원형 연결 리스트라서 가능한 구조
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	// 2배수를 모두 찾아서 삭제 //////////////////////////
	nodeNum = LCount(&list);
	
	if(nodeNum != 0)
	{
		LFirst(&list, &data);
		if(data%2 == 0)
			LRemove(&list);

		for(i=0; i<nodeNum; i++)
		{
			LNext(&list, &data);
			if(data%2 == 0)
				LRemove(&list);
		}
	}

	// 전체 데이터 1회 출력 ////////////////////////
	if(LFirst(&list, &data))   
	{
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)-1; i++)	//원형 연결 리스트라서 가능한 구조
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n\n");

	return 0;
}