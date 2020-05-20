#include<stdio.h>
#include<math.h>
void main()
{
    void calInterst();
   void encryptChar();
   void ponderous();
   ponderous();
}
void calRatio(int year)
{
    double r,P;
    r = 0.1;
    P = pow(1+r,year);
    printf("%f",P);
}
void calInterst()
{
    int origin = 1000;
    double r1 = 0.0414,r2 = 0.0468 , r3 = 0.054, r4 =0.0585 , r5 = 0.0072,end,end1,end2;
    end=1000*(1+r4);
    end1 = 1000*pow(1+r1,5);
    printf("%f,%f,%f",end,end1,end2);
}
void encryptChar()
{
    char c1[] = "China";
    for(int i=0;i<5;i++)
    {
        c1[i] = c1[i] + 4;
        printf("%c",c1[i]);
    }
    
    //向后推4个
}
void ponderous()
{
    int c1,c2;
    c1=197;
    c2=198;
    printf("%c %c\n",c1,c2);
    printf("%d %d\n",c1,c2);
    
}