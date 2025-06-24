#include<stdio.h>
void main(){
    int n,arr[100],j,i,x;
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array is :");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Finder element:");
    scanf("%d",&x);
    // finding element in array 
    for(i=0;i<n;i++){
    if(arr[i]==x){
        printf("Available"); 
    }
}
}

