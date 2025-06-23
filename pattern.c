#include<stdio.h>
void main(){
    int arr[2][2],brr[2][2],bcc[2][2],i,j,k;
    printf("Enter the valus of matrix1:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("matrix 1 is :\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d\t",arr[i][j]);
        }
          printf("\n");
    }
     printf("Enter the valus of matrix2:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&brr[i][j]);
        }
    }
    printf("matrix 2 is :\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d\t",brr[i][j]);
        }
          printf("\n");
    }
    printf("Multiply matrix:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            bcc[i][j]=0;
            for(k=0;k<2;k++){
                bcc[i][j]= bcc[i][j]+arr[i][k]*brr[k][j];
            }
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d\t",bcc[i][j]);
        }
        printf("\n");
    }
}