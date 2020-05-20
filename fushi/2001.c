#include <stdio.h>
#include <stdlib.h>
#define AMS 100
#define AB AMS //宏定义可以嵌套，层层定义
int main()
{
    void read_5();
    void bitCal();
    void read_2();
    void read_3();
    void read_6();
    read_6();
    return 0;
}
void bitCal()
{
    printf("%d\n",6>5); //1
    printf("%d\n",6&&5); //1
    printf("%d\n",6||5); //1
    printf("%d\n",6<5); //0
    printf("%d\n",6^5); // 110 ^ 101 = 011 ->3
    printf("%d\n",6&5); // 110 & 101 = 100 ->4
    printf("%d\n",6|5); // 110 | 101 = 111 ->7
}
void enumDay()
{
    enum weekday{one,two,thr,fou,fiv};
    enum weekday working;
    working = thr;
    //  working = 2; //不能讲int 赋给 枚举类型
    working =(enum weekday)2; //枚举类型和数组一样，第二个元素是thr,第0个元素是one
    working =(enum weekday)(5-3);
    
}
//阅读程序1
void read_1()
{
    char *aplha[6]={"ABC","DEF","GHI","JKL","MNO","PQR"};
    char **p;
    int i;
    p = aplha;
    for(i=0;i<4;i++)
    {
        printf("%s",*(p+i)); //用p[i]也是可以的，但不能用(p+i)
        printf("\n");
    }
}
//阅读程序2
void read_2()
{
    void swap(int *x,int *y);
    int a,b,c;
    scanf("%d,%d,%d",&a,&b,&c);
    // p1 = &a;
    // p2 = &b;
    // p3 = &c;
    if(a>b)swap(&a,&b);
    if(a>c)swap(&a,&c);
    if(b>c)swap(&b,&c);
    printf("%d,%d,%d",a,b,c);
}
void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void read_3()
{
    struct T {
    char a; //1                   
    int *d; //8
    int b; //4
    int c:16; //2 后面制定16位
    double e; //8
};
//结构体内存结构（64位-8字节）
        /*
            char              10000000
            int*              11111111
            int int:16        11111100
            double            11111111
            总共占据32个字节
        */
struct T *p;
    printf("%d\n",sizeof(p)); //64bit windows 指针为8个字节
    printf("%d\n",sizeof(*p)); 
    printf("%d\n",sizeof(p->a));
    printf("%d\n",sizeof(p->d));
    printf("%d\n",sizeof(p->b));
    printf("%d\n",sizeof(p->e));
}
//指针变量对数组的引用
void read_4()
{
    int a[4][3]={1,2,3,4,5,6,7,8,9,10,11,12},(*prt)[3]=a,*p=a[0];
    printf("%d\n",a[1][2]);
    printf("%d\n",*(*(a+1)+2));
    printf("%d\n",*(*(prt+1)+2));
    printf("%d\n",*(p+5));
    printf("%d\n",(*(prt+1))[2]);
}
//共用体
void read_5()
{
    union 
    {
        short n;
        char ch[2];
    }u;
    short m;
    scanf("%d",&m);
    u.n =m;
    printf("\n%d\n",sizeof(u));
    printf("\n%d,%d",u.ch[0],u.ch[1]);
}
//
void read_6()
{
    void adjustDown(int arr[],int size);
    void adjustHeap(int arr[],int size);
    FILE *fp;
    char src[100],dst[100];
    printf("please input src filename:");
    scanf("%s",src);
    fp = fopen(src,"r");
    if(fp == NULL)
    {
        printf("cannot open this file!\n");
        exit(0);
    }
   int arr[101];
   for(int i=1;i<=100;i++) //读入数据
    {
        // if(i%5 == 0 && i!=0)
        // {
        //     fputc(10,fp);
        // }
        fscanf(fp,"%d",&arr[i]); //不需要加格式列
        // fprintf(fp,"%-5d",rand()%50);
    }
    // int arr[11]={10,2,3,4,5,6,7,8,9,10,1};
    for(int i=1;i<=100;i++) //输出原始数组
    {
        printf("%-3d",arr[i]);
        if(i%10==0)
        {
            printf("\n");
        }
    }
    printf("-------------------\n");
    adjustHeap(arr,100);
    // for(int i=1;i<=100;i++) //输出第一次堆排序数组
    // {
    //     printf("%-3d",arr[i]);
    //     if(i%10==0)
    //     {
    //         printf("\n");
    //     }
    // }
    for(int i=1;i<=100;i++) //输出当前序列最小数
    {
        printf("%-3d",arr[1]);
        swap(&arr[1],&arr[101-i]);
        adjustDown(arr,100-i);
        if(i%10==0)
        {
            printf("\n");
        }
    }
    if(ferror(fp))
    {
        printf("detect error!!\n");
        clearerr(fp);
    }
    fclose(fp);
}
//堆排序
void adjustHeap(int arr[],int size)
{
    void adjustUp(int arr[],int i,int size);
    int pivot = size /2;
    for(int i=pivot;i>=1;i--)
    {
        adjustUp(arr,i,size);
    }
}
void adjustUp(int arr[],int n,int size)
{
    int idx,tmp;
    tmp = arr[n];
    int flag =1;
    for(int i=2*n;i<=size&&flag;)
    {
       idx = i;
       flag =0; //判定交换符
       if(i+1 <= size)
        {
            if(arr[i]>arr[i+1])
            {
                idx = i+1;
            }
        }
        if(arr[n]>arr[idx])
        {
            flag = 1; //发生交换
            arr[n] = arr[idx]; //小元素上移
            arr[idx] = tmp; //比较位置下移
            n = idx; //交换坐标下移
            i = 2*n; //检测
        }
    }
    arr[n] =tmp; //节点最终位置
}
void adjustDown(int arr[],int size)
{
    int flag =1,idx,n=1;
    int tmp = arr[1];
    for(int i=2*n;i<=size&&flag;)
    {
       idx = i;
       flag =0;
       if(i+1 <= size)
        {
            if(arr[i]>arr[i+1])
            {
                idx = i+1;
            }
        }
        if(arr[n]>arr[idx])
        {
            flag = 1; //发生交换
            arr[n] = arr[idx]; //小元素上移
            arr[idx] = tmp;
            n = idx; //交换坐标下移
            i = 2*n; //检测
        }
    }
    arr[n] =tmp; //节点最终位置
}