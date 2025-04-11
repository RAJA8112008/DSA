#include<iostream>
using namespace std;
int firstOcurrence(int arr[],int n,int key){
	int start=0;
	int end=n-1;
	int ans=-1;
	int mid = start+(end-start)/2;
	while(start<=end){
		if(arr[mid]==key){
			ans = mid;
			end = mid-1;
			
		}
		else if(key>arr[mid]){
			start = mid+1;
		}
		else if(key<arr[mid]){
			end=mid-1;
		}
			mid = start+(end-start)/2;
		
	}
	return ans;
}


int main(){
	int Binaryarr[6]={1,2,3,4,4,5};
	int result =firstOcurrence(Binaryarr,6,4);
	cout<<"index of 4 "<<result<<endl; 
	cout<<"Amit"<<endl;
	return 0;
}