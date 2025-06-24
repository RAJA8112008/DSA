#include<stdio.h>
void main(){
   //palindrome
   int rem,num,org,sum=0;
   printf("Enter the num:");
   scanf("%d",&num);
   org=num;
   while(num!=0){
    rem=num%10;
    sum=sum*10+rem;
    num=num/10;
   }
   if(sum==org){
    printf("Pallindrome");
   }else{
    printf("Not pallindrome");
   }
}