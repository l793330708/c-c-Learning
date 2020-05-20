#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int value;
    struct Node* next;
}Node;
int main()
{
    Node *merge(Node*a,Node *b);
    void printTemp(int num,int size);
    Node *create(Node *head,int size);
    Node *merge_1(Node *a,Node *b);
    Node *head1,*head2;
    head1 = (Node*)malloc(sizeof(Node));
    head2 = (Node*)malloc(sizeof(Node));
    head1->value = 1;
    head2->value = 0;
    head1 = create(head1,2);
    head2 = create(head2,4);
    Node *p = merge_1(head1,head2);
    while(p)
    {
        printf("%d->",p->value);
        p = p->next;
    }

    return 0;
}
//创建链表
    Node *create(Node *head,int size)
    {
        Node *p = head;
        int val;
        while(size--)
        {
            if(head)
            {
                p ->next = (Node *)malloc(sizeof(Node));
                p = p->next;
                printf("input val:");
                scanf("%d",&val);
                p->value = val;
                p->next = NULL;
            }else{
                head = (Node *)malloc(sizeof(Node));
                printf("input val:");
                scanf("%d",&val);
                p = head;
                p->value = val;
                p->next = NULL;
            }
        }
        return head;
    }
//将两个递增链表合并成一个

    Node *merge(Node  *a,Node  *b)
    {
        Node *head,*t;
        if(a->value < b->value)
        {
            head = t = a;
            a = a->next;
        }else{
            head = t = b;
            b = b->next;
        }
        while(a&&b)
        {
            if(a->value < b->value)
            {
                t ->next = a;
                a = a->next;
            }else{
                t ->next = b;
                b = b->next;
            }
            t = t->next;
        }
        while(b)
        {
            t->next = b;
            b = b->next;
            t = t->next;
        }
        while(a)
        {
            t->next = a;
            a = a->next;
            t = t->next;
        }
        return head;
    }
Node *merge_1(Node *a,Node *b)
{
    Node *p,*q,*t;
    if(a->value <= b->value)
    {
        p = a;
        q = b;
    }else{
        p=b;
        q=a;
    }
    t = p;
    while(q)
    {
        if(p->next==NULL)
        {
            p->next =q;
            break;
        }
        if(q->value < p->next->value)
        {
            Node* k = q->next;
            q ->next = p->next;
            p ->next =q;
            q = k;
            continue;
        }
        p = p->next;
    }
    return t;
}

















//输出模板字符
    void printTemp(int num,int size)
    {
        FILE *fp;
        if((fp = fopen("E:\\template.txt","r"))==NULL)
        {
            printf("cannot open file");
            return;
        }
        char code[6][5][7]={};
        char (*p)[5][7] = code;
        int count=0;
        while(count<7)
        {
            for(int i=0;i<5;i++)
            {
                fgets(code[count][i],7,fp); //每次循环完毕读入一个数字模板
                code[count][i][6]=0;
            }
            
            count++;
        }
        int digit[3]={0},i=2;
        while(i>=0)
        {   
            digit[i--]=num%10;
            num/=10;
        }
        for(int j=0;j<3;j++)
        {
            int index = digit[j];
            for(int p=0;p<5;p++)
            {
                printf("%s",code[index][p]);
            }   
        }
        

        
    }