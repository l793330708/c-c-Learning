#include <stdio.h>
#include <stdlib.h>
int main()
{
    void Fpread();
  Fpread(5);
}
void GetChar(FILE *fp)
{
    while(!feof(fp))
    {
        printf("%c",fgetc(fp));
    }
    
}
void Exmp10_1()
{
    FILE *fp;
    if((fp = fopen("1.txt","w+"))==NULL)
    {
        exit(0); //需要引入stdlib.c
    };
    char ch;
    scanf("%c",&ch);
    while(ch!='#')
    {
        fputc(ch,fp);
        scanf("%c",&ch);
        
    }
}
void Exmp10_2()
{
    FILE *fp1,*fp2;
    if((fp1= fopen("1.txt","r"))==NULL)
    {
        printf("Unable to read");
        exit(0);
    }
    if((fp2= fopen("2.txt","w"))==NULL)
    {
        printf("Unable to write");
        exit(0);
    }
    //将fp1的内容复制到fp2
    char c1;
    while(!feof(fp1))
    {
        c1 = fgetc(fp1);
        fputc(c1,fp2);
    }
    fclose(fp1);
    fclose(fp2);

}
void test_01()
{
   struct student
   {
       char name[10];
       int num;
       int age;
       char addr[30];
   }stud[5];
   for(int i=0;i<5;i++)
   {
       scanf("%s%d%d%s",stud[i].name,&stud[i].num,&stud[i].age,stud[i].addr);
   }
   FILE *fp;
   if((fp = fopen("1.txt","wb+"))==NULL)
   {
       printf("file could not open");
       exit(0);
   }
   for(int i=0;i<5;i++)
   {
       fwrite(&stud[i],sizeof(struct student),1,fp);
   }
   fclose(fp);
   
}
void Fpread(int size)
{
    struct student
   {
       char name[10];
       int num;
       int age;
       char addr[30];
   }stud[5];
    FILE *fp;
    if((fp = fopen("1.txt","rb+"))==NULL)
   {
       printf("file could not open");
       exit(0);
   }
   
    for(int i=0;i<size;i+=2)
    {
        printf("%d  ",ftell(fp));
        fread(&stud[i],sizeof(struct student),1,fp);
        fseek(fp,sizeof(struct student),1);
       
        printf("%s %d %d %s\n",stud[i].name,stud[i].num,stud[i].age,stud[i].addr);
    }
    fclose(fp);
}