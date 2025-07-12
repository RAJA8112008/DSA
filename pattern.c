#include<stdio.h>
void main(){
    //swaping of two variables
    int a,b,temp;
    printf("Enter the number A:");
    scanf("%d",&a);
    printf("Enter the number B:");
    scanf("%d",&b);
    temp=a;
    a=b;
    b=temp;
    printf("Swaped numbers are:\n");
    printf(" a:%d",a);
     printf("b:%d",b);
    
}