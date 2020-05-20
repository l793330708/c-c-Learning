#include <stdio.h>

int main()
{   
    int *q ,a,b,temp;
    a = 100;
    b = 10;
    q = &a;
    printf("q=%d",q);
    printf("*q=%d\n",*q);
    printf("------------\n");
    printf("a= %d,b= %d\n",a,b);
    // q = &b;
    temp = *q;
    *q = b;
    b = temp;
    printf("q=%d\n",q);
    printf("a= %d,b= %d\n",a,b);
    printf("*q=%d\n",*q);
    return 0;
}
int fac(int n)
{
    static int f=1;
    f= f*n;
    return f;
}