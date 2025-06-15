#include<stdio.h>
#include<stdlib.h>

//nbs_queue also queue


struct node{
    int data;
    struct node * next;
};

struct node * f;
struct node * r;

void enqueue(int value)
{

    struct node * n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data=value;
        n->next=NULL;
        printf("Enqueued: %d\n",value);
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}

int dequeue()
{
    int value=-1;
    struct node * ptr = f;
    if(f==NULL){
        printf("Queue is Empty");
    }
    else{
        f=f->next;
        value=ptr->data;
        free(ptr);
        printf("Dequeued: %d\n",value);
    }
    return value;
}


int main()
{
    enqueue(11);
    enqueue(22);
    enqueue(33);

    dequeue();
    dequeue();
    dequeue();
    dequeue();


}
