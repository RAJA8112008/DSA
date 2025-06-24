#include<stdio.h>
void main(){
    int i,arr[10],n;
    printf("Enter the value of N:");
    scanf("%d",&n);
   printf("Enter the num:");
   for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
   }
   printf("Array is:\n");
   for(i=0;i<n;i++){
     printf("%d",arr[i]);
   }
   
}