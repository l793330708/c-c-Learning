#include <stdio.h>

int main()
{
    void Quicksort(int arr[],int low,int high);
    int arr[] = {8,3,2,1,9,6};
    Quicksort(arr,0,sizeof(arr)/4-1);
    for(int i=0;i<6;i++)
    {
        printf("%-5d",arr[i]);
    }
    return 0;
}

void Quicksort(int arr[],int low,int high)
{
    int getIndex(int arr[],int low,int high);
    if(low < high)
    {
        int index = getIndex(arr,low,high);
        Quicksort(arr,low,index-1);
        Quicksort(arr,index+1,high);
    }
    
}
int getIndex(int arr[],int low,int high)
{
    int pivot = arr[low];
    while(low< high)
    {
        while(arr[high]>pivot && low< high)high--; //右侧向左找小值
        arr[low] = arr[high]; //小的赋值
        while(arr[low]<pivot && low< high)low++; //左侧向右找大值
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}