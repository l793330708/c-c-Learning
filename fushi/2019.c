#include <stdio.h>
#include <math.h>
int main()
{
    // int a,b,d=10;
    // a = d | 1% 9 ,b= d&-1; //模运算>位运算>赋值运算>逗号运算
    // printf("%d,%d",a,b);
    // int a[3][3];
    // int *p = a;
    // for(int i=0;i<9;i++)
    // {
    //     p[i] = i+1;
    // }
    // for(int i=0;i<3;i++)
    // {
    //     printf("%d",a[2][i]);
    // }
    // int (*q)[3] = a;
    // printf("\n%d,%d,%d",**q,**(q+1),**(q+2));
    void dotSearch();
    int MinusNum();
    void Champion();
    // Champion();
    dotSearch();
    return 0;
}
//求组成新的最大最小四位数的差
int MinusNum()
{
    unsigned num1,num2;
    scanf("%4d,%4d",&num1,&num2);
    int nums[4]={0},index=0;
    while(num1>0)
    {
        nums[index++] = num1%10;
        num1/=10;
    }
    for(int i=0;i<4;i++)
    {
        int pivot = i;
        for(int j=i+1;j<4;j++)
        {
            if(nums[pivot]<nums[j])
            {
                pivot = j;
            }
        }
        int temp = nums[pivot];
        nums[pivot] = nums[i];
        nums[i] = temp; //获得递减数组 选择排序
    }
    int nums1[4]={0};
    index=0;
    while(num2>0)
    {
        nums1[index++] = num2%10;
        num2/=10;
    }
    for(int i=0;i<4;i++)
    {
        int flag=0;
        for(int j=i;j<3;j++)
        {
            if(nums1[j]<nums1[j+1])
            {
                flag = 1;
                int temp = nums1[j];
                nums1[j] = nums1[j+1];
                nums1[j+1] = temp; 
            }
        }
        if(!flag)
        {
            break;
        }
    }
    for(int i=0;i<4;i++)
    {
        num1 += (nums[i]*pow(10,3-i));
        num2 += (nums1[i]*pow(10,3-i));
    }
    return abs(num2-num1);
}
//比赛问题
void Champion()
{
    char A;
    char B;
    char C;
    char str;
    for(str = 'X';str<='Z';str++)
    {
        if(str!='X'&&str!='Z')
        {
            C = str;
        }
    } //C的对手
    for(str = 'X';str<='Z';str++)
    {
        if(str!='X'&&str!=C)
        {
            A = str;
        }
    }//A的对手
    for(str = 'X';str<='Z';str++)
    {
        if(str!=A&&str!=C)
        {
            B = str;
        }
    }
    printf("A's enemy is %c\n",A);
    printf("B's enemy is %c\n",B);
    printf("C's enemy is %c\n",C);
}
/*
    二维数组鞍点问题，行上最大，列上最小 ：First:横向搜索（最大），Then:竖向搜索最小
    */
void dotSearch()
{
    int i,j,k,max,min;
    int array[3][4];
    printf("please input Array Elements:\n");
    for(i = 0;i<3;i++)
    {
        for(j = 0;j<4;j++)
        {
            scanf("%d",&array[i][j]);
        }
    }
    printf("the array:\n");
    for(i = 0;i<3;i++)
    {
        for(j = 0;j<4;j++)
        {
            printf("%-5d\t",array[i][j]);
            
        }
        printf("\n");
    }
    for(i = 0;i<3;i++)
    {
        max = array[i][0]; 
        for(j =0;j<4;j++)
        {
            if(max<array[i][j])
            {
                max = array[i][j]; 
                k = j; //记录当前行的最大的列下标 
            }
        }
        min = array[0][k];
        for(j = 0;j<3;j++)
        {
            if(min >array[i][k])
            {
                min = array[i][k];
            }
        }
        if(min == max )
        {
            printf("coordinate is array[%d][%d]--%d ",i,k,max);
        }
    }
}
/*
    莱文斯坦；字符串编辑距离，即动态规划中状态方程的确定
    */
