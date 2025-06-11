#include<stdio.h>
int ftarget(int arr[],int target,int n){
for(int i=0;i<n;i++){
    if(arr[i]==target){
        return i;
    }
}
}
int main(){
    int arr[5]={10,25,46,89,5};
    int target=89;
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=ftarget(arr,target,n);
    if(target!=-1){
    printf("index of target %d\n",ans);
    }else{
        printf("Target is not available:\n",ans);
    }
}