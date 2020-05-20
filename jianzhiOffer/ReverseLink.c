#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
/*
    逆向打印链表节点
    */
struct Node
{
    int val;
    struct Node* next;
}node,*head;
int main()
{
    void reversePrint(struct Node* node);
    head = (struct Node*)malloc(sizeof(node));
    head->val = 5;
    head->next = NULL;
    struct Node *p = head;
    if(head == NULL)
    {
        exit(0);
    }
    for(int i=1;i<=5;i++)
    {
        p->next = (struct Node*)malloc(sizeof(head)); //初始化链表
        p = p->next ;
        p->val = i;
        p->next = NULL;
    }     
    reversePrint(head->next);          
    return 0;
}
void reversePrint(struct Node* node)
{
    if(node->next)
    {
        reversePrint(node->next);
    }
    printf("%d ",node->val);
}