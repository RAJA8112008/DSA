#include<stdio.h>
void main(){
    int num,i;
    unsigned long fact=1;
    printf("Enter the num:");
    scanf("%d",&num);
    if(num<0){
        printf("num is negative");
    }else{
    for(int i=1;i<num;i++){
        fact=fact*i;
    }
    printf("%ul",fact);
}
}