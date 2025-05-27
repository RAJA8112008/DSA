#include<stdio.h>
void main(){
    int arr[5],i;
    for(i=0;i<5;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array is :");
    for(i=0;i<5;i++){
        printf(" %d",arr[i]);
    }
}