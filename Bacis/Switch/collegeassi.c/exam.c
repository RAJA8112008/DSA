#include<stdio.h>
void main(){
    int arr[4][4],i,j;
    printf("Enter the values");
    for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        scanf("%d",&arr[i][j]);
    }
    }
    printf("arr is:");
    printf("\n");
    for(i=0;i<4;i++){
    for(j=0;j<4;j++){
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
    }
}