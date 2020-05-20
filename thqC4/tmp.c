#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a = 123456;
    int b = 67356;
    char str1[10],str2[10],res[10],rs[10];
    itoa(a,str1,10);
    itoa(b,str2,10);
    int count=0,max=0;
    for(int i=0;i<strlen(str1);i++)
    {
        int ii = i;
        for(int j=0;j<strlen(str2);j++)
        {
            if(str1[ii] == str2[j])
            {
                res[count] = str2[j];
                count++;
                ii++;
            }else{
                
                ii = i;
                if(count>max)
                {
                    res[count] = 0;
                    strcpy(rs,res);
                    max = count;
                }
                count = 0;
            }
        }
        if(count>max)
        {
            res[count] = 0;
            strcpy(rs,res);
            max = count;
        }
                count = 0;
    }
    printf("%d\n",max);
    printf("%s\n",rs);
    return 0;
}