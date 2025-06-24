#include<stdio.h>
void main(){
    int num,i,count=0;
    scanf("%d",&num);
    for(i=2;i<=num;i++){
        if(num%i==0){
            count++;
        }
    }
    if(count==2){
        printf("num is prime");
    }else{
        printf("num is not prime");
    }
}