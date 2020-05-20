#include <stdio.h>
#include <string.h>
#include <math.h>
int main( )
{
    // char *s[6]={ "ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX" };
    // fun(s);   
    // printf("\n");
    int jumpFloorII(int number);
    
    return 0;
}
void fun( char ** p)
{
    int i;
    for(i=0;i<4;i++)printf("%s",*p[i]);
}
/**
 * 动态规划 跳楼层
 **/
int jumpFloorII(int number) 
{
    int ans[100];
    memset(ans,0,100*sizeof(int));
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for(int i=3;i<=number;i++)
    {
        for(int j=1;j<=i;j++)
        {
            ans[i] += ans[i-j];
        }
    }
    return ans[number];
}
