#include<iostream>
using namespace std;
  
bool search( int arr[],int size,int n){
    for(int i=0;i<size;i++){
    if(arr[i]==n){
        return 1;
    }
} 
    return 0;

}


int main(){
    int n;
    cin>>n;
    int arr[5]={1,2,3,4,5};
     
   if(search( arr,5,n)){
    cout<<"value exist"<<endl;
   }else{

cout<<"value not essist"<<endl;
   }
return 0;
}
