#include<stdio.h>
void main(){
    int n,arr[100],temp;
    printf("Enter the size of array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("array is:");
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    //bubble sorting process
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
              temp=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=temp;
            }
        }
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}