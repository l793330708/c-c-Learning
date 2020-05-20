#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
int main()
{
    void Diagram_812();
    void Diagram_830(char *p);
    void Diagram_824();
    void Exmp_3_1();
    void Exmp_4(int n);
    void Exmp_5(int n);
    int Exmp_6(char *str);
    void Exmp_7();
    void Exmp_8();
    void Exmp_9();
    void Exmp_10();
    void Exmp_11(char (*)[20]);
    void Exmp_11_pArray(char *[3]);
    void Exmp_13(int lower,int upper,double (*p)(double x));
    void Exmp_14();
    void Exmp_15();
    void Exmp_16();
    int Exmp_17(char *str1,char *str2);
    void Exmp_18(char *p[],int i);
    void* Exmp_19(int size);
    void  Exmp_20(char *[5]);
    void Exmp_21(int *p);
    int *p = (int *)malloc(sizeof(int)*5);
    int *head = p;
    for(int i=0;i<5;i++,p++)
    {
        scanf("%d",p);
    }
    p = head;
    Exmp_21(p);
    
    for(int i=0;i<5;i++,p++)
    {
        printf("%d ",*p);
    }
    // char *p[5];
    // char position[5][20] = {"Ba","Bb","BB","BC","BD"};
    // for(int i=0;i<5;i++)
    // {
    //     p[i] = position[i];
    // }
    // Exmp_20(p);
    // for(int i=0;i<5;i++)
    // {
    //     printf("%s\n",p[i]);
    // }
    // char *p = (char*)Exmp_19(20);
    // char *p = Exmp_19(20);
    // for(int i=0;i<10;p++,i++)
    // {
    //     *p = '1';
    // }
    // *p = 0;
    // printf("%s",p-10);
    // char *p[] = {"January","February","March","April","May","June","July","August","Sepetember","October"
    // ,"November","December"};
    // Exmp_18(p,3);
    // Exmp_13(0,1,sin);
//     char strs[3][20],*pstrs[3];
//     for(int i=0;i<3;i++)
//     {
//         scanf("%s",strs[i]);
//         pstrs[i] = strs[i];
//     }
//    Exmp_11_pArray(pstrs);

    // Exmp_11(strs);
    // for(int i=0;i<3;i++)
    // {
    //     printf("%s\n",strs[i]);
    // }
    // char str[] = "I love ChengDu";
    // Diagram_830(str);
    // Diagram_824();
    // char *p;
    // printf("%d",&p);
    // p = "Hello";
    // printf("%d",&p);
    // printf("%d",Exmp_6("Hello My"));
    return 0;
}
void Diagram_812()
{
    int a[][4]={1,3,5,7,9,11,13,15,17,19,21,23}; //数组名是指向 int (*p)[4]类型
    int *p = *a; //*a a[0] &a[0][0] 三者等价
    int (*p1)[4] = &a[0]; //指向行向 a &a[0]等价
    printf("%d,%d\n",*p,**p1);
    printf("%d,%d,%d",*(p+6),*(*(p1+1)+2),*(p1[1]+2)); //输出13，coordinate:1,2
}
void Diagram_830(char *p)
{
    for(int i=0;p[i]!='\0';i++)
    {
        printf("%c",p[i]);
    }
}
/**
 * 指向函数的指针
 **/
void Diagram_824()
{
    int max(int a,int b);
    int min(int,int);
    int add(int,int);
    int (*p)(int,int),tcode,a,b;
    printf("please input type name:(1,2,3)\n");
    scanf("%d",&tcode);
    switch (tcode)
    {
    case 1:
        p = max;
        break;
    case 2:
        p = min;
        break;
    case 3:
        p = add;
        break;
    default:
        break;
    }
    printf("please input two nums\n");
    scanf("%d%d",&a,&b);
    int rs = (*p)(a,b); 
    char *format = "rs is %d"; //可变格式输出函数
    printf(format,rs);
}
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int add(int a,int b)
{
    return a+b;
}
//课后习题
/*
    输入三个数，按从小到大输出
    */
