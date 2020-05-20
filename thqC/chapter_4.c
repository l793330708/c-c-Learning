#include <stdio.h>
int main()
{
    //int a=2,b=3;
    //printf("%d",a<b); //用0 和 1 代表关系表达式的True or False
    char ch;
    ch = 'E';
    switch (ch)
    {
    case 'A':
        printf("1");

    case 'B':
        printf("2");
        
    case 'C':
        printf("3");
        break;
    default:
        printf("4");
    }
    return 0;
}