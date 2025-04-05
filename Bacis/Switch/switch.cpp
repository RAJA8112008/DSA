#include<iostream>
using namespace std;
int factorial(int n){
    int factorial=1;
    for(int i=1;i<=n;i++){
        factorial=factorial*i;
    }
    return factorial;
}
int ncr(int n,int r){
    int num=factorial(n);
    int demuneter=factorial(r)*factorial(n-r);
    int ans=num/demuneter;
    return ans;
}
int main(){
    int n,r;
    cin>>n>>r;
cout<<"value of ncr:"<<ncr<<endl;
}