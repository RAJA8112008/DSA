#include<stdio.h>
int main(){
    char op;
    int a,b;
    printf("Enter the value  :");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf(" %c",&op);
    printf("%c",op);
    switch(op){
        case '+':
        printf("sum=%d",a+b);
        break;
         case '-':
        printf("sub=%d",a-b);
        break;
         case '*':
        printf("Multip=%d",a*b);
        break;
         case '/':
        printf("subtraction=%d",a/b);
        break;
         case '%':
        printf("modul=%d",a%b);
        break;
        default:
        printf("Kuch nhi");
    }
}