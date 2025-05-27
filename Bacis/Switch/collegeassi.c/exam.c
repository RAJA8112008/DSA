#include<stdio.h>
void main(){
//reverse the num
int num,rem,rev=0;
printf("Enter the value:");
scanf("%d",&num);
 while(num>0){
   rem=num%10;
  rev=rev*10+rem;
  num=num/10;
 }
 printf("reverse num:%d\n",rev);
}