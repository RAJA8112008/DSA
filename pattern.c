#include<stdio.h>
void main(){
    int st,end;
    int sum=0;
    printf("Enter starting value:");
    scanf("%d",&st);
     printf("Enter Ending value:");
    scanf("%d",&end);

    for(int st;st<=end;st++){
        sum=sum+st;
    }
    printf("SUm is:%d",sum);
}