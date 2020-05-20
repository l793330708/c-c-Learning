#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 10
/**
 * 参数列表 第一个为文件路径 后面为指针向量组，指向命令行程序
 **/
int main(int argc,char *argv[])
{
    void Exmp_1();
    int Exmp_2(int year,int month,int day);
    void Exmp_3();
    void Exmp_6();
    // Exmp_6();
    // int ans=0;
    // for(int i=2;i<=13;i++)
    // {
    //     ans  = (ans +3)%i;
    // }
    // printf(" %d",ans+1);
//    Exmp_1();
    printf("Today is 2020's %d day\n",Exmp_2(2020,4,26));
    return 0;
}
/*
 定义结构体变量包括年月日，计算改日在本年中是第几天，注意闰年问题
 */
void Exmp_1()
{
    typedef enum {Jau=1,Feb=2,Mar,Apr,May,Jun,July,Aug,Sep,Oct,Nov,Dec}Month;
    typedef struct 
    {
        int year;
        Month month;
        int day;
        
    }Date;
    Date date ={2020,Jau,4};
    int count = 0;
    for(int i=Jau;i<date.month;i++)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            count+=31;
        break;
        case 2:
            if(date.year % 4 != 0)
            {
                count+=28;
            }else if(date.year %100 !=0)
            {
                count+=29;
            }else if(date.year %400 ==0)
            {
                count+=29;
            }else{
                count+=28;
            }
            break;
        default:
            count+=30;
            break;
        }
    }
    count+= date.day;
    char formatstr[][30]={"%d.%d.%d is %d's %dst day\n","%d.%d.%d is %d's %dnd day\n","%d.%d.%d is %d's %drd day\n","%d.%d.%d is %d's %dth day\n"};
    char *pformate = NULL;
    switch (date.day)
    {
    case 1:
        pformate = formatstr[0];
        break;
    case 2:
        pformate = formatstr[1];
        break;
    case 3:
        pformate = formatstr[2];
        break;
    default:
        pformate = formatstr[3];
        break;
    }
    printf(pformate,date.year,date.month,date.day,date.year,count);
}
/*
 实现第一题计算，从主函数传递年月日给其计算，返回日字数
 */
int Exmp_2(int year,int mon,int day)
{
    typedef enum{Jau=1,Feb=2,Mar,Apr,May,Jun,July,Aug,Sep,Oct,Nov,Dec}Month;
    typedef struct 
    {
        int year;
        Month month;
        int day;
    }Date;
    Date date = {.year = year,.month=(Month)mon,.day = day};
    int count = 0;
    for(int i=Jau;i<date.month;i++)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            count+=31;
        break;
        case 2:
            if(date.year % 4 != 0)
            {
                count+=28;
            }else if(date.year %100 !=0)
            {
                count+=29;
            }else if(date.year %400 ==0)
            {
                count+=29;
            }else{
                count+=28;
            }
            break;
        default:
            count+=30;
            break;
        }
    }
    count+= date.day;
    return count;
}
/*
 输出学生成绩数组
 */
 typedef struct  
    {
        int no;
        char name[10];
        int score[3];
    }Student;
    
void Exmp_3()
{
    void Exmp_4(Student []);
   Student stus[3];
   Exmp_4(stus);
   for(int i=0;i<3;i++)
    {
        printf("%-5d",stus[i].no);
       
        printf("%-10s",stus[i].name);
        for(int j=0;j<3;j++)
        {
            printf("%-3d",stus[i].score[j]);
        }
        printf("\n");
    }
}
/*
 第三题的输入函数
 */
void Exmp_4(Student stus[])
{
     for(int i=0;i<3;i++)
    {
        printf("please input stu no:");
        scanf("%d",&stus[i].no);
        printf("please input stu name:");
        scanf("%s",stus[i].name);
        printf("please input stu scores[3]:");
        for(int j=0;j<3;j++)
        {
            scanf("%d",&stus[i].score[j]);
        }
        printf("\n");
    }
}
/*
    13个人围成圈，从第一个人开始顺序报号，报到3退出圈子，链表实现
    */
void Exmp_6()
{
    typedef struct Node
    {
        int no;
        struct Node *next;
    }Node;
    Node *head  = (Node *)malloc(sizeof(Node));
    Node *p = head;
    for(int i=0;i<13;i++)
    {
        p->next = (Node *)malloc(sizeof(Node));
        p = p->next;
        p->no = i+1;
        p->next = NULL;
    }
    p->next = head->next; //构成循环链表
    Node *pre = p;
    p = pre->next; 
    int count =1;
    while(p->next != p)
    {
        count++;//报数
        p = p->next;
        pre = pre->next;
        if(count==3)
        {
            count = 1;
            pre->next = p ->next;
            printf("%d is passed\n",p->no);
            p->next = NULL;
            free(p);
            p = pre->next;
        }
    }
    printf("%d is winner!\n",p->no);
}