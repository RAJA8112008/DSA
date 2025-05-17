#include<stdio.h>
int main(){
    int num,rem,sum=0;
    int original=sum;
    printf("Enter the num:");
    scanf("%d",&num);
    while(num!=0){
        rem=num%10;
        sum=sum*10+rem;
        num=num/10;
    }
    printf("Reverse num :%d",sum);

if(original==num){
        printf("pallindrome");
    }
    printf(" not pallindrome");
}