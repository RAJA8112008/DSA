#include<iostream>
using namespace std;
  
bool search( int arr[],int n){
    if(n==arr[n]){
        return 1;
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    int arr[5]={1,2,3,4,5}
     
   if(search( arr,n)){
    cout<<"value exist"<<endl;
   }
cout<<"value not essist"<<endl;
return 0;
}
