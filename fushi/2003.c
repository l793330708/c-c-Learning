#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//阅读程序
    static void read_2003()
    {
        void swap(int **p1,int **p2);
        int a=1,b=3,*p=&a,*q=&b;
        swap(&p,&q);
        printf("%d,%d,%d,%d",a,b,*p,*q); //1,3,1,1
    }
int main()
{
    void insertData();
    void reverse();
    void searchData(char* str);
    int maxsameChar(char *s);
    void read_2003();
    void reverse();
    reverse();
    // char str[10]="0";
    // scanf("%s",str);
    // searchData(str);
    return 0;
}
//该题关键在于不要误认为是仅交换两指针所指地址

    void swap(int **p1,int **p2)
    {
        int *t;  //*p1 等价于p *p2等价于q
        t = *p1; //使临时指针变量t 指向a，即存储a的地址
        p1 = p2; //使p1 指向p2所指地址，即指针变量q的地址，若改为*p1 = *p2，即使p指向b，才能达到交换p指向b，q指向a的目的
        *p2 = t; //使指针变量q指向 t 所指地址，即指向a 
                //最终没有变量指向b所在地址
    }
//按字母大小合并字符串
    void merge(char *d,char *s1,char *s2)
    {
        while(*s1!='\0'&& *s2!='\0')
        {
            if(*s1<*s2)
            {
                *d = *s1; 
                s1++;
                d++; //* 和 ++ --的优先级相同，从右至左结合 *d++ = *s1++
            }else{
                *d = *s2;
                s2++;
                d++;
            }
        }
        while(*s1!=0)*d++=*s1++;
        while(*s2!=0)*d++=*s2++;
            *d = 0;
    }
//统计字符串中最大连续相同字符
    int maxsameChar(char *s)
    {
        char pre;
        int count = 1;
        int max = 1;
        pre = *s;
        while(*s++!='\0')
        {
            if(*s==pre)
            {
                count++;
            }else{
                if(count>max)
                {
                    max = count;
                }
                count = 1;
            }
            pre = *s;
        }
        return max;
    }
//翻转链表连接方向 需要三个指针
    void reverse()
    {
        typedef struct node{
            int key;
            struct node *next;
        }Node;
        Node *head,*p;
        head = p = (Node*)malloc(sizeof(Node));
        head ->key =5;
        head ->next =NULL; //带头节点
        for(int i=0;i<5;i++)
        {
            p->next = (Node*)malloc(sizeof(Node));
            p = p->next;
            p->key =i;
            p->next =NULL;
        }
        p = head->next;
        Node *r;
        while(p)
        {
            r = p->next;
            if(head->next!=p)
            {
                p->next = NULL;
                p->next = head->next;
                head ->next = p;
                p = r;
            }else{
                p ->next = NULL;
                p = r; //处理第一个节点
            }
        }
        p = head->next;
        while(p)
        {
            printf("%d ",p->key);
            p = p->next;
        }

    }
//车站信息查询
    void searchData(char* str)
    {
        FILE *fin;
        int flag=0;
        if((fin = fopen("2003.txt","r+"))==NULL)
        {
            printf("fail to create FILE!!");
            exit(0);
        }
        
        for(int i=0;i<3;i++)
        {
        char num[10],src[20],des[20],time[15];
        fscanf(fin,"%10s%20s%20s%10s",num,src,des,time);
        if(!strcmp(num,str))
        {
            printf("%-20s%-20s%-10s",src,des,time);
            flag=1;
            break;
        }
        }
        if(!flag)
        {
            printf("cannot find this train");
        }
        fclose(fin);
    }   
    void insertData()
    {
        FILE *fin;
        if((fin = fopen("2003.txt","w+"))==NULL)
        {
            printf("fail to create FILE!!");
            exit(0);
        }
        for(int i=0;i<3;i++)
        {
            char num[10],src[20],des[20],time[15];
            scanf("%s%s%s%s",num,src,des,time);
            fprintf(fin,"%-10s%-20s%-20s%-10s",num,src,des,time);
            fputc(10,fin);
        }
        fclose(fin);
    }