#include<iostream>
using namespace std;
int firstOcurrence(int arr[],int n,int key){
	int start=0;
	int end=n-1;
	int mid =(start+end)/2;
	while(start<=end){
		if(arr[mid]<=key){
			start=mid+1;
		}
		else if(arr[mid]>key){
			end=mid-1;
		}
		else{
			return mid;
		}
	}
	return 
}


int main(){
	int Binaryarr[6]={1,2,3,4,4,5};

}