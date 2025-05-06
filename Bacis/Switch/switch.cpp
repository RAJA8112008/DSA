#include<stdio.h>
int main(){
    int num;
    printf("value of num:");
    scanf("%d",&num);
    switch(num%2){
        case 0:
        printf("num is odd");
        break;
        case 1:
        printf("num is even",num);
        break;
        default:

        printf("value is not found");
    }
}