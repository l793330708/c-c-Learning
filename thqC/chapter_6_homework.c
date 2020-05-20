#include <stdio.h>
#include <math.h>
#include <malloc.h>
#define SIZE sizeof(struct months)
int main()
{
    void Exmp_1();
    void Exmp_2();
    void Exmp_3();
    void Exmp_4();
    void Exmp_5();
    Exmp_1();
}
/* 6.3 */
void Exmp_1()
{
    int stud[5][3];
    for(int i=0;i<5;i++)
        {
            int avg =0;
            for(int j=0;j<2;j++)
            {
                scanf("%d",&stud[i][j]);
                avg += stud[i][j];
            }
            avg/=2;
            stud[i][2]=avg; //求出该名学生的平均成绩
        }
    //选择排序
    for(int i=0;i<5;i++)
    {
        int index = i;
        for(int j=i+1;j<5;j++)
        {
            if(stud[index][2]<stud[j][2])
            {
                index = j;  //寻找当前平均分最高的学生
            }
        }
        int temp;
        for(int j=0;j<3;j++)
        {
            temp  =stud[i][j];
            stud[i][j] = stud[index][j];
            stud[index][j] = temp;
        }
    }
   
}
int num = 0;
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
