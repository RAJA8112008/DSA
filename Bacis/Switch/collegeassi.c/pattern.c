#include<stdio.h>
int fact(int num){
    if(num==0){
        return 1;
    }
    return num*fact(num-1);
}

int main(){
    int num;
    printf("Enter the num:");
    scanf("%d",&num);
    int result=fact(num);
    printf(" Factorial of %d is %d\n",num,result);
}