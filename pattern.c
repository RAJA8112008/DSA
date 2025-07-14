#include<stdio.h>
void main(){
    float num1,num2;
  char op;
  printf("Enter the num1:");
  scanf("%f",&num1);
  printf("Enter the op:");
  scanf(" %c",&op);
  printf("Enter the num2:");
  scanf("%f",&num2);
  switch(op){
    case '+':
    printf("a+B:%.2f",num1+num2);
    break;
    case '-':
    printf("a-B:%.2f",num1-num2);
    break;
    case '*':
    printf("a*B:%.2f",num1*num2);
    break;
    case '/':
    printf("a/B:%.2f",num1/num2);
    break;
    default:
    printf("Iv");
  }
  }
