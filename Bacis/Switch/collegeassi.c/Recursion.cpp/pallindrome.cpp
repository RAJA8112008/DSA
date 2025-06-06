#include<iostream>
using namespace std;

int checkpallindrome(int s,int e){

 //base condition
 if(s>e){
    return false;
 }
 // solve one case
 if(s==e){
    return true;
 }else{
    return false;
 }
 return checkpallindrome(s+1,e-1);
 }

int main(){
    string str="raja";
    int s=str[0];
    int e=str.length();
   return checkpallindrome(s,e);
}