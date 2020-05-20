 #include <stdio.h>
 #include <stdlib.h>
 typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode;
 ListNode* ReverseList(ListNode* pHead) {
        
         ListNode* p =  pHead->next;
         ListNode* t = pHead,*tmp;
         t->next = NULL;
        if(p == NULL)
        {
            return pHead;
        }else{
            while(p)
            {
                tmp = p->next;
                p->next = t;
                t = p;
                p  = tmp;
            }
            return t;
        }
    }
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
        ListNode *t,*p,*q,*thead;
        p = pHead1;
        q = pHead2;
        if(pHead1->val < pHead2->val)
        {
            thead = pHead1;
            p = pHead1->next;
        }else{
            thead = pHead2;
            q = pHead2->next;
        }
        t = thead;
        while(p && q)
        {
            if(p->val > q->val)
            {
                t->next = q;
                q = q->next;
            }else{
                t->next = p;
                p = p->next;
            }
            t = t->next;
        }
        while(p)
        {
            t->next = p;
            p = p->next;
        }
        while(q)
        {
            t->next = q;
            q = q->next;
            t = t->next;
        }
        return thead;
}
int main()
{
    ListNode *head = (ListNode*)malloc(sizeof(ListNode)),*p;
    p = head;
    head->val = 1;
    head->next = NULL;
    int arr[3]={3,10,20};
    int arr1[3]={5,6,7};
    for(int i=0;i<3;i++)
    {
        p->next = (ListNode*)malloc(sizeof(ListNode));
        p = p->next;
        p->val =arr[i];
        p->next = NULL;
    }
    // p = ReverseList(head);
    ListNode *head1 = (ListNode*)malloc(sizeof(ListNode));
    p = head1;
    head1->val = 4;
    head1->next = NULL;
    for(int i=0;i<3;i++)
    {
        p->next = (ListNode*)malloc(sizeof(ListNode)); //List1 0->1->2->3 list2 1->1->3->5
        p = p->next;
        p->val =arr1[i];
        p->next = NULL;
    }
    p = Merge( head,head1);
    while(p)
    {
        printf("%d ",p->val);
        p = p->next;
    }
    return 0;
}