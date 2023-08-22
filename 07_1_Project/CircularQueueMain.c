#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
    Queue q;
    QueueInit(&q);

    printf("%d %d ",sizeof(q.queArr), sizeof(2));

    for(int i =0; i<10; i++) //queArr�� size�� 400�̰� int �ϳ��� ������� 4�̹Ƿ� �� ä��� ������ 99�� ������ ä�� �� ����! 
    {
        Enqueue(&q, 1);
        Enqueue(&q, 2);
        Enqueue(&q, 3);
        Enqueue(&q, 4);
        Enqueue(&q, 5);
        Enqueue(&q, 6);
        Enqueue(&q, 7);
        Enqueue(&q, 8);
        Enqueue(&q, 9);
        Enqueue(&q, 0);
    }

    while(!QIsEmpty(&q))
        printf("%d ", Dequeue(&q));


    return 0;
}