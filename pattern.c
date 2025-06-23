#include<stdio.h>
   void main(){
    int arr[5],i,n,j,temp;
    printf("Enter the values\n:");
     scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //buble sorting 
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("Sorted Array:");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
     printf("\n");
   }