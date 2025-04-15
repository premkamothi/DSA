#include<stdio.h>


int fun(int a)
{
    if(a>1)

        fun(a-1);
    printf("%d\t",a);

}

int main()
{
    fun(5);
    return 0;

}
