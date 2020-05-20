
void main()
{
    void f(int n);
      f(5);
}
void f(int n)
{ 
    int i=0,j=0,k=0,sum= 0;
for(i=1; i<n+1;i++)
{for(j=n;j>i-1; j--)
for(k=1;k<j+1;k++ ){
    sum++;
    printf("sum=%d\t",sum);}
printf("sum=%d\n",sum);
}

}