#include <stdio.h>
#include "CLinkedList.h"

int main(void)
{
	// List�� ���� �� �ʱ�ȭ /////////////////////////////
	List list;
	int data, i, nodeNum;
	ListInit(&list);

	// 5���� ������ ���� /////////////////////////////
	LInsert(&list, 3);  
	LInsert(&list, 4);  
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);

	// ����Ʈ�� ����� �����͸� ���� 3ȸ ��� /////////////////////////
	if(LFirst(&list, &data))   
	{
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)*3-1; i++)	//���� ���� ����Ʈ�� ������ ����
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n");

	// 2����� ��� ã�Ƽ� ���� //////////////////////////
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

	// ��ü ������ 1ȸ ��� ////////////////////////
	if(LFirst(&list, &data))   
	{
		printf("%d ", data);
		
		for(i=0; i<LCount(&list)-1; i++)	//���� ���� ����Ʈ�� ������ ����
		{
			if(LNext(&list, &data))
				printf("%d ", data);
		}
	}
	printf("\n\n");

	return 0;
}