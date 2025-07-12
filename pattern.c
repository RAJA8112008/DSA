#include<stdio.h>
void main(){
    int arr[100],n;
    int val,count=0;
    printf("Enter the size of Arrays:");
    scanf("%d",&n);
    printf("Enter the value:");
    scanf("%d",&val);
    printf("Enter the value of arr1:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("Array1 is:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    for(int i=0;i<n;i++){
        if(val==arr[i]){
           count++;
        }
    }
    if(count==1){
           printf("yes");
        }else{
             printf("NO");
        }
  
}