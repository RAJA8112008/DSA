#include<iostream>
using namespace std;
 void merge(int*arr,int st,int mid,int end){
    
 }
void mergeSort(int*arr,int st,int end){
    int mid=st+(end-st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,st,mid,end);
}


int main(){
    int arr[]={1,2,4,0,57,51,889,47,12,11,23};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);

}