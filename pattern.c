#include<stdio.h>
void main(){
    int num;
    printf("Enter the num:");
    scanf("%d",&num);
    if(num%10==0){
        printf("Num is even");
    }else{
        printf("num is odd");
    }
}