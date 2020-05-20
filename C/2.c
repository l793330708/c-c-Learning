#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50
typedef struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode *LChild;
    struct BinaryTreeNode *RChild;
}BiTree;
int ValuePath(BiTree* root,int count)
{
    static int sum=0;
    static int i=0;
    static int arr[MAX_SIZE];
    if(root == NULL)
    {
        return 0;
    }
    sum += root->data;
    arr[i++] = root->data;
    ValuePath(root->LChild,count-root->data);
    ValuePath(root->RChild,count-root->data);
    if(sum ==count)
    {
        printf("The sequences are:\n");
        for(int j=0;j<i;j++)
        {
            printf("%d",arr[j]);
        }
    }
    sum -=root->data;
    i--;
}
BiTree* CreateBiTree()
{
    BiTree* pTree;
    int value;
    scanf("The value of the node:",&value);
    while(value!=0)
    {
        pTree=(BiTree*)malloc(sizeof(BiTree));
        pTree->data = value;
        pTree->LChild = CreateBiTree();
        pTree->RChild = CreateBiTree();
    }
    return pTree;
}
int main()
{
    BiTree *root = NULL;
    root = CreateBiTree();
    ValuePath(root,22);
    return 1;
}