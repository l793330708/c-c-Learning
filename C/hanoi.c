#include <stdio.h>

int main()
{
    void hanoi(int n,char x,char y,char z);
    int m;
    printf("input the number of disks:");
    scanf("%d",&m);
    printf("The step to moving %d disks :\n",m);
    hanoi(m,'A','B','C');
    return 0;
}
//hanoi(n,x,y,z)表示将N个盘子从x->z借助y的过程
void hanoi(int n,char x,char y,char z)
{
    void move(char,char);
    if(n==1)move(x,z);
    else{
        hanoi(n-1,x,z,y);
        move(x,z);
        hanoi(n-1,y,x,z);
    }
}
void move(char a,char b)
{
    printf("%c-->%c\n",a,b);
}