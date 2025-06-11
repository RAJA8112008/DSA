#include<stdio.h>
int find(int arr[],int target,int n){
    int st=0;
    int ed=n-1;
    while(st<=ed){
        int mid=st+(ed-st)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]>target){
            ed=mid-1;
        }else{
            st=mid+1;
    }
    }
    return -1;
}

int main(){
    int arr[8]={1,5,48,69,88};
    int target=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=find(arr,target,n);
    if(ans!=-1){
        printf("Target index:%d",ans);
    }else{
        printf("num is not availavle\n");
    }
}