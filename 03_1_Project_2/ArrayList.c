#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist -> numOfData) = 0;		//����Ʈ�� ����� �������� ���� 0
	(plist -> curPosition) = -1;	//���� �ƹ� ��ġ�� ����Ű�� ����
}

void LInsert(List * plist, LData data)
{
	if(plist -> numOfData>=LIST_LEN)
	{
		puts("�����͸� ������ ������ �����ϴ�.");
		return;
	}
	plist -> arr[plist -> numOfData] = data;		//������ ����
	plist -> numOfData++;							//����� �������� �� ����
}

int LFirst(List * plist, LData * pdata)
{
	if((plist -> curPosition) == 0)			//����� �����Ͱ� �ϳ��� ���ٸ�
		return FALSE;

	plist -> curPosition = 0;				//���� ��ġ �ʱ�ȭ, ù ��° �������� ������ �ǹ�
	*pdata = plist -> arr[0];				//pdata�� ����Ű�� ������ ������ ����
	return TRUE; 
}

int LNext(List * plist, LData * pdata)
{
	if((plist -> curPosition) >= (plist -> numOfData)-1)
		return FALSE;

	plist -> curPosition++;
	*pdata = plist -> arr[plist -> curPosition];
	return TRUE; 
}

LData LRemove(List * plist)
{
	int rpos = plist -> curPosition;
	int num = plist -> numOfData;
	int i;
	LData rdata = plist -> arr[rpos];

	for(i=rpos; i<num-1; i++)
		plist -> arr[i] = plist ->arr[i+1];

	plist -> curPosition--;	//���� �ֱٿ� ������ �������� �ε��� ������ ��� ����
	plist -> numOfData--;

	return rdata;
}

int LCount(List * plist)
{
	return plist -> numOfData;
}