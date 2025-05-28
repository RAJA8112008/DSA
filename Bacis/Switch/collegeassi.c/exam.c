#include<stdio.h>
void main(){
    int num,i;
    unsigned long factorial=1;
    printf("Enter the num:");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        factorial*=i;
    }
printf("factorial is %lu",factorial);
}