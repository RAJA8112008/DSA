#include<stdio.h>
void main(){
    int arr[3][3],brr[3][3],crr[3][3],i,j,k;
    printf("Enter the values:");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&brr[i][j]);
        }
    }
    for(i=0;i<3;i++){  
        for(j=0;j<3;j++){
            crr[i][j]=0;
            for(k=0;k<3;k++){
      crr[i][j]=crr[i][j]+arr[i][k]*brr[k][j];
        }
    }
}
     printf("first matrix:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
     printf("second matrix:\n");
   
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d\t",brr[i][j]);
        }
      printf("\n");
    }
    printf("sum of matrix:\n");
    for(i=0;i<3;i++){
         crr[i][j]=arr[i][j]+brr[i][j];
        for(j=0;j<3;j++){
            printf("%d\t",crr[i][j]);
        }
         printf("\n");
    }
}