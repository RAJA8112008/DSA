#include<iostream>
using namespace std;
int getPivot(int arr[],int n){
	int s=0;
	int e=n-1;
	while(s<e){
		int mid =s+(e-s)/2;
		if(arr[mid]>=arr[0]){
			s= mid+1;
		}
		else{
			e=mid;
		}
	}
	return s;
}
int main(){
	int arr[7]={9,7,8,5,6,1,2};
	int result=getPivot(arr,6);
	cout<<" pivot index:"<<result<<endl;
}