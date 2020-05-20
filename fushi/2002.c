#include <stdio.h>
#include <string.h>
#include <malloc.h>
typedef struct Node 
    {
        int value;
        struct Node *next;
    }Node;
int main()
{
    void create_1();
    void read();
    Node* create(Node *head,int size);
    Node *head =NULL,*p;
    head = p = create(head,5);
    while(p!=NULL)
    {
        printf("%d",p->value);
        p = p->next;
    }
    return 0;

}
//字符串函数用法 需要包含string.h头文件
void read()
{
    char s1[100] = "I like C language",s2[100];
    strcpy(s2,s1);  //strcpy(dest,src)
    strcat(s1,s2);
    puts(s1);
    putchar(10);
    puts(s2);
}
//指针，指向一维数组指针
void read_1()
{
    char a[3][10]={"Beijing","Shanghai","Chengdu"};
    char *p1,(*p2)[10];
    p1 = a[0];
    p2 = a;
    printf("%c\n",*(a[1]+1)); //h
    printf("%s\n",p2+2); //Chengdu
    printf("%c\n",*(*(a+1)+2)); //a
    printf("%c\n",*(p1+1)); //e
    printf("%c\n",*(*(p2+1)+2));//a
    printf("%c\n",(*(p2+1))[2]); //a
    printf("%s\n",p2[2]);//Chengdu
    printf("%s\n",p2+1); //Shanghai
    printf("%s\n",p1+1); //eijing
}
//程序设计 构造递增链表 无头结点

Node* create(Node *head,int size)
{
    int val;
    Node *p = head;
    while(size--)
    {
        printf("val is:");
        scanf("%d",&val);
        if(!head) //建立头结点
        {   
            head = (Node*)malloc(sizeof(Node));
            head->value = val;
            head->next = NULL;
        }else
        {
             if(head->value > val)
            {
                p = (Node*)malloc(sizeof(Node));
                p->value = val;
                p->next = head;
                head = p;
            }else{
                Node *pre = head;
                p = pre->next;
                while( p !=NULL &&p->value < val)
                {
                    p = p->next;
                    pre = pre->next;
                }
                p = (Node*)malloc(sizeof(Node));
                p ->value =val;
                p->next = pre->next;
                pre->next = p;
            }
        }
        p = head;
    }
    return head;
}
Node *addItem(Node *head,int value)
{
    Node *p,*q,*r,*s;
    p = head;
    if(!p)
    {
        r = (Node*)malloc(sizeof(Node));
        r->value = value;
        r->next = NULL;
        head = r;
    }else if(value <=p->value)
    {
        r = (Node*)malloc(sizeof(Node));
        r->value = value;
        r->next = p;
        head = r;
    }else{
        q = p->next;
        while(q)
        {
            if(value<=q->value)
            {
                break;
            }else{
                p = q;
                q= p->next;
            }
        } //p q节点中为插入节点位置
        r= (Node *)malloc(sizeof(Node));
        r->value =value;
        r->next = p->next;
        p->next = r;
    }
    return head;
}
//程序设计 删除文件中的标签 
void create_1()
{   
    FILE *fp,*fout;
    if((fp = fopen("E:\\C\\fushi\\2002.txt","r"))==NULL)
    {
        printf("fail to open file!");
        return;
    }
     if((fout = fopen("E:\\C\\fushi\\2002cp.txt","w"))==NULL)
    {
        printf("fail to create file!");
        return;
    }
    while(!feof(fp))
    {
        char ch = fgetc(fp);
        if(ch=='<')
        {
            char chs[10]="";
            int i=0;
            while((ch = fgetc(fp))!='>')
            {
                chs[i++]=ch;
            }
            if(!strcmp(chs,"BR"))
            {
                fputc(10,fout);
            }
            if(!strcmp(chs,"/TITLE"))
            {
                fputc(10,fout);
            }
        }else if(ch!=10&&ch!='\0')
        {
            putc(ch,fout);
        }
        
    }
}
//外部引用 构造链表
struct Node* createList(int size)
{
    Node *head,*p;
    head = p = NULL;
    for(int i=0;i<size;i++)
    {
        int val;
        scanf("%d",&val);
        if(!head)
        {
            head = p =(Node*)malloc(sizeof(Node));  //初始节点
            p->value = val;
            
        }else{
            p->next = (Node*)malloc(sizeof(Node)); //
            p = p->next;
            p->value = val;
        }  
        p->next = NULL; 
    }
    p = head;
        while(p)
        {
            printf("%d\t",p->value);
            p = p->next;
        }
    return head;
}