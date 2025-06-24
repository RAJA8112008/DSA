#include<stdio.h>
void main(){
    int n,arr[100],j,i,x,count=0;
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
       count=1;
       break;
    }
}
if(count=1){
printf("Available ");
}else{
   printf(" not Available"); 
}
}

