#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main()
{
    double money(double q);
    void my_strncpy(char *str,int offfset);
    void linkListRev();
    void cubeSum();
    int a,b;
    while(scanf("%d%d",&a,&b)==2)
    {
        printf("h");
    }
    // my_strncpy("Hello my friend",5);
    // printf("%7.2f",money(5,0.01));
    return 0;
}
//水仙花数 自身等于各位的三次方之和
    void waterFlowerNum()
    {
        for(int i=100;i<999;i++)
        {

            int nums[3],count = 2,p = i;
            while(p>0)
            {
                nums[count--] = p%10;
                p/=10;
            }
            int sum=0;
            for(int j=0;j<3;j++){
                sum+=pow(nums[j],3);
            }
            if(sum == i)
            {
                printf("%d\n",i);
            }

        }
    }
//利息问题 每年取1000，利率为q，递推
    double money(double q)
    {
        // //第五年刚好取完，每年取1000，有递推式 money(year) = money(year-1)*(1+p)-1000
        // //于是money(year-1) = (money(year)+1000)/(1+p)
        // double money=0;
        // for(int i=0;i<year;i++)
        // {
        //     money = (money+1000)/(1+p);
        // }
        // return money;
        //第五年的金额是第四年存的钱 money(4)*(1+p)
        double money[6];
        money[5] = 0;
        for(int i=5;i>=1;i--)
        {
            money[i-1] = (money[i]+1000) / (1+q);
        }
        printf("%f",money[1]);
    }
//链表逆序
    void linkListRev()
    {

        struct node
        {
            int val;
            struct node* next;
        }*head,*p;
        head = p = (struct node*)malloc(sizeof(struct node));
        head ->val = 0;
        head->next = NULL;
        for(int i=1;i<5;i++)
        {
            p->next = (struct node*)malloc(sizeof(struct node));
            p = p->next;
            p->val = i;
            p->next = NULL;
        }
        p = head;
        while(p)
        {
            printf("%d ",p->val);
            p = p->next;
        }
        //头插逆置
        struct node* temp;
        p = head->next;
        head->next =NULL;
        while(p)
        {
            temp = p->next;
            p->next = head->next;
            head->next = p;
            p = temp;
        }
    }
//二维数组鞍点 行上最大，列上最小
    void num(int m,int n)
    {
        int a[m][n];
        for(int i=0;i<m;m++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]); //输入数组
            }
        }
    
        int col=0;
        for(int i=0;i<m;i++)
        {
            int max = a[i][0];
            int col = 0;
            for(int j=0;j<n;j++)
            {
                if(a[i][j]>max)
                {
                    max = a[i][j];
                    col = j;
                }
            }
            int min = max;
            int flag=0;
            for(int j=0;j<n;j++)
            {
                if(a[j][col]<min)
                {
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                printf("%d",min);
                break;
            }
        }
    }   
//字符数组的赋值
    void my_strncpy(char *str,int offfset)
    {
        char str1[20]={0};
        char *p = str;
        p+=offfset;
        int len = strlen(str)-offfset;
        strncpy(str1,p,len);
        printf("%s",str1);
    }
//将输入的8个数放在立方体顶点 ，unfinished
    void cubeSum()
    {
        int nums[8];
        for(int i=0;i<8;i++)
        {
            scanf("%d ",&nums[i]);
        }
        int sum=0;
        for(int i=0;i<4;i++)
        {
            sum+= nums[i];
        }
        printf("%d ",sum); //顶
        for(int i=4,sum=0;i<8;i++)
        {
            sum+= nums[i]; 
        }
        printf("%d",sum); //底
        
    }
//九宫格问题 行列对角线值都为一样
#define SUM 15
void nine_Rec()
{
    int rec[3][3];
    memset(rec,0,sizeof(rec));
    for(int i=0;i<10;i++)
    {
        for(int j=SUM-i-5;j<10;j++)
        {
            if(i!=j&& i!= 5 && j!=5)
        }
    }
}

