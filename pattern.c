#include<stdio.h>
void main(){
    int year;
    printf("Enter the year:");
    scanf("%d",&year);
    if((year%100!=0 &&year%400==0)||(year%4==0)){
        printf("Year is leap:\n",year);
    }else{
        printf("Year is not leap:\n",year);
    }
}