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

struct node * insertAtBegin(struct node *head,int data)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node));//make s new node for insert at begin
    ptr->next=head;
    ptr->data=data;
    return ptr;

};



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

struct node * insertAtIndex(struct node *head,int index,int data)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node));//make s new node for insert at begin
    struct node * p=head;
    int i=0;

    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;
};


struct node * deleteAtindex(struct node * head,int index)
{
    struct node * p=head;
    struct node * q=head->next;
    for(int i=0; i<index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;

};

struct node * deleteTheLastNode(struct node * head)
{
    struct node * p=head;
    struct node * q=head->next;
    while(q->next != NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);

    return head;

};

struct node * deleteGivenValue(struct node * head,int value)
{
    struct node * p=head;
    struct node * q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    if(q->data==value)
    {
        p->next=q->next;
        free(q);
    }
    return head;

};

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
    head = insertAtBegin(head,99);
    linkedListT(head);
    printf("\n");

    head = insertAtIndex(head,3,76);
    linkedListT(head);
    printf("\n");

    head = insertAtEnd(head,1000);
    linkedListT(head);
    printf("\n");

    //delete
    printf("\nDeletion\n\n");
    head = deleteFirstNode(head);
    linkedListT(head);
    printf("\n");

    head = deleteAtindex(head,2);
    linkedListT(head);
    printf("\n");

    head = deleteTheLastNode(head);
    linkedListT(head);
    printf("\n");

    head = deleteGivenValue(head,45);
    linkedListT(head);


    return 0;

}

