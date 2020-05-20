#include <stdio.h>
/**
 * 从数组中选取几个数使得它的和为9
 **/
int main()
{
    int arr[] = {3,34,4,12,5,2};  
    int subset[6][10]={0}; //二维数组含义即subset[i][j]表示用 arr[]中前i个数拼出j的可能性，
    for(int i=0;i<6;i++)
    {
        subset[i][0]= 1; //任何数都可以拼出0，subset[1][9] = 0 表示用3,31两个数拼出9
    }
    subset[0][arr[0]] =1; //只有一个数时，只能拼出本身
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<10;j++)
        {
            if(arr[i]>j)
            {
                subset[i][j] = subset[i-1][j]; //当目前的数大于所拼时，一定不能选该数
            }else
            {
                subset[i][j] = subset[i-1][j] || subset[i][j-arr[i]]; //目前数能否拼成 j 关乎于选当前的数和不选当前数的并集
            }
            
        }
    }
    printf("%d",subset[5][9]); //用arr[]前6个数是否能拼出9
    return 0;
}