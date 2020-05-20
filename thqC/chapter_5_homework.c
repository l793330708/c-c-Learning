#include <stdio.h>
#include <math.h>
int main()
{
    void Exmp_1();
    void Exmp_2();
    void Exmp_3();
    void Exmp_4();
    void Exmp_5();
    Exmp_2();
}
/* 5.1 */
void Exmp_1()
{
    for(int j=10;j<=20;j++)
    {
        int i=2;
        for(;i<=sqrt(j);i++)
        {
            if(j%i==0)
            {
                break;
            }
            
        }
        if(i==(int)sqrt(j)+1)
        {
            printf("%d is prime num\n",j);
        }
        
    }
        
    return;
}
/* 5.2 */
void Exmp_2()
{
    char a;
    int letter=0,space=0,num=0,other=0;
    while((a = getchar())!='\n')
    {
        int paradigm;
        if(a>='A'&&a<='z')
        {
            paradigm = 1; //英文字母
        }else if(a==32)
        {
            paradigm = 2; //空格
        }else if(a>=48&&a<=57)
        {
            paradigm =3; //数字
        }else
        {
            paradigm =4; //其他字符
        }
        
        
    switch (paradigm)
    {
    case 1:
        letter++;
        break;
    case 2:
        space++;
        break;
    case 3:
        num++;
        break;
    case 4:
        other++;
    default:
        break;
    }
    
    
    }
    printf("there are %d letters\n",letter);
    printf("there are %d nums\n",num);
    printf("there are %d space\n",space);
    printf("there are %d letters",other);
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
