#include<stdio.h>
int main()
{
   int day;
   printf("Enter the day number:");
   scanf("%d",&day);
   if(day==1){
    printf("\nSunday");
   }
   else if(day==2){
    printf("\nMonday");
   }
   else if(day==3){
    printf("\n Tuesday");
   }
   else if(day==4){
    printf("\nwednesday");
   }
   else if(day==5){
    printf("\n Tuesday");
   }
   else if(day==6){
    printf("\nFriday");
   }
   else if(day==7){
    printf("\n Saturday");
   }
   else{
    printf("Day is not found:");
   }
}