#include<stdio.h>
int main(){
    int rem,num,sum=0;
    printf("Enter the value of num:");
    scanf("%d",&num);
    while(num!=0){
        rem=num% 10;
        sum =sum+rem;
        num =num/10;
    }
    printf(" Sum of digits of num:%d",sum);
}