void Exmp_1()
{
    int a,b,c,*p1,*p2,*p3;
    scanf("%d%d%d",&a,&b,&c);
    p1 = &a;
    p2 = &b;
    p3 = &c;
    int tmp;
    if(*p1>*p2)
    {
        tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
    }
    if(*p1>*p3)
    {
        tmp = *p1;
        *p1 = *p3;
        *p3 = tmp;
    }
     if(*p2>*p3)
    {
        tmp = *p2;
        *p2 = *p3;
        *p3 = tmp;
    }
    printf("%d,%d,%d",*p1,*p2,*p3);
}
void Exmp_1_CP()
{
    int a,b,c,*p1,*p2,*p3;
    scanf("%d%d%d",&a,&b,&c);
    p1 = &a;
    p2 = &b;
    p3 = &c;
    int *tmp = NULL;
    if(*p1>*p2)
    {
        tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
    if(*p1>*p3)
    {
        tmp = p1;
        p1 = p3;
        p3 = tmp;
    }
     if(*p2>*p3)
    {
        tmp = p2;
        p2 = p3;
        p3 = tmp;
    }
    printf("%d,%d,%d",*p1,*p2,*p3);
}
/*
    输入三个字符串，从小到大的输出
    */
void Exmp_2()
{
    char str[3][20];
    for(int i=0;i<3;i++)
    {
        scanf("%s",str[i]);
    }
    char *p[3];
    int i=0;
    while(i<3)
    {
        p[i] = str[i];
        i++;
    }
    for(int i=0;i<2;i++)
    {
        char *pivot = p[i];
        int idx = i;
        for(int j=i+1;j<3;j++)
        {
            if(strcmp(pivot,p[j])>0)
            {
                pivot = p[j];
                idx = j;
            }
        }
        p[idx] = p[i];
        p[i] = pivot;
    }
}
/*
    输入十个数，最小的数放在第一个位置，最大的放在最后,三个函数，输入十个数，进行处理，输出十个数
    */
void Exmp_3_1() //输入函数
{
    void Exmp_3_2(int *head,int *end);
    int *p = (int *)calloc(10,sizeof(int)); //动态分配10个
    int *head = p;
    for(;p<head+10;p++)
    {
        scanf("%d",p); //键入十个整数
    }
    int *end = --p;
    p = head;
    Exmp_3_2(head,end);
}
void Exmp_3_2(int *head,int *end) //处理
{
    int *p = head;
    int max,min,maxidx=0,minidx=0;
    max = *p;
    min = *p;
    int i =0;
    while(p<=end)
    {
        if(*p>max)
        {
            max = *p;
            maxidx = i;
        }
        if(*p<min)
        {
            min = *p;
            minidx = i;
        }
        p++;
        i++;
    }
    int tmp;
    if(*end != head[maxidx])
    {
        
        tmp = head[maxidx];
        head[maxidx] =*end;
        *end = tmp;
        if(*end == head[minidx])
        {
            minidx = maxidx;
        }
    }
    if(*head != head[minidx])
    {
        tmp = head[minidx];
        head[minidx] =*head;
        *head = tmp;
    }
    p = head;
    while(p<=end)
    {
        printf("%d ",*p++);
    }
    
}
/*
    将n个数，前部分向后移m个位置，最后m个数变成最前面的位置
    输入：n 
    思路可利用reverse 翻转
 */
void Exmp_4(int n)
{
    void reverse(int *arr,int begin,int end);
    int *head,m;
    int *arr = (int *)malloc(sizeof(int)*n);
    head = arr;
    printf("please input n numbers\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr++);
    }
    arr = head;
    printf("please input m:");
    scanf("%d",&m);
    reverse(arr,0,n-1);
    reverse(arr,0,m-1);
    reverse(arr,m,n-1);
    printf("\n");
    for(;arr<=head+n-1;arr++)
    {
        printf("%d ",*arr);
    }
}
void reverse(int *arr,int begin,int end)
{
     int tmp;
    while(begin<end)
    {
        tmp = arr[begin];
        arr[begin] = arr[end];
         arr[end] = tmp; 
         begin++;
         end--;
    }
    
    
}
/*
    约瑟夫环问题 递推胜者
    输入：n 个人
    */
void Exmp_5(int n)
{
    int rs = 0;
    for(int i=2;i<=n;i++)
    {
        rs  = (rs+ 3)%i;
    }
    printf("%d is winner",rs+1);
}
/*
    求字符串长度,仿写 strlen
    */
int Exmp_6(char *str)
{
    int count=0;
    while(*str++)count++;
    return count;
}
/*
    字符串复制,仿写strncpy
    */
void Exmp_7()
{
    char *str ="Hello My Friend!";
    printf("please input offset:");
    int m;
    scanf("%d",&m);
    char *str2 = (char*)malloc(20);
    char *hstr2 = str2;
    str+=m-1;
    while(*str)
    {
        *str2++ = *str++;
    }
    *str2 = 0;
    printf("%s",hstr2);
}
/*
    统计一行文字中的大小写字母，空格，数字以及其他字符各有多少
    */
void Exmp_8()
{
    char *str =(char *)malloc(20);
    printf("please input str\n");
    scanf("%s",str);
    int uLetter=0,lLetter=0,space=0,num=0,other=0,type;
    while(*str)
    {
        type = 5;
        if(*str>='a'&&*str<='z')
        {
            type = 1;
        }else if(*str>='A'&&*str<='Z')
        {
            type = 2;
        }else if(*str>='0'&&*str<='9')
        {
            type = 3;
        }else if(*str ==32)
        {
            type = 4;
        }
        switch (type)
        {
        case 1:
            lLetter++;
            break;
        case 2:
            uLetter++;
            break;
        case 3:
            num++;
            break;
        case 4:
            space++;
            break;
        default:
            other++;
            break;
        }
    str++;
    }
    printf("string has %d UpperLetter,%d LowerLetter,%d space,%d num,and %d other\n",uLetter,lLetter,space,num,other);
}
/*
    转置 3x3 Matrix
    */
void Exmp_9()
{
    int matrix[3][3];
    int *p = matrix[0];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",p++);
        }
    }
    p = *matrix; 
    int tmp;
    for(int i=0;i<3;i++)
    {
        for(int j=i;j<3;j++)
        {
            tmp = p[i*3+j];
            p[i*3+j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
        
    }
    p = *matrix; 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",*p++);
        }
        printf("\n");
    }
}
/*
    5X5 matrix 中心放最大，四个角放置最小的数,且按照从左到右，从上到下最小 ,unfinished
    */
