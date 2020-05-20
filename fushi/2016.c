#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int sum=0;
int main()
{   
    void sortArr(int arr[],int size);
    void search(int curRow);
    void revStrprint();
    void initiallA();
    void anlyticTxt(char ch ,char *frs,char *fdst);
    void reDirectTxt(char *frs);
    // revStrprint();
    // initiallA();
    // int arr[] ={4,3,2,6,7,1};
    // sortArr(arr,6);
    // search(0);
    // printf("%d",sum);
    // anlyticTxt('i',"E:\\vs_workspace\\C\\fushi\\analytic.txt","E:\\vs_workspace\\C\\fushi\\output.txt");
    reDirectTxt("E:\\vs_workspace\\C\\fushi\\analytic.txt");
    return 0;
}
/* 排列组合问题,A有n个，B有m个，组合成AB的字符串，有多少种
   思路：从m+n个位置选n个A
   */
int combinationA_B(int m,int n)
{
    int Fun(int a);
    return Fun(m+n) / (Fun(m)*Fun(n));
}
//该题辅助 阶乘    
int Fun(int a)
{
    int res=1;
    for(int i=1;i<=a;i++)
    {
        res*=i;
    }
    return res;
}
/*
    奇数偶数排序：输入一个整数序列，第一行输出奇数，第二行输出偶数。这运用了冒泡排序
    */
void sortArr(int arr[],int size)
{
     int tmp;
     int flag;
    // for(int i=0;i<size;i++)
    // {
    //     flag = 0;
    //     for(int j=0;j<size-i-1;j++)  //冒泡排序
    //     {
    //         if(arr[j]>arr[j+1])
    //         {
    //             tmp = arr[j];
    //             arr[j] = arr[j+1];
    //             arr[j+1] = tmp;
    //             flag = 1;
    //         }
    //     }
    //     if(!flag)
    //     {
    //         break;
    //     }
    // }
    for(int i=0;i<size;i++)
    {
        if(arr[i]%2==0)
        {
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
    for(int i=0;i<size;i++)
    {
        if(arr[i]%2)
        {
            printf("%d ",arr[i]);
        }
    }
}
/*
    八皇后问题：八个皇后在棋盘上互相不能攻击，回溯法
    */
int p[8];
void search(int curRow)
{
    
    int ok;
    if(curRow==8)
    {   
        sum++;
        return;
    }else{
        for(int i = 0;i<8;i++)
        {
           ok = 1;
           p[curRow] = i;
           for(int j=0;j<curRow;j++)
           {
               if(p[curRow]==p[j]||abs(p[curRow]-p[j])==abs(curRow-j))
               {
                   ok = 0;
                   break;
               }
               
           }
           if(ok)
           {
               search(curRow+1);
           }
        }
    }
}
/*
    递归逆向打印字符串
    */
void revStrprint()
{
    char c ;
    if((c = getchar()) != '\n')
    {
        revStrprint();
    }
    if(c!='\n')
    {
        putchar(c);
    }
}
/*
    Dijkstra最短路径
    */
   int dis[105];  //存储最短距离
   int A[105][105]; //无向图边的权值
   int n; //n个顶点
   void initiallA()
   {
       void Dijkstra(int v0);
       int m,a,b,s;
       while(scanf("%d%d",&n,&m)==2) // n顶点数，m为边数
       {
           for(int i =1;i<=n;i++)
           {
               for(int j =1;j<=n;j++)
               {
                   if(i==j)A[i][j] = A[j][i] = 0;
                   else A[i][j] = A[j][i] = 1e10;
               }
           }
           for(int i =0;i<m;i++)
           {
               scanf("%d%d%d",&a,&b,&s);
               A[a][b]= A[b][a] = s; //键入边权值
           }
           Dijkstra(1);
           for(int i=1;i<=n;i++)
           {
               printf("%d",dis[i]); //输出最短路径
           }
           printf("\n");
       }
   }
   void Dijkstra(int v0)
   {
       int s[105];
       memset(s,0,sizeof(s));
       for(int i=1;i<=n;i++)
       {
           dis[i] = A[v0][i]; //初始化距离
           s[i] = 0;      //默认都没有加入边值集合
       }
       s[v0] = 1;
       dis[v0] = 0;
       for(int i=2;i<=n;i++)
       {
           int mindis = 1e9;
           int u = v0;
        for(int j=1;j<=n;j++)
        {
            if(!s[j]&&dis[j]<mindis) //选择法筛选
            {
                u = j;
                mindis = dis[j]; //选取可达且距离 v0 最近的点
            }
        }
        s[u] = 1;
        printf("selected is %d \n",u);
        for(int j=1;j<=n;j++)
        {
            if(!s[j]&&A[u][j]<dis[j])
            {
                if(A[u][j]+dis[u]<dis[j])
                {
                    dis[j] = dis[u]+A[u][j]; //将最短路径修正加入数组存储
                }
            }
        }
       }
   }
/*
    统计文件中字符个数输出到另一文件:analytic.txt output.txt
    ch 查询字符
    frs 查询文件
    fdst 输出文件位置
    */
void anlyticTxt(char ch ,char *frs,char *fdst)
{
    int count=0;
    FILE *fin  = fopen(frs,"r");
    if(!fin)
    {
        exit(0);
    }
    FILE *fout = freopen(fdst,"w",stdout);
    
    while(!feof(fin))
    {
        if(fgetc(fin)== ch)
        {
            count++;
        }
    }
    printf("%d",count);
    fclose(fin);
    fclose(fout);
}
/*
    输入流重定向成文件,frs,文件作为输入
    */
void reDirectTxt(char *frs)
{
    char str[20],*p;
    p = str;
    freopen(frs,"r",stdin); 
    while(scanf("%c",p)!=EOF) //重定向输入流，默认为 键盘，输出流默认为屏幕
    {
        p++;
    }
    fclose(stdin);
    *p = 0;
    printf("%s",str);
    
}