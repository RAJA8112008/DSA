#include<iostream>
using namespace std;
bool isprime(int n){
    for(int i=1;i<=n;i++){
        if(n&i==1){
            
            return 1;
        }

    }
    return 0;
}


int main(){
    int n;
    cin>>n;
    if(isprime(n)){
        cout<<"prime"<<endl;
    }
    cout<<"not prime"<<endl;
}