#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
    struct node * top;

};

    struct node * top=NULL;


int isEmpty(struct node * top)
{
    if(top==NULL){
        return 1;
    }
    return 0;
}

int isFull(struct node * top)
{
    struct node * n = (struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        return 1;
    }
    return 0;
}

void linkedListT(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }

}

struct node * push(struct node * top, int x){
    if(isFull(top)){
        printf("Stack overflow");
    }
    else{
        struct node * n = (struct node *)malloc(sizeof(struct node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }

};

//int pop(struct node ** top){
//    if(isEmpty(*top)){
//        printf("Stack underflow");
//    }
//    else{
//        struct node * n=(*top);
//        (*top)=(*top)->next;
//        int x=n->data;
//        free(n);
//        return x;
//
//    }
//};

int pop(struct node * tp){
    if(isEmpty(tp)){
        printf("Stack underflow");
    }
    else{
        struct node * n=tp;
        top=tp->next;
        int x=n->data;
        free(n);
        return x;

    }
};

int peek(int pos)
{
    struct node * ptr = top;
     for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    return -1;

}


int main()
{
    top=push(top,11);
    top=push(top,22);
    top=push(top,33);
    top=push(top,44);
    top=push(top,55);
    linkedListT(top);
    printf("\n");

    int element;
    element = pop(top);
    printf("Poped Element is %d\n",element);
    linkedListT(top);
    printf("\n");

    for(int i=1; i<5;i++){
    printf("Value at position %d is: %d\n",i,peek(i));
    }



    return 0;
}
