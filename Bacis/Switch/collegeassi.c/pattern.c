#include<stdio.h>
int ftarget(int arr[],int target,int n){
for(int i=0;i<n;i++){
    if(arr[i]==target){
        return i;
    }
}
return -1;
}
int main(){
    int arr[5]={10,25,46,89,5};
    int target=9;
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=ftarget(arr,target,n);
    if(ans!=-1){
    printf("index of target %d\n",ans);
    }else{
        printf("Target is not available:\n",ans);
    }
}