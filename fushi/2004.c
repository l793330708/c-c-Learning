#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//读函数
    static void read()
    {
        int a=2,b=3;
        // printf("%d\n",a+=b*5); //17 a = a+b*5;
        // printf("%d\n",a=b++); //3
        // printf("%d\n",a%=(a%=b)); //0
        // printf("%d\n",a=a>b&&b>a||a); //a = 0 && 1||2 ;a=1
        // printf("%d\n",a=!b<a&&!a<b); // a = 1 && 1
    }
int main()
{
//    read();
    void DecodeStr();
    DecodeStr();
    // char str1[]="Hello";
    // char str2[6]={'H','e','l','l','o',0};
    // printf("%d",strcmp(str1,str2));
   return 0;
}

//返回字符串相同char的最初位置
    int SamePos(char *s1,char *s2)
    {
        int index=0;
        while(*s1&&*s2)
        {
            index++;
            if(*s1++ == *s2++)
            {
                return index;
            }
            
        }
    }
//解码特殊字符串
void DecodeStr()
{
    int status =0,count=0;
    FILE *fp = fopen("E:\\vs_workspace\\C\\fushi\\2004.txt","r");
    if(fp == NULL)
    {
        printf("cannot open this file!");
        exit(0);
    }
    char ch;
    char head[]="AUG";
    char end[]="UGA";
    char tmp[4]={0};
    int flag=1;
    char str[50] ={0};
    char *p = str;
    while(!feof(fp)&&flag)
    {
        while(strcmp(tmp,head)!=0)
        {
            ch = fgetc(fp);
            while(ch!='A')
            {
                ch = fgetc(fp);
            }
            tmp[0] = ch;
            if((ch = fgetc(fp))!='U')continue;
            tmp[1] = ch;
            if((ch = fgetc(fp))!='G')continue;
            tmp[2] = ch;
            tmp[3] = 0;
        }
        str[count++] = (ch = fgetc(fp));
        if(count>2)
        {
            if(*p =='U' && *(p+1) =='G' && *(p+2)=='A')
            {
                flag =0;
            }
            p++;
        }
         
    }
    fclose(fp);
    int cxg = 1;
    for(int i=0;i<count-3;i++,cxg++)
    {
        printf("%c",str[i]);
        if(cxg%3 ==0)
        {
            printf("\t");   
        }
    }
   
}