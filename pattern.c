#include<stdio.h>
void main(){
    int arr[10][10],brr[10][10],crr[10][10],n,i,j,k;
    printf("Enter the size of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("First:");
    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            printf("%d",arr[i][j]);
        }
         printf("\n");
    }
    printf("second:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&brr[i][j]);
        }
        printf("\n");
    }
     printf("second:");
    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            printf("%d",brr[i][j]);
        }
         printf("\n");
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            crr[i][j]=0;
            for(int k=0;k<n;k++){
                 crr[i][j]+=arr[i][k]*brr[k][j];
            }
        }
    }
printf("MULTIPLY:");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ",crr[i][j]);
    }
    printf("\n");
}
}