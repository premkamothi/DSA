////using namespace std;
////
////class node{
////public:
////    void fun(){
////        int a=7;
////        cout>>a;
////    }
////
////};
////int main(){
////    node *ob;
////    ob->fun();
////    return 0;
////
////}
//
//#include<stdio.h>
//#include<stdlib.h>
//
//struct circularQueue
//{
//    int size;  // Queue size
//    int f;     // Front index
//    int r;     // Rear index
//    int *arr;  // Queue storage
//};
//
//int isFull(struct circularQueue *q)
//{
//    return (q->r+1)%q->size==q->f;
//}
//
//int isEmpty(struct circularQueue *q)
//{
//    return q->f == q->r;
//}
//
//void enqueue(struct circularQueue *q, int value)
//{
//    if (isFull(q))
//    {
//        printf("Queue overflow\n");
//    }
//    else
//    {
//        q->r = (q->r+1) % q->size;
//        q->arr[q->r] = value;
//        printf("Enqueued: %d\n", value);
//    }
//}
//
//int dequeue(struct circularQueue *q)
//{
//    int a = -1;
//    if (isEmpty(q))
//    {
//        printf("Queue underflow\n");
//    }
//    else
//    {
//        q->f = (q->f+1) % q->size;
//        a = q->arr[q->f];
//        printf("Dequeued: %d\n", a);
//    }
//    return a;
//}
//
//int main()
//{
//    struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
//    q->size = 3;  // Adjust size to 3 to store 2 elements
//    q->f = 0;
//    q->r = 0;
//    q->arr = (int *)malloc(q->size * sizeof(int));
//
//    enqueue(q, 11);
//    enqueue(q, 22);
//    enqueue(q, 33);  // This should trigger overflow
//
//    dequeue(q);
//    dequeue(q);
//    dequeue(q);  // This should trigger underflow
//
//    return 0;
//}
//
#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications
void matrixChainOrder(int p[], int n) {
    // m[i][j] stores the minimum number of scalar multiplications needed
    int m[n][n];

    // Initialize m[i][i] to 0 because a single matrix needs no multiplication
    for (int i = 1; i < n; i++) {
        m[i][i] = 0;
    }

    // L is the chain length (subproblem size), starting from 2
    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;  // Initialize with a very large number

            // Try placing parenthesis at different points to split the chain
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;  // Update the minimum number of scalar multiplications
                }
            }
        }
    }

    // The minimum number of multiplications needed to multiply matrices A1 to An-1
    printf("Minimum number of multiplications: %d\n", m[1][n - 1]);
}

int main() {
    // Example for 2 matrices: A1 (2x2) and A2 (2x2)
    int arr[] = {2, 2, 2,2};  // Dimension array for two 2x2 matrices
    int n = sizeof(arr) / sizeof(arr[0]);

    matrixChainOrder(arr, n);

    return 0;
}
