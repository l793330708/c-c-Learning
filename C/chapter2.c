#include<stdio.h>
#include<math.h>

void main(){
    void ChickRabbit(); //鸡兔同笼
    void countLoan(int d,int p ,double r); //分级付款计算
    //countLoan(324500,3245,0.008);
    void printCharsToLower(char s);
    void print8_16();
    void printSize();
    // int a;
    // double b;
    // float c;
    // printf("%d \n",sizeof(a));
    // printf("%d  \n",sizeof(b));
    // printf("%d",sizeof(c));
    // printCharsToLower('Z');
    // printf("%c",200);
    printSize();
}
void ChickRabbit()
{
    int x,y,head,foot;
    head = 16;
    foot = 40;
    y = (foot - 2 * head )/2;
    x = head - y;
    printf("兔子有%d,鸡有%d",y,x);
}
void countLoan(int d,int p ,double r)
{
     double m;
    m = (log10(p)-log10(p-d*r))/log10(1+r);
    printf("month=%f\n",m);
    printf("total=%f\n",m*p);
}
void printCharsToLower(char a)
{
    if(a<=97 && a>=65)
    {
        a = a+32;
    }
    printf("%c",a) ;
}
void print8_16()
{
    char c = 's';
    //'\101' = 1+64 = 65 8进制
    //'\x41' = 16*4 + 1 = 65 16进制
    // 计算机中0开头的为8进制，0x为16进制
    printf("%c",'\101');
    printf("%c",'\x41');
    printf("\n%c",c);
    printf("\n%c",0111);
    
}
void printSize()
{
    //默认在字符串后添加 \0 标示字符串结束
    printf("%d","CHINA");
    //默认为signed符号
    unsigned int a;
    signed int b;
    int c;
    printf("%f,%d,%d",sizeof(a),sizeof(b),sizeof(c));
    printf("\n%d,%d,%d",sizeof(int),sizeof(long),sizeof(short));
    //后面加u代表unsigned int
    printf("\n%d",sizeof(111u));
    //后面加l,L代表Long int
    printf("\n%d",sizeof(111L));
}
