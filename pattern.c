#include<stdio.h>
// void swap(int *a,int *b){
//  int temp;
//  if(*a>*b){
//     temp=*a;
//     *a=*b;
//     *b=temp;
//  }
// }
int main(){
 int arr[10],n,temp;
 printf("Enter the size:");
 scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]);
  }
  //bubble sort
 for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
        if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
        }
    }
 }
 for(int i=0;i<n;i++){
    printf("%d",arr[i]);
 }
}