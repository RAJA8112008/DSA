#include<iostream>
using namespace std;
 void merge(int*arr,int st,int mid,int end){
    int n1=mid-st+1;
    int n2=end-mid;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i]=arr[st+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[mid+1+j];
    }
    //merging two array
    int i=0,j=0,k=st;
    while(i<n1 && j<n2){
        if(R[i]<L[j]){
            arr[k++]=R[i++];
        }else{
            arr[k++]=L[j++];
        }
    }
    //coping extra elements
    while(i<n1){
        arr[k++]=R[i++];
    }
    while(j<n2){
        arr[k++]=L[j++];
    }
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
    for(int i=0;i<n;i++){
    cout<<arr[i]<<"";
  }
  cout<<endl;
}