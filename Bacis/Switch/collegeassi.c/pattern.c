#include<stdio.h>
void fact(int i,int num,int factorial){
    if(num==0){
        return 1;
    }
    for(int i=1;i<=num;i++){
        return num*fact(i+1);
    }
}
int main(){
    int i,num,factorial=1;
    printf("Enter the num:");
    scanf("%d",&num);
    return fact( i,num);
}