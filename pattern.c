#include<stdio.h>
void main(){
    int num1,num2;
    char operator;
    printf("Enter the num1:");
    scanf("%d",&num1);
     printf("Enter the num2:");
    scanf("%d",&num2);
    printf("Enterr the operator:");
    scanf(" %c",&operator);
   
    switch(operator){
        case '+':
        printf("Sum:%d",num1+num2);
        break;
         case '-':
        printf("Sub:%d",num1-num2);
        break;
         case '*':
        printf("mul:%d",num1*num2);
        break;
         case '/':
        printf("Sumb:%d",num1/num2);
        break;
        default:
        printf("Invalid value");
    }
}