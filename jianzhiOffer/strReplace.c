#include <stdio.h>
#include <string.h>
/*
    替换字符串中的空格，用"%20"代替
    */
int main()
{
    void replaceSpace(char *str,int length);
    char str[]  = "Hello My Friend!";
    replaceSpace(str,16);
    printf("%s",str);
    return 0;
}
void replaceSpace(char *str,int length) 
{
        int spaceNum = 0;
        char *p = str;
        while(*p!=0)
        {
            if(*p++ == 32)
            {
                spaceNum++;
            }

        }
        char str_cpy[length + 2*spaceNum + 1];
        char add[] ="%20";
        int k = 0;
        for(int i=0;i<length;i++)
        {
            if(str[i]!=32)
            {
               str_cpy[k++] = str[i];
            }else{
                for(int j =0;j<3;j++)
                {
                    str_cpy[k++] = add[j];
                }
            }
        }
        str_cpy[k] = 0;
}