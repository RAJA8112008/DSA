#include<stdio.h>
void main(){
    int num,rem,temp,sum=0;
      printf("Enter the value of num:");
      scanf("%d",&num);
      temp = num;
    while(num!=0){
        rem= num % 10;
        sum=sum+(rem*rem*rem);
        num=num/10;
    }
    if(temp==sum){
    printf("\nNumber is Armstrong:%d",temp);
    }else{
        printf("\nNumber is not Armstrong:%d",temp);
    }
}