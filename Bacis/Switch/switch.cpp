#include<stdio.h>
int main()
{
    int year;
    printf("Enter ythe value of year:");
    scanf("%d",&year);
    if(year%4==0){
     printf("\n year is leep",year);
    }
    else if(year%100==0){
        printf("\n year is not leep",year);
    }
    else if(year%400==0){
        printf("\n year is leep",year);
    }
}