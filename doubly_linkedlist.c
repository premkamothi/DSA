#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * next;
    struct node * prev;

};

void doublyLinkedListforPREV(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("element: %d\n",ptr->data);
        ptr=ptr->prev;

    }

}
void doublyLinkedListforNEXT(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("element: %d\n",ptr->data);
        ptr=ptr->next;

    }

}

struct node * insertAtBegin(struct node *n1head,int data)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node));//make s new node for insert at begin
    ptr->next=n1head;
    ptr->prev=NULL;
    ptr->data=data;
    return ptr;

};

struct node * insertAtEnd(struct node *n1head,int data)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node));//make s new node for insert at end
    struct node * p=n1head;

    ptr->data=data;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->prev=n1head;

    return n1head;

};

struct node * insertAtIndex(struct node *n1head,int index,int data)
{
    struct node * ptr =(struct node *)malloc(sizeof(struct node));//make s new node for insert at begin
    struct node * p=n1head;
    int i=0;

    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    p->prev=n1head;
    return n1head;
};

struct node * deleteFirstNode(struct node * n1head)
{
    struct node * ptr=n1head;
    n1head=n1head->next;
    n1head->prev=NULL;
    free(ptr);
    return n1head;


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


int main()
{

    struct node * n1head = (struct node *)malloc(sizeof(struct node));
    struct node * n2 = (struct node *)malloc(sizeof(struct node));
    struct node * n3 = (struct node *)malloc(sizeof(struct node));
    struct node * n4 = (struct node *)malloc(sizeof(struct node));

    n1head->data=11;
    n1head->next=n2;
    n1head->prev=NULL;

    n2->data=22;
    n2->next=n3;
    n2->prev=n1head;

    n3->data=33;
    n3->next=n4;
    n3->prev=n2;

    n4->data=44;
    n4->next=NULL;
    n4->prev=n3;

    doublyLinkedListforPREV(n4);
    printf("\n");

    doublyLinkedListforNEXT(n1head);
    printf("\n");

    printf("Insertion\n");
    n1head=insertAtBegin(n1head,90);
    doublyLinkedListforNEXT(n1head);
    printf("\n");

    n1head=insertAtEnd(n1head,99);
    doublyLinkedListforNEXT(n1head);
    printf("\n");

    n1head=insertAtIndex(n1head,2,4434);
    doublyLinkedListforNEXT(n1head);
    printf("\n");

    printf("Deletion\n");
    n1head=deleteFirstNode(n1head);
    doublyLinkedListforNEXT(n1head);
    printf("\n");


    n1head=deleteAtindex(n1head,2);
    doublyLinkedListforNEXT(n1head);
    printf("\n");

}
