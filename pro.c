#include<stdio.h>

struct abc{
        int a,b;

}*ab;
int main()
{
ab->a=5;
printf("%d\n",ab->a);
return 0;
}
