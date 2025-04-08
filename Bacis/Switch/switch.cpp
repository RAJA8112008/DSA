#include<iostream>
using namespace std;

void swaparr(int arr[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
    swap(arr[start],arr[end]);
    start++;
    end--;
}
}

void printarr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int arr[6]={4,5,6,2,8,3};
    printarr( arr,6);
    swaparr(arr,6);
    printarr(arr,6);
    return 0;
}