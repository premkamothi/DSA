#include<stdio.h>


int fun(int a)
{
    if(a>1)

        fun(a-1);
    printf("%d\t",a);
    if(a%10==0){
        printf("\n");
    }

}

int main()
{
    fun(10);
    return 0;

}
