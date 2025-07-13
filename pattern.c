#include<stdio.h>
void main(){
    int arr[100],target,n,i,count=0;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the Target:");
    scanf("%d",&target);
    printf("Enter the values of array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array is:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    for(int i=0;i<n;i++){
       if(arr[i]==target){
        count++;
       }
    }
    if(count==1){
        printf("YES");
    }else{
        printf("NO");
    }
   
}