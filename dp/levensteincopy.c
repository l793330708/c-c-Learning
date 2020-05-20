#include <stdio.h>
#include <string.h>

int min(int x,int y)
{
    return x>y?y:x;
}
int main()
{
    int dp[101];
   
   
    char str1[10]= "el";
    char str2[10] = "hello";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i=0;i<=len2;i++)dp[i] = i; //dp[i] 意味着str1->str2所需最短编辑距离
    int t1,t2;
    for(int i=1;i<=len1;i++)
    {
        t1 = dp[0]++;
        for(int j=1;j<=len2;j++)
        {
            t2 = dp[j];
            if(str1[i-1]==str2[j-1])dp[j] = t1;
            else dp[j] = min(t1,min(dp[j-1],dp[j]))+1;
            t1 = t2;
        }
    }
    printf("%d\n",dp[len2]);
    return 0;
}