void Exmp_10()
{
    int matrix[5][5];
    int *p = *matrix;
    int *pmin = *matrix;
    int *pmax = *matrix;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",p);
            if(*pmax<*p)
            {
                pmax = p;
            }
            p++;
        }
    }
    p = *matrix;
   
    int m = (pmax - *matrix)/5;
    int n = (pmax - *matrix)%5;
    int tmp = matrix[m][n];
    matrix[m][n] = matrix[2][2];
    matrix[2][2] = tmp; 
    p = *matrix;
    // for(int i=0;i<5;i++)
    // {
    //     for(int j=0;j<5;j++)
    //     {
    //         printf("%d\t",*p++);
    //     }
    //     printf("\n");
    // }
}
/**
 *  对10个等长的字符串进行排序
 **/
void Exmp_11(char (*strs)[20])
{
    // char *strs)[20] = p;
    char tmp[20];
    // for(int i=0;i<3;i++)
    // {
    //     scanf("%s",strs[i]);
    // }
    for(int i=0;i<3;i++)
    {
        int k = i;
        for(int j=i+1;j<3;j++)
        {
            if(strcmp(strs[k],strs[j])>0)
            {
                k = j;
            }
        }
        if(k!=i)
        {
            strcpy(tmp,strs[k]);
            strcpy(strs[k],strs[i]);
            strcpy(strs[i],tmp);
        }
    }
    
}
/**
 *  对10个等长的字符串进行排序,指针数组
 **/
void Exmp_12(char *strs[3])
{
    // char *strs)[20] = p;
    char tmp[20];
    // for(int i=0;i<3;i++)
    // {
    //     scanf("%s",strs[i]);
    // }
    for(int i=0;i<3;i++)
    {
        int k = i;
        for(int j=i+1;j<3;j++)
        {
            if(strcmp(strs[k],strs[j])>0)
            {
                k = j;
            }
        }
        if(k!=i)
        {
            strcpy(tmp,strs[k]);
            strcpy(strs[k],strs[i]);
            strcpy(strs[i],tmp);
        }
    }
    
}
/**
 * 用矩形法求解定积分
 **/
