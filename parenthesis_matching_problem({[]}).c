// brackets should be closed (),[],{}.
// not valid []],(().

#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char * arr;

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

void push(struct stack * s,char value)
{


    if (isFull(s))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->arr[s->top] = value;

    }

}

char pop(struct stack * s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        char value=s->arr[s->top];
        s->top=s->top-1;

    }

}

int parenthesis(char * exp)
{
    //make first stack
    struct stack * sp=(struct stack *)malloc(sizeof(struct stack));;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sizeof(char));

    for(int i=0; exp[i]!='\0';i++){
            if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
                push(sp,'(');
               }
            else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
                if(isEmpty(sp)){
                    return 0;
                }
                pop(sp);
            }
    }
    if(isEmpty(sp)){
        return 1;
    }
    return 0;
}




int main()
{
    char * exp = "81+2[";

   if(parenthesis(exp)){
    printf("The parenthesis is matching");
   }
   else{
     printf("The parenthesis is not matching");

   }

}
