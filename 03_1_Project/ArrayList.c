#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	(plist -> numOfData) = 0;		//리스트에 저장된 데이터의 수는 0
	(plist -> curPosition) = -1;	//현재 아무 위치도 가리키지 않음
}

void LInsert(List * plist, LData data)
{
	if(plist -> numOfData>=LIST_LEN)
	{
		puts("데이터를 저장할 공간이 없습니다.");
		return;
	}
	plist -> arr[plist -> numOfData] = data;		//데이터 저장
	plist -> numOfData++;							//저장된 데이터의 수 증가
}

int LFirst(List * plist, LData * pdata)
{
	if((plist -> curPosition) == 0)			//저장된 데이터가 하나도 없다면
		return FALSE;

	plist -> curPosition = 0;				//참조 위치 초기화, 첫 번째 데이터의 참조를 의미
	*pdata = plist -> arr[0];				//pdata가 가리키는 공간에 데이터 저장
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

	plist -> curPosition--;	//가장 최근에 참조된 데이터의 인덱스 정보를 담기 위해
	plist -> numOfData--;

	return rdata;
}

int LCount(List * plist)
{
	return plist -> numOfData;
}