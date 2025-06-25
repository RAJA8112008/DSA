#include<stdio.h>
void main(){
    int arr[100],i,j,n,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
//selection sort 
for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
        if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
       
         } }
    }
    for(i=0;i<n;i++){
    printf("%d ",arr[i]);
    }


}