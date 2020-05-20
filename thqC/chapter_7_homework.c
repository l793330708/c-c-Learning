#include <stdio.h>
#include <math.h>
int main()
{
    void Exmp_1();
    void Exmp_2();
    void Exmp_3();
    void Exmp_4();
    void Exmp_5();
    Exmp_1();
}
/* 3.3 */
void Exmp_1()
{
    char str[]="hello";
    char str2[6];
    str2=str;
    
    return;
}
/* 3.4 */
void Exmp_2()
{
    int a,b;
    char c1,c2;
    float x,y,z;
    // scanf("%5d%5d%c%c%f%f% * f,%f",&a,&b,&c1,&c2,&x,&y,&z);
    scanf("%f%f",&x,&y);
    return;
}
/* 3.5 */
void Exmp_3()
{
    double r=1.5;
    int h=3;
    double round = 2 * acos(-1) * r;
    double s =  round *h;
    return;
}
/* 3.6 */
void Exmp_4()
{
    int ftemp;
    float c;
    printf("请输入华氏温度：");
    scanf("%d",&ftemp);
    printf("c=%3.1f",c = 5.0/9*(ftemp-32));
    return;
}
/* 3.7 */
void Exmp_5()
{
    char c1,c2;
    int i1,i2;
    c1 = getchar();
    c2 = getchar();
    putchar(c1);
    putchar('\n');
    putchar(c2);
}
