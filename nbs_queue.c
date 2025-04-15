#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;

};

void linkedListT(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("element: %d\n",ptr->data);
        ptr=ptr->next;
    }

}

struct node * insertAtEnd(struct node *head,int data)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node));//make s new node for insert at end
    struct node * p=head;

    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;

};

struct node * deleteTheFirstNode(struct node * head)
{
    struct node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

int main()
{

    // allocate memory for the nodes in linked list in heap, dynamic memory allocation
    struct node * head= (struct node *)malloc(sizeof(struct node));
    struct node * second= (struct node *)malloc(sizeof(struct node));
    struct node * third= (struct node *)malloc(sizeof(struct node));

    // first node
    head->data=7;//data
    head->next=second;//next node address

    second->data=45;//data
    second->next=third;//next node address

    third->data=66;//data
    third->next=NULL;//next node address
    printf("Insertion\n\n");
    linkedListT(head);
    printf("\n");

    //insert

    head = insertAtEnd(head,1000);
    linkedListT(head);
    printf("\n");

    //delete

    head = deleteTheFirstNode(head);
    linkedListT(head);
     printf("\n");

    return 0;

}

