#include <stdio.h>
#include <string.h>
/**
 * 2012上午c 字符串循环移动，求最大相同连续字串
 * 下午专业综合 dijkstra最短路径，小顶堆，读HTML+专业英语翻译
 **/
int main()
{
    void maxEqualstr(char str1[],char str2[]);
    void create(int nums[],int size);
    void printMinHeap(int nums[],int num);
    void strMove_1(char str[],int offset);
    void create_dui(int dui[],int K);
    void UpToDonw(int dui[],int i,int K);
    int nums[10]={0};
    int i,tmp,n,K;
    scanf("%d%d",&n,&K);
    {
        for(i = 1;i<=K;i++)
            scanf("%d",&nums[i]);
        create_dui(nums,K);
        for(i = K+1;i<=n;i++)
        {
            scanf("%d",&tmp);
            if(tmp>nums[1])
            {
                nums[1] = tmp;
                UpToDonw(nums,1,K);
            }
        }
    }
    for(int i=1;i<=K;i++)printf("%d ",nums[i]);
    // create(nums,8);
    // for(int i=1;i<=8;i++)
    // {
    //     printf("%d\t",nums[i]);
    // }
    // printf("\n");
    // printMinHeap(nums,8);
    // strMove_1("abcdefg",4);
        return 0;
}
//字符串循环移动,offset移动量
    void strMove(char str[],int offset)
    {
        char *p,*pivot;
        p = pivot = str;
        int len = strlen(str);
        int reoff;
        if(offset>=len)
        {
            reoff = offset %len;
            
        }else
        {
            reoff = offset;
        }
        for(int i=reoff;i<len;i++)
        {
            printf("%c",str[i]); //
        }
        for(int i=0;i<reoff;i++)
        {
            printf("%c",str[i]);
        }
    }
    void strMove_1(char str[],int offset)
    {
        int len = strlen(str);
        offset = offset%len;
        char prestr[len],laststr[len];
        char *p = str;
        p = str+offset;
        strcpy(prestr,p);
        strncpy(laststr,str,offset);
        strcat(prestr,laststr);
        printf("%s",prestr);
    }
//求最大相同连续字符串,str2比str1短
void maxEqualstr(char str1[],char str2[])
{
    int size1 = strlen(str1);
    int size2 = strlen(str2);
    char res[50] ={0},tmp[50]={0};
    int maxcount=0;
    for(int i=0;i<size1;i++)
    {
        int sti=i;
        int count =0;
        for(int j=0;j<size2;j++)
        {
            if(str2[j]==str1[sti])
            {
                tmp[count++] = str2[j];
                sti++;
            }else{
                tmp[count]=0;
                sti = i;
                if(count>maxcount)
                {
                    maxcount = count;
                    strcpy(res,tmp);
                }
                count = 0;
            }
            
        }
        if(count>maxcount)
        {
            maxcount = count;
            strcpy(res,tmp);
        }
    }
    printf("%s",res);
}
//构造小顶堆
void create(int nums[],int size)
{   
    int index = size/2;
    while(index>0)
    {
        int flag = 1;
        for(int j = index;j*2<=size&&flag==1;)
        {
            int ii= j*2;
            flag = 0;
            if(ii+1<size)
            {
                if(nums[ii]>nums[ii+1])
                {
                    ii = ii+1;
                }
            }
            if(nums[j]>nums[ii])
            {
                int swp = nums[j];
                nums[j] = nums[ii];
                nums[ii] = swp;
                j = ii;
                flag = 1;
            }
        }
        index--;
    }
}
//输出堆中前几个最小的数 大顶堆
void printMinHeap(int nums[],int num)
{
    void adjustHeap(int nums[],int size);
    for(int i=0;i<num;i++)
    {
        printf("%d",nums[1]);
        adjustHeap(nums,8-i);
    }
}
void adjustHeap(int nums[],int size)
{
    int temp = nums[1];
    nums[1] = nums[size];
    nums[size] = temp;
    int flag =1;
    
    int i =1;
    // while(flag && i*2<size)
    for(int i=1;flag && i*2<size;)
    {
        int ii = i*2;
        int tmp = ii;
        flag = 0;
        if(ii+1<size)
        {
            if(nums[ii]>nums[ii+1])
            {
                tmp = ii+1;
            }
        }
        if(nums[i]>nums[tmp])
        {
            int swp = nums[i];
            nums[i] = nums[tmp];
            nums[tmp] = swp;
            i = tmp;
            flag = 1;
        }

    }
}
//参考书元例子
void UpToDonw(int dui[],int i,int K)
{
    int t1,t2,tmp,pos;
    t1 = 2*i;
    t2 = t1+1;
    if(t1>K)
    {
        return;
    }else
    {
        if(t2>K)
            pos = t1;
        else
        {
            pos = dui[t1]>dui[t2]?t2:t1;
        }
        if(dui[i]>dui[pos])
        {
            tmp = dui[i];
            dui[i] = dui[pos];
            dui[pos] = tmp;
            UpToDonw(dui,pos,K);
        }   
    }
}
void create_dui(int dui[],int K)
{
    int i;
    int pos = K/2;
    for(i=pos;i>=1;i--)
        UpToDonw(dui,i,K);
}