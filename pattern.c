#include<stdio.h>
void main(){
    int arr[100],n;
    printf("Enter the size of Arrays:");
    scanf("%d",&n);
    printf("Enter the value of arr1:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("Array1 is:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
   int min=arr[0];
   int max=arr[0];
   for(int i=0;i<n;i++){
    if(min>arr[i]){
        min=arr[i];
    }
    if(max<arr[i]){
        max=arr[i];
    }
   }
   printf("min is:%d",min);
    printf("max is:%d",max);
}