void Exmp_13(int lower,int upper,double (*p)(double))
{
    double dx = (upper - lower)/1000000.0;
    double ans = 0;
    double x;
    for(double i = lower;i<=upper;i+=dx)
    {
        x = (*p)(i);
        ans += dx * x;
    }
    printf("%7.5f",ans);
}
/**
 * 模拟栈
 **/
#define N 10

void Exmp_14()
{
    typedef struct{
        int head;
        int num[N];
    }Stack;
    Stack o_stack ={.head = 0};
    for(int i=0;i<=9;i++)
    {
        scanf("%d",&o_stack.num[o_stack.head++]);
    }
    for(int i=0;i<=9;i++)
    {
        printf("%d\t",o_stack.num[--o_stack.head]);
    }
    
}
#undef N
/**
 * 求第一门课程的平均分;找出两门即以上不及格的学生，输出它全部成绩即平均成绩；找出平均分在90分以上或全部成绩在85以上的
 **/
void Exmp_15()
{
    void Exmp_15_1(int (*p)[5]);
    void Exmp_15_2(int (*p)[5]);
    int score[3][5];
    int *p = *score;
    int (*pstu)[5] =score; 
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",p++);
        }
    }
    Exmp_15_1(pstu);
    Exmp_15_2(pstu);
}
void Exmp_15_1(int (*p)[5])
{
    int ans = 0;
    for(int i=0;i<3;i++)
        ans += **p++;
    ans /=3;
    printf("The first subject's average socre is %d\n",ans);
}
void Exmp_15_2(int (*p)[5])
{
    int count;
    bool flag;
    int *pnum,avg;
    for(int i=0;i<3;i++)
    {
        pnum = p[i];
        count=0;
        flag = false;
        for(int j=0;j<5;j++)
        {
            if(pnum[j]<60)
                count++;
            if(count==2)
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            avg= 0;
            printf("%d student fail to pass the exam;scores as followings:\n",i);
            for(int j=0;j<5;j++)
            {
                avg +=pnum[j];
                printf("%d ",pnum[j]);
            }
            printf("average score is %d\n",avg);
        }
    }
}
/*
    提取字符串中的数字
    */
void Exmp_16()
{
    char str[]="A123x467 17960? 302tab5876";
    char *pre = str;
    char *p = pre+1;
    char tmp[5];
    int num[10];
    int tcount =0,count=0;
    while(*pre)
    {
        if(*pre>='0'&& *pre<='9')
        {
            tcount = 0;
            tmp[tcount++] = *pre;
            while(*p>='0'&& *p<='9')
            {
                tmp[tcount++] = *p++;
            }
            tmp[tcount] = 0;
            num[count++] = atoi(tmp);
            pre = p;
            p = p+1;
        }else
        {
            p++;
            pre++;
        }
    }
    while(count>0)
    {
        printf("%d ",num[--count]);
    }
}
/*
    自我实现strcmp功能
    */
int Exmp_17(char *str1,char *str2)
{
    while(*str1 == *str2 && *str1 && *str2)
    {
        str1++;
        str2++;
    }
    return *str1-*str2;
}
/*
 指针数组的引用
 */
void Exmp_18(char *p[],int i)
{
    printf("%s",p[i-1]);
}
/*
    模拟new函数
    */
void* Exmp_19(int size)
{
    return malloc(size);
}
/*
 指针指向指针的方法对字符串排序并输出
 */
void  Exmp_20(char *p[])
{
    char **pp = p; 
    char tmp[20];
    for(int i=0;i<5;i++)
    {
        int k = i;
        for(int j=i+1;j<5;j++)
        {
            if(strcmp(*(pp+k),*(pp+j))>0)
            {
                k = j;
            }
        }
        if(k!=i)
        {
            strcpy(tmp,*(pp+k));
            strcpy(*(pp+k),*(pp+i));
            strcpy(*(pp+i),tmp);
        }
        
    }
}
/*
    二重指针对数进行排序
    */
void Exmp_21(int *p)
{
    int **pp = &p;
    int tmp;
    for(int i=0;i<5;i++)
    {
        int k =i;
        for(int j=i+1;j<5;j++)
        {
            if(*(*pp+k)>*(*pp+j))
            {
                k = j;
            }
        }
        if(k!=i)
        {
            tmp = *(*pp+k);
            *(*pp+k) = *(*pp+i);
            *(*pp+i) = tmp;
        }
    }
}