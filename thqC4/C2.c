#include <stdio.h>
int main()
{
    // double countSum();
    // printf("%f",countSum());
    void printStr(char *p);
    char str[] = "abcd";
    printStr(str);
    return 0;
}
/*
    计算S = 1-1/2+1/3-1/4...+1/99-1/100
    */
double countSum()
{
    double sum =0;
    int sign = 1;
    for(int i=1;i<=100;i++)
    {
        sum += (sign*1.0/i);
        sign*=-1;
    }
    return sum;
}