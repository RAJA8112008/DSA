#include<stdio.h>
void main(){
    int arr[10],i,j,n,temp;
    printf("Enter the value of n:");
    scanf("%d",&n);
    //Enter the value of Array
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    //Insertion sort processing 
    printf("Enter the values of Array:");
    for(i=1;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("Sorted array:");
for(i=0;i<n;i++){
 printf("%d",arr[i]);
  }
}