#include <stdio.h>
#include <string.h>
#define N 31
//大数求因子，思路
int main()
{
       char nums[N];
    while(gets(nums))
    {
        if(nums[0]== '-')
        {
            break;
        }
        int len = strlen(nums);
        int flag = 0,count=0;
        for(int i=2;i<=9;i++)
        {
            int mod = 0;
            for(int j=0;j<len;j++)
            {
                mod = (mod*10 + nums[j]-'0')%i; //方法和按位取大数差不多
            }
            if(mod == 0)
            {
                flag = 1;
                count++;
                if(count>1)
                {
                    putchar(32);
                }
                printf("%d",i);
            }
        }
        if(flag ==0)
        {
            printf("none");
        }
        printf("\n");
        
    }
    return 0;
}