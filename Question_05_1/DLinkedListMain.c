#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

void WhoIsOnDuty(List * plist, char * name, int day);

int main(void)
{
	// List의 생성 및 초기화 /////////////////////////////
	List list;
	ListInit(&list);
	int i;
	Data data;

	data = (Employee*)malloc(sizeof(Employee));
	strcpy(data->name,"상영");
	data->num = 1;
	LInsert(&list, data);

	data = (Employee*)malloc(sizeof(Employee));
	strcpy(data->name,"민수");
	data->num = 2;
	LInsert(&list, data);

	data = (Employee*)malloc(sizeof(Employee));
	strcpy(data->name,"현규");
	data->num = 3;
	LInsert(&list, data);

	data = (Employee*)malloc(sizeof(Employee));
	strcpy(data->name,"상호");
	data->num = 4;
	LInsert(&list, data);	

	//민수가 당직을 하고 7일 뒤 당직
	WhoIsOnDuty(&list, "민수", 10);

	//상호가 당직을 하고 3일 뒤 당직
	WhoIsOnDuty(&list, "상호", 3);

	printf("\n\n");

	return 0;
}

void WhoIsOnDuty(List * plist, char * name, int day)
{	
	Employee * pemp = (Employee*)malloc(sizeof(Employee));
	LFirst(plist, &pemp);
	while(1)
	{
		if(strcmp(pemp->name , name) == 0)
			break;
		else
			LNext(plist, &pemp);
	}

	Employee * pemp1 = pemp;

	for(int i=0; i<day; i++)
	{
		LNext(plist, &pemp);
		printf("%s ",pemp -> name);
	}

	printf("\n");
	printf("%s가 당직을 선 후로 %d일 뒤 당직: %s \n", pemp1->name, day, pemp->name);
}