#include<stdio.h>
void main(){
    int arr[100],n,sum=0;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array is:");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
     printf("Array Sum is:");
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
      printf("%d",sum);
}