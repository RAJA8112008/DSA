#include<stdio.h>
void main(){
    int i,n,key,j,arr[100];
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("array is:");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    // insertion algorithum
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[i]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
    printf("Sorted array");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}