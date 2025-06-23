#include<stdio.h>
void main(){
    int arr[3][3],brr[3][3],crr[3][3],i,j;
    printf(" Enter matrix 1:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }
     printf(" Enter matrix2:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&brr[i][j]);
        }
    }
     printf("matrix 1 is :\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
 printf("matrix 2 is :\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",brr[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            crr[i][j]=arr[i][j]+brr[i][j];
        }
    }
    printf(" Addition matrix  is :\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",crr[i][j]);
        }
        printf("\n");
    }

}