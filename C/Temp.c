#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct node{
    int num[MAX];
    int length;

} *Link,Node;

void reverse(int *num,int length)
{
    int i =0;
    int t;
    while(i <length/2 )
    {
        t = num[i];
        num[i] = num[length-1];
        num[length - 1] = t;
        length--;
        i++;
    }
    return;
}
int main(void)
{
    int arrayNum;
    int i =0;
    Link list = (Link)malloc(sizeof(Node));
    list->length=0;
    while(1 == scanf("%d",&arrayNum)){
        list->length++;
    }
    reverse(list->num,list->length);
    for(;i<list->length;i++)
    {
        printf("%d",list->num[i]);
    }
    putchar('\n');
    return 0;
}