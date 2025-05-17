#include<stdio.h>
int main(){
    int first,Last;
    //start num
    printf("Enter the First num:");
    scanf("%d",&first);
    //last num
    printf("Enter the Last num:");
    scanf("%d",&Last);
    for(int i=first;i<=Last;i++){
        if(first%i==0){
            printf("Prime Num :%d",first);
        }
    }
}