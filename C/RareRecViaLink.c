#include <stdio.h>
#include <malloc.h>
typedef int DataType;
 
struct LNode//数据结构
{
    int col;//列
    DataType value;//元素值
    struct LNode *next;//指向同行下一个非零结点指针
};
 
void InArray(struct LNode *row[],int r,int col,int value);
void PrintArray(struct LNode *row[]);
 
int main() {
    struct LNode *row[5]= {NULL};
 
    InArray(row,0,0,11);
    InArray(row,0,3,14);
    InArray(row,0,4,15);
    InArray(row,1,1,22);
    InArray(row,2,4,35);
    InArray(row,4,0,51);
    InArray(row,4,2,53);
 
    PrintArray(row);
    return 0;//程序退出时，malloc的内存会被操作系统自动回收，所以不用free
}
 
void InArray(struct LNode *row[],int r,int col,int value) {
    struct LNode *q,*s;
 
    s=(struct LNode *)malloc(sizeof(struct LNode));
    s->col=col;
    s->value=value;
    s->next=NULL;
 
    if (row[r]==NULL) {
        row[r]=s;
        return;
    } else {
        q=row[r];
        while (q->next!=NULL) q=q->next;
        q->next=s;
    }
}
 
void PrintArray(struct LNode *row[]) {
    int i,j,value;
    struct LNode *q;
    for(i=0;i<5;i++) {
        for(j=0;j<5;j++) {
            q=row[i];
            value=0;
            while (1) {
                if (q==NULL) break;
                if (q->col==j) {
                    value=q->value;
                    break;
                } else {
                    q=q->next;
                }
            }
            printf("%4d",value);
        }
        printf("\n");
    }
}