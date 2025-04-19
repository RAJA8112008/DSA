#include<iostream>
using namespace std;

void  getsort(int arr[],int n){
    
    for(int i=1;i<n-1;i++){
        int mininum=i;
        for(int j=i+1;j<n;j++){
            if(arr[mininum]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main(){
    int n=5;
    
    int arr[5]= {10,8,9,1,5};
    getsort(arr,n);
    for(int i=1;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
    
}