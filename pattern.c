#include<stdio.h>
void main(){
    int n,arr[100],j,temp;
    printf("Enter the size of array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("array is:");
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    //Selection  sorting process
    for(int i=0;i<n-1;i++){
       int min=i;
       for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
       }
       temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}