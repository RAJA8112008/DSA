#include<stdio.h>
int fact(int num){
    if(num==0){
        return 1;
    }
    return fact(num-1);
}

int main(){
    int num;
    printf("Enter the num:");
    scanf("%d",&num);
    return fact(num);
    printf("%d",num,fact(num));
}