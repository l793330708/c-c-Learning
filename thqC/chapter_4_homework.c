#include <stdio.h>
#include <math.h>
int main()
{
    void Exmp_1();
    void Exmp_2();
    void Exmp_3();
    void Exmp_4();
    void Exmp_5();
    Exmp_3();
}
/* 4.5 */
void Exmp_1()
{
    int a,b,c;
    scanf("a=%d,b=%d,c=%d",&a,&b,&c);
    if(a<b)
    {
        a = b;
    }
    if(a<c)
    {
        a = c;
    }
    printf("the max num is %d",a);
    return;
}
/* 4.6 */
void Exmp_2()
{
    int score;
    int grade;
    scanf("score=%d",&score);
    grade = score/10;
    switch (grade)
    {
    case 10:
    case 9:
        printf("A");
        break;
    case 8:
        printf("B");
        break;
    case 7:
        printf("C");
        break;
    case 6:
        printf("D");
        break;
    default:
        printf("E");
        
    }
    
    return;
}
/* 4.7 */
void Exmp_3()
{
    int num;
    scanf("%d",&num);
    int bit=0;
    while(num>0)
    {
        int temp=num%10;
        printf("%d\t",temp);
        num/=10;
        bit++;
    }
    printf("num has %d bit",bit);
    return;
}
/* 4.8 */
void Exmp_4()
{
    float profit,bonus;
    scanf("%f",&profit);
    // if(profit<=100000)
    // {
    //     bonus = profit/10;
    // }else
    // {
    //     if(profit<=200000)
    //     {
    //         bonus = 100000/10+(profit-100000)*0.075;
    //     }else if(profit<=400000)
    //     {
           
    //     }else if(profit<=600000)
    //     {

    //     }else if(profit<=1000000)
    //     {

    //     }else
    //     {
            
    //     }
        
    // }
    int level = profit/100000;
    switch (level)
    {
    case 0:
        bonus = profit*0.1;
    case 1:
        bonus = 10000+(profit-100000)*0.075;
        break;
    
    default:
        break;
    }
    return;
}
/* 4.9 */
void Exmp_5()
{
    
}
