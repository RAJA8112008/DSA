#include<stdio.h>
void main(){
    int rem,num,sum=0,original;
    printf("Enter the marks:");
    scanf("%d",&num);
  original=num;
  while(num!=0){
    rem=num%10;
    sum=sum+rem*rem*rem;
    num=num/10;
  }
 if(sum==original){
    printf("Pallindrome");
 }else{
    printf("Not Pallindrome");
 }

}