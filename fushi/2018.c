#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    void printAllSubStr(char *str);
    int checkCardNum(char *num,int length);
    int searchNum();
    // char str[10]= "abcde";
    // printAllSubStr(str);
    // char str[] = "5432123456788881";
    // if(checkCardNum(str,strlen(str)))
    // {
    //     printf("This cardNum is fine");
    // }else{
    //     printf("error cardNum");
    // }
    printf("%d",searchNum());
    return 0;
}
/*
    字符串公共最长序列长度
    */
void strCommonNum()
{
    long a = 123456l;
    long b = 671l;
    char str_1[10];
    char str_2[10];
    itoa((int)a,str_1,10);
    itoa(b,str_2,10);
    printf("%s\n",str_1);
    printf("%s\n",str_2);
    int max = 0;
    for(int i=0;i<strlen(str_1);i++)
    {
        int count = 0;
        int flag = 0;
        int tmp = i;
        for(int j=0;j<strlen(str_2)&&i<strlen(str_1);j++)
        {
            flag = 0;
            if(str_1[tmp]==str_2[j])
            {
                count++;
                tmp++;
                flag = 1;
            }
            if(!flag)
            {
                tmp = i; //重新返回起点
                if(count>max)
                {
                    max = count;
                }
            }
        }
        if(count>max)
        {
            max = count; //检测末尾
        }
    }
    printf("%d",max);
}
void printAllSubStr(char *str)
{
    int length = strlen(str);
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
        {
            printf("%c",str[j]);
        }
        printf("\n");
    }
}
/*
    卡号检测问题：逆向奇数位相加，逆向偶数位先乘2，大于10减9，在求和，若奇数和加偶数和能被10整除则卡号可行
    */
int checkCardNum(char *num,int length)
{
    int even[length];
    int odd[length];
    int j=0,k=0;
    char *p  = &num[length-1];
    int len = length ;
    int flag= 1;
    while(len--)
    {
        if(flag)
        {
            odd[k++] = *p-'0';
            flag = 0;
        }else{
             even[j++] = *p-'0';
             flag = 1;
        }
       p--;
    }
    int oddSum=0;
    for(int i=0;i<k;i++)
    {
        oddSum+=odd[i];
    }
    int evenSum=0;
    for(int i=0;i<j;i++)
    {
        even[i]*=2;
        if(even[i]>=10)
        {
            even[i]-=9;
        }
        evenSum+=even[i];
    }
    if((evenSum+oddSum)%10==0)
    {
        return 1;
    }else{
        return 0;
    }
    
}
/*
    优化版
    */
int checkCardNum_opm(char *num,int length)
{
    int sum=0;
    for(int i=1;i<=length;i++)
    {
        if(i%2==0)
        {
            num[length-i]*=2;
            if(num[length-i]>=10)
            {
                num[length-i]-=9;
            }
        }
        sum += num[length-i];
    }
    if(sum%10==0)
    {
        return 1;
    }else{
        return 0;
    }
}
/*
    一个人年龄三次方是四位数，4次方是6位数，十个数包含了0~9，求这个数
    */
int searchNum()
{
    int count[10];
    for(int i=10;;i++)
    {
        long pw3 = pow(i,3);
        long pw4 = pow(i,4);
        if((pw3>=1000 && pw3<10000 && pw4>=100000 && pw4<=999999)==0)
        {
            continue;
        }
        int tmp,flag = 1;
        memset(count,0,sizeof(count));
        while(pw3)
        {
            tmp = pw3%10;
            if(++count[tmp]==2)
            {
                flag = 0;
                break; //搜索下一个
            }
            pw3/=10;
        }
        if(!flag)
        {
            continue;
        }
        while(pw4)
        {
            tmp = pw4%10;
            if(++count[tmp]==2)
            {
                flag = 0;
                break; //搜索下一个
            }
            pw4/=10;
        }
        if(flag)
        {
            return i;
        }
    }
    return -1;
}