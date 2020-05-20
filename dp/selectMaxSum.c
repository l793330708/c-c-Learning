#include <stdio.h>
#include <stdlib.h>
/**
 * 从数组中选取几个数使得它累加的和最大，相邻的数字不能入选
 **/
int main()
{
 int arr[] ={1,2,4,1,7,8,3};
    int opt[7] = {0};
    opt[0]=1;
    opt[1]=2;
    for(int i=2;i<=6;i++)
    {
        opt[i] = opt[i-1]>opt[i-2]+arr[i]?opt[i-1]:opt[i-2]+arr[i];
    }
    printf("%d",opt[6]);
    return 0;   

}