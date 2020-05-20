#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#define MAX(A,B) (A)>(B)?(A):(B)
#define PRINTF(Y) printf("Y=%d\t",Y)
#define HELLO 0
int main()
{
   #ifdef HELLO
    printf("HELLO!");
   #else
    printf("OK!");
    #endif
    #if HELLO
        printf("YES!");
    #endif
        printf("OVER!");
    // int a = '\0xaa';
    // PRINTF(a);
//    int a=1,b=2,c=3,d=4,t;
//    t = MAX(a+b,c+d);
//    PRINTF(t);
    // printf("%d\n",i);
    // char str_1[] = "Hello";
    // char str_2[] = "Beijing";
    // if(str_1>str_2)
    // {
    //     printf("%s",str_1);
    // }
    // char *s = "\t\"Name\\Address\n";
    // printf("%d",strlen(s));
    // union pw{
    //     int b;long a;char ch[2];
    // }m;
    // printf("%d",sizeof(m)); //4
    // printf("%d",sizeof(int)); //4
    // printf("%d",sizeof(long long)); //8
    // int a,b;
    // if(b=2,a=0)
    // {
    //     printf("in");
    // }
    // int i,j;
    // for(i = 4;i>=1;i--)
    // {
    //     for(j=1;j<=i;j++)putchar('C');
    //     for(j=1;j<=4-i;j++)putchar('D');
    //     printf("\n");
    // }
    // int a[6][6],k,j;
    // for(k=1;k<6;k++)
    // {
    //     for(j=1;j<6;j++)
    //     {
    //         a[k][j] == (k/j)*(j/k);
    //     }
    // }
    void mergeFile(char *rs1,char *rs2,char *dst);
    void selectKing(int m,int n);
    void selectKing_Link(int m,int n);
    // selectKing(5,4);
    // selectKing_Link(5,4);
    // mergeFile("E:\\vs_workspace\\C\\fushi\\A_2017.txt","E:\\vs_workspace\\C\\fushi\\B_2017.txt","E:\\vs_workspace\\C\\fushi\\C_2017.txt");
    return 0;           
}
/*
    文件合并，含字符比较;A_2017.txt,B_2017.txt
    */
void mergeFile(char *rs1,char *rs2,char *dst)
{
    void sort(char *str,int i);
    void sortFile(FILE *fp,char *arr);
    FILE *fp1 = fopen(rs1,"r+");
    FILE *fp2 = fopen(rs2,"r+");
    if((fp1&&fp2)==0)
    {
        exit(0);
    }
    char str1[20]; 
    sortFile(fp1,str1);
    char str2[20]; 
    sortFile(fp2,str2);
    FILE *out = fopen(dst,"w");
    int length_1 = strlen(str1);
    int length_2 = strlen(str2);
    // 
    // if(out==NULL)
    // {
    //     exit(0);
    // }
    char str3[length_1+length_2];
    str1[length_1-1] = 0;
    strcpy(str3,str1);
    strcat(str3,str2);
    sort(str3,length_1+length_2-1);
    // char *p1,*p2;
    // p1 = str1;
    // p2 = str2;
    // int count=0;
    // while(*p1!=EOF&&*p2!=EOF)
    // {
    //     if(*p1 > *p2)
    //     {
    //         str3[count++] = *p2;
    //         p2++;
    //     }else{
    //         str3[count++] = *p1;
    //         p1++;
    //     }
    // }
    // while(*p1!=EOF)str3[count++]=*p1++;
    // while(*p2!=EOF)str3[count++]=*p2++;
    // str3[count] = 0;
    fputs(str3,out);
    fclose(out);
    fclose(fp1);
    fclose(fp2);
}
/*
    文件内部排序 选择排序
    */
void sortFile(FILE *fp,char *str)
{
    int i = 0;
    while(!feof(fp))
    {
        str[i++] = fgetc(fp);
    }
    for(int j=0;j<i-1;j++)
    {
        char tmp = str[j];
        int index = j;
        for(int k=j+1;k<i-1;k++)
        {
            if(str[k]<str[index])
            {
                index = k;
            }
        }
        str[j] = str[index];
        str[index] = tmp;
    }
}
/*
    选择排序
    */
void sort(char *str,int i)
{
   for(int j=0;j<i-1;j++)
    {
        char tmp = str[j];
        int index = j;
        for(int k=j+1;k<i-1;k++)
        {
            if(str[k]<str[index])
            {
                index = k;
            }
        }
        str[j] = str[index];
        str[index] = tmp;
    }
}
/*
    猴子选大王,类比约瑟夫环，m只猴子，报第n个号的退出
    */
void selectKing(int m,int n)
{
    int ans = 0; //递推中，ans = 0即每次的胜利者
    for(int i=2;i<=m;i++)
    {
        ans = (ans + n)%i; //当for循环递推时，每次的ans都是新环的 0号，即最新的
        
    }
    printf("%d",ans);
}
/* 
    链表法 猴子选大王
    */
struct node
{
    int no;
    struct node* next;
}*head;
void selectKing_Link(int m,int n)
{
    head = (struct node*)malloc(sizeof(head));
    head->no = 1;
    head->next =NULL;
    struct node *nd = head;
    for(int i=1;i<m;i++)
    {
        nd->next = (struct node*)malloc(sizeof(head));
        nd = nd->next;
        nd->no = i+1;
        nd->next = NULL;
    }
    nd->next = head; //构造循环链表
    struct node *pre,*p;
    pre = nd ;
    p = head;
    for(int i=1;i<m;i++)
    {
        int count = n;
        while(--count)
        {
           p = p->next; // p 指针停留位置即出队位置
           pre = pre->next;
        }
        printf("No.%d monkey is out\n",p->no);
        pre->next = p->next ;
        p->next = NULL;
        // free(p);
        p = pre->next;
    }
    printf("NO.%d is winner",pre->no);
}