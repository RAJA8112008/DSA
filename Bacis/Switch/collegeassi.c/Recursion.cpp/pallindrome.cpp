#include<iostream>
#include<vector>
using namespace std;
  void substring(vector<int>nums,int start,int end){
      //base case
      if(end==nums.size()){
         return;
      }
      //one case solve
      for(int i=start;i<=end;i++){

        
        cout<<nums[i];
      }
      cout<<endl;
    
      //funvtion call
     substring(nums,start,end+1);
  }
  void allsubstring(vector<int>nums){
       for(int start=0;start<nums.size();start++){
        substring(nums,start,start);
       }
  }
int main(){
  vector<int>nums{1,2,3,4,5};
     allsubstring(nums);
   return 0;
}