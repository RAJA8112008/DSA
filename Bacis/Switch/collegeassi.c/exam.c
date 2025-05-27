#include<stdio.h>
void main(){
    int num,i;
    unsigned long fact=1;
    printf("Enter the name:");
    scanf("%d",&num);
    if(num<0){
        printf("Enter the poss num:");
    }else{
        for(i=0;i<=num;i++){
            fact*=i;
        }
        printf("Factorial %d",fact);
    }
}