#include<stdio.h>
void main(){
    int st,end;
    int sum=0;
   
     printf("Enter Ending value:");
    scanf("%d",&end);

    for(int i=0;i<=end;i++){
        sum=sum+i;
    }
    printf("SUm is:%d",sum);
}