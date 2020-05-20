#include <stdio.h>

int main()
{
    void cut(char *in,char *out,int n);
    int hanoi(int n,char x,char y,char z);
    // int x=0,y,z,w;
    // z=(x)?(y=-2,y+=x+5):(x=7,y=3);// 执行x=-1
    // w = 'A'+y; //w=D ,68
    // printf("%d,%d,%d,%c\n",x,y,z,w); //7,3,-1,D
    // char ch[105]="E:\\in.txt";
    // char och[105]="E:\\out.txt";
    // cut(ch,och,1);
    char x='x',y='y',z='z';
    printf("contain %d steps for moving",hanoi(3,x,y,z));
    
   return 1;
}
//重定向输出流，复制文件
void cut(char *in,char *out,int n)
{
    freopen(in,"r",stdin);
    freopen(out,"w",stdout);
    char s[1005];
     while(n--)
    {
        gets(s);
        printf("%s\n",s); //将流重定向输入到out文件中，并不在终端打印
    }
}
//hanoi塔
int hanoi(int n,char x,char y,char z)
{
    static int count=0;
    if(n==1)
    {
        printf("%c --> %c\n",x,z);
        count++;
    }else
    {
        hanoi(n-1,x,z,y); //将n-1个从x->y 借助z
        printf("%c -->%c\n",x,z);
        count++;
        hanoi(n-1,y,x,z); //将n-1 从y->z 借助x
    }
    return count;
    
}

