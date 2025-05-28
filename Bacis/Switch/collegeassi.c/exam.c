#include<stdio.h>
void main(){
    char op;
    int a,b;
    printf("Enter the value of a &b:");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&op);
    switch(op){
        case '+':
        printf("Sum:&",a+b);
        break;
        case '-':
         printf("Sub:%d",a-b);
        break;
        case '*':
         printf("mul:%d",a*b);
        break;
        case '/':
         printf("Sub:%d",a/b);
        break;
            case '%':
         printf("mod:%d",a%b);
        break;
        default:
        printf("Enter valid oper");
    }
}