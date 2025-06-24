#include<stdio.h>
void main(){
    int i,rem,num,temp,sum=0;
    printf("Enter the num:");
    scanf("%d",&num);
while(num!=0){
    rem=num%10;
    sum=sum+rem;
    num=num/10;
}
printf("SUM is:%d",sum);

}