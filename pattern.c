#include<stdio.h>
void main(){
    //pallindrome
    int num,rem,sum=0,original;
  printf("Enter the num:");
  scanf("%d",&num);
  original=num;
  while(num!=0){
    rem=num%10;
    sum=sum*10+rem;
    num=num/10;
  }
if(original==sum){
    printf("Yes");
}else{
    printf("NO");
}
}