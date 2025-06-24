#include<stdio.h>
void main(){
    int arr[10],i,n,j,s;
    int st,ed,mid,count=0;
    printf("Enter the value of n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array is:");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    printf("\n");
    printf("Searching Element:");
    scanf("%d",&s);
    st=0;
    ed=n-1;
    while(st<=ed){
        mid=st+(ed-st)/2;
        if(arr[mid]==s){
            count=1;
            break;
        }else if(s<arr[mid]){
            ed=mid-1;
        }else{
            st=mid+1;
        }
    }
    if(count==1){
        printf("Available");
    }else{
        printf("not Available");
    }
    
}