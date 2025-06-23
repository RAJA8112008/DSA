#include<stdio.h>
void main (){
int arr[10][10],i,j,row,col;
printf("Enter the row:");
scanf("%d", &row);
printf("Enter the col:");
scanf("%d", &col);
printf("Enter the values:\n");
for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        scanf("%d", &arr[i][j]);
    }
}
printf("Matrix is:\n");
for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
}
 printf("Transpose matrix:\n");
 for(i=0;i<col;i++){
    for(j=0;j<row;j++){
        printf("%d\t",arr[j][i]);
    }
    printf("\n");
 }

}