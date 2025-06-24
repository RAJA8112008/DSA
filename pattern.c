#include<stdio.h>
void main(){
    int a,b,c,max;
    printf("Enter the values:");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    max=a>b?(a>c?a:c):(b>c?b:c);
    printf("Greater among :%d",max);

}