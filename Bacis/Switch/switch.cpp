#include<stdio.h>
int main()
{
   int year;
   printf("value of year:");
   scanf("%d",&year);
   if((year%4==0 && year%100!=0)||(year%400==0)){
    printf("\nyear is leep:%d",year);
   }else{
    printf("\nyear is not leep:%d",year);
   }
}