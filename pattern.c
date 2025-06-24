#include<stdio.h>
void main(){
    int temp,n,i,j,arr[100];
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Original array:");
   for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    //selection sort 
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("\n");
    printf("Sorted array:");
   for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}