#include<stdio.h>
void main(){
    int num,rem,temp,rev=0;
    printf("Enter the num:");
    scanf("%d",&num);
    temp=num;
    while(num>0){
        rem=num%10;
        rev=rev*10+rem;
        num=num/10;
    }
    if(temp==rev){
        printf("is pallindrome");
    }else{
        printf("not pallindrome");
    }
}