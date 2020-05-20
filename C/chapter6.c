#include <stdio.h>
//一维数组
 int score[5]={95,65,90,85,20};
//二维 
 int score_2[3][4]={{90,85,75,89},{85,82,83,95},{90,90,90,90}};
void main()
{
    void q_1();
    void q_2();
    void q_3();
    q_3();
    
}
//6.1求平均成绩
void q_1()
{

    int sum=0;
       for (int j = 0; j < 5; j++)
        {
            sum +=score[j];
        }
        printf("%d",sum/5);
}
//求出最高成绩
void q_2()
{
  
    int max= score[0],index=0;
       for (int j = 0; j < 5; j++)
        {
            if(max<score[j]){
                max = score[j];
                index = j;
            }
           
        }
        printf("maxium score:%d \t counterpart ID:%d",max,index);
}
//三个学生四门课
void q_3()
{
    
 double avg1,avg2,avg3,avg4;
 for(int i=0;i<3;i++){
     for(int j =0;j<=4;j++){
         switch (j)
         {
         case 1:
        avg1+=score_2[i][j];
             break;
        case 2:
        avg2+=score_2[i][j];
            break;
        case 3:
        avg3+=score_2[i][j];
        break;
        case 4:
        avg4+=score_2[i][j];
             break;
         default:
             break;
         }
    }
 }
 printf("avg1:%f \t avg2:%f \t avg3:%f \t avg4:%f",avg1/3,avg2/3,avg3/3,avg4/3);
}
