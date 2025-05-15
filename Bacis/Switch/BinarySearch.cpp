#include<stdio.h>
int main(){
    int num,rem,sum=0;
    printf("num:");
    scanf("%d",&num);
    while(num!=0){
        num=num%10;
        sum=sum*10+rem;
        num=num/10;
    }
    printf("\nnum:%d",sum);
}