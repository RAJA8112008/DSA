#include<stdio.h>
void main(){
//reverse the num
int num,rem,temp,rev=0;
printf("Enter the value:");
scanf("%d",&num);
temp=num;
 while(num>0){
   rem=num%10;
  rev=rev+rem*rem*rem;
  num=num/10;
 }
 if(temp==rev){
    printf("Num is armstrome");
 }else{
    printf("num is not armstome");
 }
}