#include<stdio.h>
void main(){
    int arr[3][3],brr[3][3],crr[3][3],i,j,k;
    printf("Enter the  1 matrix values:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Enter the  2 matrix values:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&brr[i][j]);
        }
    }
    printf("Enter the  3 matrix values:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            crr[i][j]=0;
            for(k=0;k<3;k++){
                crr[i][j]=crr[i][j]+arr[i][k]*brr[k][j];
            }
        }
    }
    printf("Matrix 1:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
     printf("Matrix 2:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",brr[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 3:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",crr[i][j]);
        }
        printf("\n");
    }
}