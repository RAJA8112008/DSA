#include<iostream>
#include<vector>
using namespace std;
  bool substring(vector<int>nums,int start,int end){
      //base case
      if(nums[end]==nums.size()){
         return true;
      }
      //one case solve
      if(nums[start]==nums[end]){
       cout<<nums[end]<<endl;
      }
      //funvtion call
      return substring(nums,start,end+1);
  }
int main(){
  vector<int>nums{1,2,3,4,5};
   substring(nums,0,0);
}