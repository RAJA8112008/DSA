#include<iostream>
using namespace std;
int decnumToBinary(int decnum){
int ans=0,pow=1;

while(decnum>0){
int rem=decnum%2; 
decnum/=2;
ans+=(rem*pow);
    pow*=10;
}
return ans;
}
int main(){
    int decnum=0;
    for(int i=1;i<=10;i++)
    cout<<decnumToBinary(decnum)<<endl;
    return 0;
}