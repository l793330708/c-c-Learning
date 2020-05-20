#include <stdio.h>
#include <string.h>

int min(int x,int y)
{
    return x>y?y:x;
}
int main()
{
    int dp[101][101];
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            if(i==0 || j==0)
            {
                if(i==0)
                {
                    dp[i][j] = j;
                }
                if(j==0)
                {
                    dp[i][j] = i;
                }
            }else{
                 dp[i][j] = 1000;
            }
           
        }
    }
    //数组dp含义i,j意味dp[i][j] 即str1前面i个字符和str2前面j个字符相互转换的最小编辑距离
    char str1[10]= "Kiten";
    char str2[10] = "sitten";
    int x;
    for(int i=1;i<=strlen(str1);i++)
    {
        for(int j=1;j<=strlen(str2);j++)
        {
            if(str1[i-1] == str2[j-1]) //由于填充了 0行，0列
            {
                x = 0;
            }else{
                x = 1;
            }
            dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+x); 
        }
    }
    //如 A='a' B='a' ，则前一个状态dp[i-1][j]为A='',B='a'
    //dp[i][j-1] A='a',B=''，dp[i-1][j-1] A='',B=''
    //三种情况中dp[i-1][j]到dp[i][j]肯定要增加一个编辑距离，同理dp[i][j-1]
    //而dp[i-1][j-1]到dp[i][j]当str1[i]==str2[j]是不增加，否则+1
    printf("%d",dp[5][6]);
    return 0;
}
