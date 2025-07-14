#include<stdio.h>

int main(){
  int n,arr[10],temp;
  printf("Enter the values n:");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  printf("Array is:");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  //selection sort
  for(int i=0;i<n-1;i++){
    int min=i;
    for(int j=i;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    //swapping
    temp=arr[i];
    arr[i]=arr[min];
    arr[min]=temp;
  }
  printf("Sorted:");
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
}