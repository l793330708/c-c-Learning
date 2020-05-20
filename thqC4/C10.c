#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    // char filename[10];
    // printf("please input filepath:");
    // scanf("%s",filename);
    // FILE *fp = fopen(filename,"r");
    // if(!fp)
    // {
    //     exit(0);
    // }
    // char ch;
    // // ch = getchar(); //接收回车符号
    
    // while(!feof(fp))
    // {
    //     putchar(fgetc(fp));
    // }
    // fclose(fp);
    void Diagram_103();
    void Diagram_104();
    // Diagram_103();
    // char str[10];
    Diagram_104();
    return 0;
}
void Diagram_103()
{
    FILE *fp;
    char str[3][10];
    char tmp[10];
    for(int i=0;i<3;i++)
        gets(str[i]);
    int index;
    for(int i=0;i<3;i++)
    {
        index = i;  
        for(int j=i+1;j<3;j++)
        {
            if(strcmp(str[index],str[j])>0)
            {
                index = j;
            }
        }
        strcpy(tmp,str[index]);
        strcpy(str[index],str[i]);
        strcpy(str[i],tmp);
    }
    for(int i=0;i<3;i++)
    {
        puts(str[i]);
    }    
        
    
}
void Diagram_104()
{
    typedef struct 
    {
        int no;
        char name[10];
    }Student,Students[5];
    Students stus;
    // for(int i=0;i<5;i++)
    // {
        
    //     stus[i].no = i;
    //     int j;
    //     for( j=0;j<i+1;j++)
    //     {
    //         stus[i].name[j] = '1';    
    //     }
    //     stus[i].name[j] = 0;
    // }
    FILE *fp = fopen("C10.txt","r");
    if(fp == NULL)
    {
        exit(0);
    }
    for(int i=0;i<5;i++)
    {
        fread(&stus[i],sizeof(Student),1,fp);
        printf("%d,%s",stus[i].no,stus[i].name);
        printf("\n");
    }
    
    fclose(fp);

}