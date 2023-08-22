#include <stdio.h>
#include "CircularQueue.h"

int main(void)
{
    Queue q;
    QueueInit(&q);

    printf("%d %d ",sizeof(q.queArr), sizeof(2));

    for(int i =0; i<10; i++) //queArr의 size는 400이고 int 하나의 사이즈는 4이므로 꽉 채우기 직전인 99개 까지는 채울 수 있음! 
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