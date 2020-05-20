#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
int main()
{
    int charto_I(char *strNum);
    float Average(int a[],int n);
    char a[]={'a','b','c'};
    printf("%d",strlen(a));
    return 0;
}
//提取字符串中的数字，如"12a" ->12
int charto_I(char *strNum)
{
    int num[10]={0},count=0;
    while(isdigit(*strNum)==1)
    {
        num[count++] = *strNum-'0'; //ASCII码差值为int值
        strNum++;
    }
    count--;
    int index=0,sum=0;
    for(;count>=0;count--)
    {
       sum+=num[count]*pow(10,index++);
    }
    return sum;
}
//
float Average(int a[],int n)
{
    if(n==1)
    {
        return *a;
    }else{
        return (Average(a,n-1)*(n-1)+a[n-1])/n;
    }
}