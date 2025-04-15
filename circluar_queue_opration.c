#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;  // Queue size
    int f;     // Front index
    int r;     // Rear index
    int *arr;  // Queue storage
};

int isFull(struct circularQueue *q)
{
    return (q->r+1)%q->size==q->f;
}

int isEmpty(struct circularQueue *q)
{
    return q->f == q->r;
}

void enqueue(struct circularQueue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r] = value;
        printf("Enqueued: %d\n", value);
    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
        q->f=(q->f+1)%q->size;
        a = q->arr[q->f];
        printf("Dequeued: %d\n", a);
    }
    return a;
}

int main()
{
    struct circularQueue * q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q->size = 5;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enqueue(q, 11);
    enqueue(q, 22);
    enqueue(q, 33);
    enqueue(q, 44);

    dequeue(q);
    enqueue(q, 55);





    return 0;
}

