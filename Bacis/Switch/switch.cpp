#include<iostream>
using namespace std;
int solve(int arr[],int size,int key){
	int start =0;
	int end= size-1; 
	int mid =(start+end)/2;
	while(start<=end){
		
		if(arr[mid]<key){
			int start =mid+1;
		}
			else if(arr[mid]>key){
				int end=mid-1;
		}
		else{
			return mid;
		}
		int mid =(start+end)/2;
	}
	return -1;
}
int main(){
int evenarr[5]={2,4,6,8,10};
 int result=solve(evenarr,5,10);
 cout<<"Key value"<<result<<endl;
 return 0;

}