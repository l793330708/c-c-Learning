#include <stdio.h>
#include <stdbool.h>
#define MAX 65537
int i,j,n,u,T,max,tp,map[103][103],d[103],sumcost;
bool s[103];
void prim()
{
    for(i=1;i<=n;i++)
    {
        d[i] = map[1][i]; //默认从点1开始 赋值最近数组值
        s[i] = false; //默认未被访问
    }
    s[1] = true ; //将点1加入已选点集合
    for(j =2;j<=n;j++)
    {
        tp = MAX,u=1;
        for(int i=2;i<=n;i++) //寻找目前边集合最小边
        {
            if(!s[i]&&d[i]<tp)
            {
                tp = d[i];
                u = i;
            }
        }
        sumcost += d[u]; //计算添加权值
        s[u] = true;
        printf("put %d in array\n",u);
        for(i=1;i<=n;i++)
        {
            if(!s[i]&& map[u][i] <d[i])
             d[i] = map[u][i]; //更新邻接边最小值
        }
    }
}
int main()
{
    
        scanf("%d",&n);//输入多少个点
        for(i=1;i<=n;i++)
         for(j=1;j<=n;j++)
            scanf("%d",&map[i][j]); //初始化边值
        prim();//prim算法
        printf("%d",sumcost);
    
    return 0;
}
