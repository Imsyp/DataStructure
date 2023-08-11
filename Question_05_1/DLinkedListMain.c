#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

void WhoIsOnDuty(List * plist, char * name, int day);

int main(void)
{
	// List�� ���� �� �ʱ�ȭ /////////////////////////////
	List list;
	ListInit(&list);
	int i;
	Data data;

	data = (Employee*)malloc(sizeof(Employee));
	strcpy(data->name,"��");
	data->num = 1;
	LInsert(&list, data);

	data = (Employee*)malloc(sizeof(Employee));
	strcpy(data->name,"�μ�");
	data->num = 2;
	LInsert(&list, data);

	data = (Employee*)malloc(sizeof(Employee));
	strcpy(data->name,"����");
	data->num = 3;
	LInsert(&list, data);

	data = (Employee*)malloc(sizeof(Employee));
	strcpy(data->name,"��ȣ");
	data->num = 4;
	LInsert(&list, data);	

	//�μ��� ������ �ϰ� 7�� �� ����
	WhoIsOnDuty(&list, "�μ�", 10);

	//��ȣ�� ������ �ϰ� 3�� �� ����
	WhoIsOnDuty(&list, "��ȣ", 3);

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
	printf("%s�� ������ �� �ķ� %d�� �� ����: %s \n", pemp1->name, day, pemp->name);
}