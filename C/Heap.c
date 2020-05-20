#include <stdio.h>
static int a[10]={0,5,13,5,8,10,1,0,2,7};
int main()
{   
    
    void HeapSort(int a[],int length);
    
    int length=10;
    HeapSort(a,length);
    return 0;
}
//堆排序主体
void HeapSort(int a[],int length)
{
    void printArray();
    void CreateMaxHeap(int a[],int length);
    void swap(int a,int b);
    void ShiftDown(int a[],int k,int length);

    CreateMaxHeap(a,length);
    printArray();
    for(int i=length;i>1;i--)
    {
        printf("%d\t",a[1]);
        swap(a[1],a[i]);
        ShiftDown(a,1,i-1);
    }
}
//堆从下标1数组开始-方便类似于完全二叉树的操作
void CreateMaxHeap(int a[],int length){
    void ShiftDown(int a[],int k,int length);

    for(int i=length/2;i>0;i--)
    {
      ShiftDown(a,i,length);  
    }
}
void swap(int a,int b)
{
    int m=0;
    m=b;
    b=a;
    a=m;
}
void ShiftDown(int a[],int k,int length)
{
    a[0]=a[k];
    for(int i=2*k;i<=length;i*=2)
    {
        
        if(i<length&&a[i]<a[i+1]) //取出最大数
        {
            i++;
        }
        if(a[k]>=a[i])
        {
            break;
        }
        else
        {
            a[k]=a[i];  //大数提升
            k=i;        //小数下移，并继续判断下层
        }
    }
    a[k]=a[0];  //放入最终位置
}
//插入操作
void ShiftUp(int a[],int k)
{
    for(int i=k/2;i>0;i=i/2)
    {
        a[0]=a[k];
        if(a[i]<a[k])
        {
            a[k]=a[i];
            i=k;
        }else{
            break;
        }
    }
    a[k]=a[0];
}
void printArray()
{
    for(int i=1;i<=9;i++)
    {
        printf("%d  ",a[i]);
    };
    printf("\n");
}