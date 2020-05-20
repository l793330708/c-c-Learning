#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int sum= 0;
int main()
{
     void Split(unsigned short a,unsigned short *pOdd,unsigned short *pEven);
     void Match();
     void UpperStr(char *p);
     void hitTarget(int round,int score);
     void prim();
     void Kruscal();
    // int x =0210; //0开头的是八进制 
    // int y =0x11; //0x是16进制 17
    // printf("%d,%d\n",x,y);
    // int a[3][3],*p,i;
    // p = &a[0][0];
    // for(i=0;i<9;i++)
    // {
    //     *(p+i) = i;
    // }
    // for(i = 0;i<3;i++)
    // {
    //     i!=1 ? printf("%d %d ",a,*a[2-i]):printf("%d ",a);
    // }
    // unsigned short *pOdd = (unsigned short*)malloc(sizeof(unsigned short));
    //  unsigned short *pEven = (unsigned short*)malloc(sizeof(unsigned short));
    // unsigned short a = 13851u;
    // Split(a,pOdd,pEven);                                                                 
    // char str[] = "my Name is Lei";
    // UpperStr(str);
    // hitTarget(3,21);
    // printf("%d",sum);
    Kruscal();
    return 0;
}
//递归求学生年龄
int age(int order)
{
    if(order==1)return 10;
    else{
        return age(order-1)+2;
    }
}
//对一个无符号短整型数取偶数位与奇数为分别组成新的无符号段整形数,巧用atoi,itoa函数
    void Split(unsigned short a,unsigned short *pOdd,unsigned short *pEven)
    {
        char nums[20];
        itoa(a,nums,10); //10表示十进制转换
        char nums_odd[10];
        char nums_even[10];
        int order_1=0,order_2=0;
        for(int i=0;i<strlen(nums);i++)
        {
            if(i%2==0)
            {
                nums_even[order_1++] = nums[i];
            }else{
                nums_odd[order_2++] = nums[i];
            }
        }
        *pOdd = atoi(nums_odd);
        *pEven = atoi(nums_even);
    }
//两队比赛问题 甲队a,b,c，乙队x,y,z
    void Match()
    {
        char a,b,c;
        for(char opp = 'x';opp<='z';opp++)
        {
            if(opp!='x'&&opp!='z')
            {
                c = opp;
            }
        }
        for(char opp = 'x';opp<='z';opp++)
        {
            if(opp!='x'&&opp!=c)
            {
                a = opp;
            }
        }
        for(char opp = 'x';opp<='z';opp++)
        {
            if(opp!=a&&opp!=c)
            {
                b = opp;
            }
        }
        printf("a's opp is %c\n",a);
        printf("b's opp is %c\n",b);
        printf("c's opp is %c\n",c);
    }
//大写每个单词最后的字母
    void UpperStr(char *p)
    {
        char *p1,*p2;
        p1 = p;
        p2 = p;
        
        while(*p2!=0)
        {
            p1 = p2;
            p2++;
            if(*p2==' ')
            {
                *p1-=32; //转换成小写
            }
        }
        if(*p1>='a'&& *p1<='z')
        {
            *p1 -=32; //将最后一个大写
        }
        
    }
//运动员打靶10次，最后打中90环的所有可能情况
    int count[11]={0};
    void hitTarget(int round,int score)
    {
        
        if(score == 0 && round >=0)
        {
            sum++;
            for(int i=1;i<=3;i++)
            {
                printf("round %d hit %d\n",i,count[i]);
            }
            printf("-----------\n");
        }else if(score <0 || round <1 || round *10<score)
        {
            return;
        }else{
            for(int i=0;i<=10;i++)
            {
                count[round] = i;
                hitTarget(round-1,score-i);
            }
        }
    }
//最小生成树
    typedef struct  
    {
        int from,to;
        long cost;
    }Edge;
    int father[3];
    void Kruscal()
    {
        int find(int x);
        Edge edges[3];
        printf("please input edge detail:\n");
        for(int i=0;i<3;i++)
        {
            scanf("%d,%d,%d",&edges[i].from,&edges[i].to,&edges[i].cost); //初始化边集
        }
        
        for(int i=0;i<3;i++)
        {
            father[i] = i; //初始化父集合
        }
        int tmp;
        Edge tmps;
        for(int i=0;i<3;i++)
        {
            tmp = i;
            for(int j=i+1;j<3;j++)
            {
                if(edges[tmp].cost > edges[j].cost)
                {
                    tmp = j;
                }
            }
            tmps = edges[tmp];
            edges[tmp] = edges[i];
            edges[i] = tmps;
        } //排序边
        long weightsum =0;
        for(int i=0;i<3;i++)
        {
            if(find(edges[i].from) != find(edges[i].to))
            {
                weightsum += edges[i].cost; //添加权值
                father[edges[i].from] = edges[i].to; //归入并查集
            }
        }
        printf("%ld",weightsum);
    }
    int find(int x) //寻找父亲
    {
        if(father[x] == x)return x;
        else
        {
            return find(father[x]);
        }
    }