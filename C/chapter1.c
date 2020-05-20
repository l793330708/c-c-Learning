#include<stdio.h>

int main()

{
int swap(int a,int b);  //交换两数
void printfS(); //打印
int getMax(int a,int b,int c); //得到最大值
    int a,b,c,d;
     a = 20;
     b = 5;
     c = 21;
    d  = getMax(a,b,c);
    printf("%d",d);
   
    return 0;
}
int swap(int x,int y)
{
    int max;
    if(x > y){
        max = x;
    }else{
        max = y;
    }
    return (max);

}
void printfS(){
    printf("\n");
    for(int i= 0;i<20;i++)
    {
    printf("*");
    }
    printf("\n\t Very good!\n");
    for(int i= 0;i<20;i++)
    {
    printf("*");
    }
}
int getMax(int a,int b,int c)
{
    int d;
    return (a>(d=(b>c)?b:c))?a:d;
}