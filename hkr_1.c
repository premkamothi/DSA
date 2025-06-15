#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char ch;
    char str[100];
    char sentance[100];
    scanf("%c", &ch);
    printf("%c", ch);

    scanf("%s",str);
    printf("\n%s",str);

    scanf("%*c");
    scanf("%[^]%*c", sentance);
    printf("\n%s",sentance);


}
