#include<stdio.h>
int main(){
    int num,rem,val,sum=0;
    printf("num:");
    scanf("%d",&num);
    while(num!=0){
        rem=num%10;
        sum=sum*10+rem;
        val=num/10;
    }
    printf("\nnum:%d",num);
}