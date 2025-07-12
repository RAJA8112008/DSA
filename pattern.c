#include<stdio.h>
void main(){
    float a,b; 
    char operator;
    printf("Enter the operator:");
    scanf(" %c",&operator);
     printf("Enter the values:");
     scanf("%f",&a);
     scanf("%f",&b);
     switch(operator){
        case '+':
        printf("result:%f",a+b);
        break;
        case '-':
        printf("result:%f",a-b);
        break;
        case '*':
        printf("result:%f",a*b);
        break;
        case '/':
        if(b!=0)
        printf("result:%.2f",a/b);
        break;
        default:
        printf("invalid operator");
     }
}