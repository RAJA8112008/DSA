#include<stdio.h>
int main(){
    
    int num,original,rem,sum=0;
    original=sum;
    printf("Enter the num:");
    scanf("%d",&num);
    while(num!=0){
        rem=num%10;
        sum=sum+rem;
        num=num/10;
    }
     
     if(original==num){
        printf("pallindrome");
     }else{
        printf("not pallindrome");
     }
}