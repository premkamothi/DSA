#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * f;
struct node * r;

void enqueueF(int value)
{
    struct node * n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data=value;
        n->next=f;
        printf("Enqueued from Front: %d\n",value);
        if(f==NULL){
            f=r=n;
        }
        else{
            f=n;
        }
    }

}
void enqueueR(int value)
{
     struct node * n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is Full");
    }
    else{
        n->data=value;
        n->next=NULL;
        printf("Enqueued from Rare: %d\n",value);
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }

}
int dequeueF()
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
        printf("Dequeued from Front: %d\n",value);
    }
    return value;

}
void dequeueR()
{
    struct node * ptr = f;
    if(f==NULL){
        printf("Queue is Empty");
    }
    else{
        while(ptr->next!=r){
            ptr=ptr->next;
        }
         printf("Dequeued from Rare: %d\n",r->data);
         free(r);
         r=ptr;
         r->next=NULL;
    }

}

void Print()
{
    struct node * ptr = f;
    while(ptr!=NULL){
        printf("%d-->",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    enqueueR(11);
    enqueueF(22);
    enqueueR(0);
    enqueueF(33);
    Print();


}
