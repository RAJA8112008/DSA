#include<stdio.h>
void bubble(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]<arr[j+1]){
                int temp=arr[j];
                 arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int  main(){
    int arr[5]={1,3,5,6,0};
    int n=sizeof(arr)/sizeof(arr[0]);
  bubble(arr,n);
  printf("Sorted array:\n");
  for(int i=0;i<n;i++){
    printf("%d",arr[i]);
  }
  printf("\n");
}