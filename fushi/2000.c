#include <stdio.h>
#include <stdlib.h>
int main()
{
    void read();
    void Exmp_1();
    // read();
    char str[3] ={'a','b','c'};
    printf("%s",str);
    return 0;
}
//program read
void read()
{
    struct m{
        int x;
        int *y;
    }*p;
    int a[4]={12,33,-40,100};
    struct m b[4]={10,a+2,9,a+3,8,a,7,a+1};
    p = b;
    printf("%d\n",++p->x); //11 ->指向运算符优先级更高
    printf("%d\n",(++p)->x); //9
    printf("%d\n",++(*p->y)); //101
    
}
//program design
void Exmp_1()
{
    FILE *fp1,*fp2,*fp3;
    if((fp1 = fopen("1.txt","rb+"))==NULL)
    {
        printf("file 1 could not open");
        exit(0);
    };
    if((fp2 = fopen("1.txt","rb+"))==NULL)
    {
        printf("file 2 could not open");
        exit(0);
    };
    if((fp3 = fopen("1.txt","rb+"))==NULL)
    {
        printf("file 3 could not open");
        exit(0);
    }
    char ch;
    while(!feof(fp1))
    {
        ch = fgetc(fp1);
        putchar(ch);
        putchar(10);
        fputc(ch,fp3);
        if(!feof(fp2))
        {
            ch = fgetc(fp2);
            putchar(ch);
            putchar(10);
            fputc(ch,fp3);
        }
    }
    while(!feof(fp2))
    {
        ch = fgetc(fp2);
        putchar(ch);
        putchar(10);
        fputc(ch,fp3);
    }
    rewind(fp1);
    rewind(fp3);
    while(!feof(fp3))
    {
        ch = fgetc(fp3);
        putchar(ch);
        putchar(10);
        fputc(ch,fp1);
    }
    rewind(fp1);
    while(!feof(fp1))
    {
        putchar(fgetc(fp1));
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}