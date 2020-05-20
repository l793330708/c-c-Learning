#include <stdio.h>
#include <math.h>
void main(){
    void typeInChars();
    void outPutChars();
    void variousOutput();
    variousOutput();
}
void typeInChars()
{
    
    //float只有6~7位有效数字
    char a[1];
    printf("%s",gets(a));
}
void outPutChars()
{
   putchar('B');
   putchar('O');
   putchar('Y');
}
void variousOutput(){
    //%s 为字符串 %d = %i 输出十进制 %c 输出一个字符 %f 输出实数
    //%e 为指数形式
    //2^31- 1
    double f = pow(2,32);
    printf("%f",f);
} 