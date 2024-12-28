#include<iostream>
using namespace std;
int main(){
    int n=4;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<=0;j++){
            cout<<"*";
        }
           
   
        cout<<endl;
     }
           
     return 0;   
}