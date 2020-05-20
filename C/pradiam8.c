#include <stdio.h>
int main()
{
char *p1,*p2,*p3,str[3][10],*temp;
for(int i = 0;i<3;i++)
  scanf("%s",str[i]);
p1 = *(str);
p2 = *(str+1);
p3 = *(str+2);
printf("str1=%s,str2=%s,str3=%s\n",str,str+1,str+2);
printf("p1=%s,p2=%s,p3=%s\n",p1,p2,p3);
printf("------------\n");
if(*p1 < *p2)
{
  temp = p1;
  p1 = p2;
  p2 = temp;
}
if(*p1 < *p3)
{
  temp = p1;
  p1 = p3;
  p3 = temp;
}
if(*p2 < *p3)
{
  temp = p2;
  p2 = p3;
  p3 = temp;
}
printf("str1=%s,str2=%s,str3=%s\n",str,str+1,str+2);
printf("p1=%s,p2=%s,p3=%s\n",p1,p2,p3);
printf("*p1=%d,*p2=%d,*p3=%d\n",*p1,*p2,*p3);
return 0;
}
