#include<stdio.h>
void main(){
    int  i,num,fact=1;
    printf("Enter the num:");
    scanf("num",&num);
    for(i=1;i<num;i++){
        fact*=i;
    }
    printf("Fact:%d",num);

}