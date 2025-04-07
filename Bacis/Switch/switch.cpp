# include<iostream>
using namespace std;
  
int totalsum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum= sum + arr[i];
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int result= totalsum(arr,n);
     cout<<result<<endl;
     return 0;
}