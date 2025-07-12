#include<stdio.h>
void main(){
    int arr[100],brr[100],n,result=0;
    printf("Enter the size of Arrays:");
    scanf("%d",&n);
    printf("Enter the value of arr1:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("Enter the value of brr1:");
    for(int i=0;i<n;i++){
        scanf("%d",&brr[i]);
    }
     printf("Array1 is:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
     printf("\nArray2 is:");
    for(int i=0;i<n;i++){
        printf("%d ",brr[i]);
    }
    for(int i=0;i<n;i++){
        result +=arr[i]+brr[i];
    }
    printf("Sum:%d",result);
}