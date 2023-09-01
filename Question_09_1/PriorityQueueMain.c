#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * ch1, char * ch2)
{
	return strlen(ch2)-strlen(ch1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "Good Morning");
	PEnqueue(&pq, "I am a boy");
	PEnqueue(&pq, "Priority Queue");
	PEnqueue(&pq, "Do you like coffee");
	PEnqueue(&pq, "I am so happy");


	while(!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
