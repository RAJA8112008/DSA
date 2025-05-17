#include<stdio.h>
int main(){  
    int num,original,rem,sum=0;  //to check Pallindrome number
    printf("Enter the num:");
    scanf("%d",&num);
     original=sum;
    while(num!=0){
        rem=num%10;
        sum=sum*10+rem;
        num=num/10;
    }
     if(original==sum){
        printf("pallindrome");
     }else{
        printf("not pallindrome");
     }
     return 0;
}