#include<iostream>
using namespace std;

void merge(int*arr,int left,int mid,int right){
    
}
void mergSort(int*arr,int left,int right){
    if(left>=right){
        return;
    }
    int mid =left+(right-left)/2;
    mergSort(arr,left,mid);
    mergSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}


int main(){
    int arr[]={2,3,4,7,8,9,54,89,79};
    int n=9;
    mergSort(s,0,n-1);
}