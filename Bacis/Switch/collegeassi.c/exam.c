#include<stdio.h>
void main(){
    int rem,num,sum=0;

printf("Enter the num:");
scanf("%d",&num);
while(num!=0){
    rem=num%10;
    sum=sum+rem;
    num=num/10;
}
printf("Total sum:%d",sum);
}