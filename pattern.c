#include<stdio.h>
 int fact(int n){
 if(n==0){
    return 1;
 }
 if(n==1){
    return 1;
 }
 return n*fact(n-1);
 }

int main(){
    int num,n;
    printf("Enter the num:");
    scanf("%d",&num);
    int result=fact(num);
    printf("%d",result);
}