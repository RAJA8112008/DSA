#include<stdio.h>
void main(){
    int arr[100][100],n,m;
    printf("Enter the size of row:");
     scanf("%d",&n);
     printf("Enter the size of col:");
     scanf("%d",&m);
    printf("Enter the matrix values:");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Original matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
printf("Transpose matrix:\n");
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        printf("%d ",arr[j][i]);
    }
     printf("\n");
}

}