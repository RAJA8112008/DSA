#include<stdio.h>
void main(){
    int arr[10][10],i,j;
    printf("Enter the values");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Matrix:");
    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    
    printf("Transpose Matrix:");
    printf("\n");
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            printf("%d\t",arr[j][i]);
        }
        printf("\n");
    }
   
}