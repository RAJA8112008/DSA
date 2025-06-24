#include<stdio.h>
void main(){
    int arr[100],i,j,n,temp;
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array is :");
    for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
    }
    printf("\n");
    //buble sort process
    printf("Sorted Array:");
    for(i=0;i<n;i++){
      for(j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
            temp=arr[j];
           arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
      }
    }
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

