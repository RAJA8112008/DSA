#include<stdio.h>
void main(){
    int num,rem,original,sum=0;
    
    scanf("%d",&num);
    original=num;
    while(num!=0){
        rem=num%10;
        sum=sum+rem*rem*rem;
        num=num/10;
    }
   if(original==sum){
    printf("pallindrome");
   }else{
    printf(" not pallindrome");
   }
}

