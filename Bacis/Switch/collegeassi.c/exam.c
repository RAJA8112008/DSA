#include<stdio.h>
void main(){
    int arr[4][4],i,j;
    printf("Enter the values");
    for(i=0;i<4;i++){
    scanf("%d",&arr[i]);
    for(j=0;j<4;j++){
        scanf("%d",arr[j]);
    }
    }
    printf("Array is");
    for(i=0;i<4;i++){
    printf("%d\t",arr[i]);
    for(j=0;j<4;j++){
        printf("%d\t",arr[j]);
    }
    }


}