#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;

};

void circluarLinkedList(struct node * head){
    struct node *ptr=head;
    do{
            printf("element :%d\n",ptr->data);
            ptr=ptr->next;

    }while(ptr!=head);

}

struct node * insertionAtBegin(struct node * head,int data){
    struct node * ptr = (struct node *)malloc(sizeof(struct node));//make a new node ptr for insrtion
    ptr->data=data;
    struct node * p=head->next;//p node is after ptr node and travel till p->next is not being head

    while(p->next!=head){
            p=p->next;
    }
    //at this point p is at the last point

    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;


}

int main()
{

    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=fourth;

    fourth->data=4;
    fourth->next=head;

    circluarLinkedList(head);
    printf("\n");

    head =insertionAtBegin(head,5);
    circluarLinkedList(head);




}
