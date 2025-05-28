#include<stdio.h>
void main(){
    int num,i,factorial=1;
    printf("Enter the num:");
    scanf("%d",&num);
    for(i=1;i<=num;i++){
        factorial*=i;
    }
printf("factorial:%d",factorial);
}