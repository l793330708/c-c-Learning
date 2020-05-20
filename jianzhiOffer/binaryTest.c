#include <stdio.h> 
#include <string.h>
#include <math.h>

int main()
{
    int intToBinary(int num);
    int intToBinary_Bit(int n);
    int countBinary(int n);
    // printf("%d",jumpFloorII(4));
    // printf("%d\n",intToBinary(-10));
    printf("please input num:");
    int num;
    scanf("%d",&num);
    printf("%d has %d '1' in binary ",num,countBinary(num));
    return 0;
}
/**
 * 一个整数（32位）转换二进制 同时求出里面1的个数 传统算法
 **/
int intToBinary(int n)
{
    int count = 0,count_1 = 0;;
    char bin[32];
    unsigned int num = n;
    memset(bin,'0',32);
    while(num>0)
    {
        count = 0;
        while(pow(2,count) <= num)count++;
        bin[--count] = '1';
        num = num - pow(2,count);
    }
    char *p = &bin[31]; //没有第32个元素
    while(p>=bin)
    {
        // printf("%c",*--p);
        if(*p-- =='1')
        {
            count_1++;
        }
    }
    return count_1;
}
/**
 *  与 1每位相与求二进制
 **/
int intToBinary_Bit(int n)
{
    int count = 0,count_1 = 0;;
    char bin[8];
    unsigned int num = n;
    memset(bin,'0',8);
    char flag = 1;
    while(flag!=0)
    {
        if(num & flag != 0)
        {
            count_1 ++; //
            bin[count] ='1';
        }
        count++;
        flag <<=1; 
    }
    char *p = &bin[7]; //没有第32个元素
    while(p>=bin)
    {
        printf("%c",*--p);
    }
    printf("\n");
    return count_1;
}
/**
 *  数-1 即将最右侧1变成0，接着把右侧所有的0变成1，与原数相与运算，则可去掉一个1，计算其中1的个数
 **/
int countBinary(int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n = n & (n-1);
    }
    return count;
}