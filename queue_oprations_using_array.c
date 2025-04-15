// Queue ADT
// FIFO
// Data: 1.storage 2.insertion end 3.deletion end
// Methods 1.enqueue 2.dequeue 3.first value 4.last value 5.peek etc.

#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;  // Queue size
    int f;     // Front index
    int r;     // Rear index
    int *arr;  // Queue storage
};

// Check if the queue is full
int isFull(struct queue *q)
{
    return q->r == q->size - 1;
}

// Check if the queue is empty
int isEmpty(struct queue *q)
{
    return q->f == q->r; // Queue is empty when front and rear are the same
}

// Enqueue an element into the queue
void enqueue(struct queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;  // Add value to the rear
        printf("Enqueued: %d\n", value);  // Print the enqueued value
    }
}

// Dequeue an element from the queue
int dequeue(struct queue *q)
{
    int a = -1; // Initialize return value for empty queue case
    if (isEmpty(q))
    {
        printf("Queue underflow\n");
    }
    else
    {
        q->f++;            // Move front pointer forward
        a = q->arr[q->f];  // Dequeue the element
        printf("Dequeued: %d\n", a); // Print the dequeued value
    }
    return a; // Return the dequeued value
}

int main()
{
    // Create a queue and initialize its attributes
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 3;  // Increasing the size of the queue to avoid overflow
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // Enqueue elements
    enqueue(q, 11);
    enqueue(q, 22);
    enqueue(q, 33);  // This will work as the queue size is 3 now

    // Try enqueuing an extra element to show overflow
    enqueue(q, 44);  // This should print "Queue overflow"

    // Dequeue elements
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // Try dequeuing from an empty queue to show underflow
    dequeue(q);  // This should print "Queue underflow"

    return 0;
}

