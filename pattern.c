#include<stdio.h>
void main(){
    int a,b,c;
    printf("Enter the num:");
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a>b && a>c){
        printf("A is greater");
    }else if(b>a && b>c){
        printf("B is greater");
    }else{
        printf("C is greater");
    }
    
}