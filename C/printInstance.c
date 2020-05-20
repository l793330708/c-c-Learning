/*
指针变量指向数组元素
指针变量指向数组

*/

#include <stdio.h>
void main()
{
  // static  int a =1;
    int nums[3][3];
    //普通指针
    int *p;
    p =nums;
    //行指针 注意区分*p[3]为指针数组
    int (*p1)[3];
    p1 = nums;
    printf("*p = %d\n",*++p);
    printf("*p1 = %d\n",&p1);
    nums[0][0]= 1;
    nums[1][1]= 2;
    nums[1][0] =3;
    for(int i=0;i<3;i++)
    {
     for(int j=0;j<3;j++)
     {
       printf("nums[%d][%d]=%d\t",i,j,nums[i][j]);
       
     }
     printf("\n");
     }
    
    // for (int i = 0; i < 3; i++)
    // {
    //   printf("\n%ld nums[%d] value = %d" ,&nums[i],i,nums[i]);
    // }
    // printf("\n--------------");
    // for(int i;i <= 3;p++,p1++,i++){
    //    printf("\np=%d",p);
    //   printf("\np1=%d",p1);
    // }
    
    
}