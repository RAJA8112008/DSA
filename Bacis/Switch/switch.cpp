#include<iostream>
using namespace std;

int totalsum(int sumnum[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        
         
        ans= ans+sumnum[i];
    }
    
   return ans;
}


int main(){
    
    int sumnum[5]={1,2,3,4,5};
   int result= totalsum(sumnum,5);

cout<<result<<endl;
return 0;

}