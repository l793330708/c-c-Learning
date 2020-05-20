#include <stdio.h>

void main()
{
    void exchange(int *a, int *b);
    int a,b,c,*p1,*p2,*p3;
    scanf("%d,%d,%d",&a,&b,&c);
    p1 = &a;
    p2 = &b;
    p3 = &c;
    printf("p1=%d,p2=%d,p3=%d",p1,p2,p3);
    printf("-------------");
    if(a<b)exchange(p1,p2);
    if(b<c)exchange(p2,p3);
    if(a<b)exchange(p1,p2);
    printf("a=%d,b=%d,c=%d\n",a,b,c);
    printf("p1=%d,p2=%d,p3=%d",*p1,*p2,*p3);
    printf("-------------");
    printf("p1=%d,p2=%d,p3=%d",p1,p2,p3);
}
void exchange(int *a, int *b)
{   
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}