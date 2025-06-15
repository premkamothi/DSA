#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;

};

int isFull(struct stack * ptr)
{
    if(ptr->top==ptr->size-1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(struct stack * ptr)
{
    if(ptr->top==-1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack * s,int value)
{


    if (isFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;
        printf("Pushed %d to stack\n", value);
    }

}

void pop(struct stack * s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int value=s->arr[s->top];
        s->top=s->top-1;
        printf("poped %d to stack\n",value);
    }

}

void peek(struct stack * s,int i)
{
    if(s->top-i+1<0){
        printf("not valid position");
        return -1;
    }
    else{
        printf("value at position %d is %d \n",i,s->arr[s->top-i+1]);
    }

}


int main()
{
//    struct stack s;
//    s.size=100;
//    s.top=-1;
//    s.arr=(int *)malloc(s.size * sizeof(int));

    int stackBottom, stackTop;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size=5;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));



    push(s,5);
    push(s,6);
    push(s,7);
    push(s,8);
    push(s,9);
    printf("\n");

    pop(s);
    printf("\n");

    peek(s,1);
    peek(s,2);
    printf("\n");

    stackBottom=s->arr[0];
    printf("%d\n",stackBottom);

    stackTop=s->arr[s->top];
    printf("%d\n",stackTop);



}
