#include<stdio.h>
void main(){
    int year;
    printf("Enter the value of year:");
    scanf("%d",&year);
    if((year%4==0&&year%100!=0)||year%400==0){
        printf("Year is leap");
    }else{
        printf("Not leap");
    }
}