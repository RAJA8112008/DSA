#include<iostream>
using namespace std;

int solve(int arr[],int size,int key){
int start =0;
int end=size-1;
int mid =(start+end)/2;
 
while(start<=end){
	if(arr[mid]<key){
		start =mid+1;
	}
	else if(arr[mid]>key){
		end =mid-1;
	}
	else{
		return mid;
		 mid =(start+end)/2;
	}
}
return -1;
}
int main(){
	int oddarr[6]={2,4,6,8,10,12};
	 int result=  solve(oddarr,6,10);
	 cout<<"fining value"<<result<<endl;
return 0;
}