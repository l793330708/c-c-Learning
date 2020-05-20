#include <stdio.h>
#include <string.h>
int main()
{
    int getNum(int a,int n);
    int getNum_rec(int a,int count,int n);
    int getPow(int num,int );
    int getPow_Rec(int num,int n);
    int getPow_Iter(int m,int n);
    void Josphy_getPerson(int per[],int gap_num,int size);
    void Josphy_getPerson_opm(int m,int n );
    void stridnexCpy(char *dst,char *res,int index);
    char dst[25];
    char res[23] = "I am a fucking genuis!";
    
    stridnexCpy(dst,res,3);
    printf("%s",dst);
    // int per[10];
    // for(int i=0;i<5;i++)
    // {
    //     per[i] = 1;
    // }
    // Josphy_getPerson(per,2,5);
    // Josphy_getPerson_opm(2,5);
    // printf("%d",getPow_Iter(2,16));
    // printf("%d\n",getNum_rec(2,3,3));
    // printf("%d\n",getNum(2,3));
    return 0;
}
//计算 s = a + aa +aaa + a^n 的和，递推方法
int getNum(int a,int n)
{
    int sum= 0;
    int tmp = a;
    for(int i=0;i<n;i++)
    {
        sum += a;
        a*=10;
        a+=tmp;
    }
    return sum;
}
//递归
int getNum_rec(int a,int count,int n)
{
    if(count == 1)
    {
        return a;
    }else{
        int tmp = a;
        for(int i = 1;i<count;i++)
        {
            tmp = tmp*10+a;
        }
        return getNum_rec(a,count-1,n)+tmp;
    }
}
//优化m^n 的算法，使乘法次数尽可能小,快速幂（二分算幂）
int getPow(int num,int n)
{
    if(n == 1)return num;
    else{
        return getPow(num,n-1)*num;
    }
}
int getPow_Rec(int num,int n)
{
    if(n == 0)
    {
        return 1;
    }else if(n == 1)
    {
        return num;
    }else{
        if(n&1)
        {
            return getPow_Rec(num,n-1)*num;//奇数
        }else
        {
            n>>=1;
            return getPow_Rec(num,n)*getPow_Rec(num,n);
        }
        
    }
}
//快速幂迭代
int getPow_Iter(int m,int n)
{
    int res =1,ori =m;
    while(n)
    {
        if(n&1)res = res*ori; //当n为奇数，先乘一次基数 m
        n>>=1;
        ori = ori *ori;
    }
    printf("%d\n",res);
    return res;
}
//约瑟夫报数问题 普通
void Josphy_getPerson(int per[],int gap_num,int size)
{

    int i = 0 ;
    int j;
    for(int c=0;c<size-1;c++)
    {
        int count = gap_num;
        j = i;
        while(count)
        {
            if(per[j]!=0)count--;
            j++;
            if(j == size)
            {
                j = 0;
            }
        }
        per[j] = 0 ;//出局
       i = ++j % size;
    }
    i = 0;
    while(per[i++]==0);
    printf("%d",i);
}
//优化版递推约瑟夫环，最后获胜,子问题推导 ,m是间隔数，n为多少人
void Josphy_getPerson_opm(int m,int n )
{
    int no =0;
    for(int i=2;i<=n;i++)
    {
        no = (no + m)%i;
    }
    printf("the winner is %d",no);
}
//字符串定向复制位置
void stridnexCpy(char *dst,char *res,int index)
{
    int length = strlen(res);
    if(length<index)
    {
        return;
    }
    char *p = res;
    while(index--)
    {
        p++;
    }
    strcpy(dst,p);
}