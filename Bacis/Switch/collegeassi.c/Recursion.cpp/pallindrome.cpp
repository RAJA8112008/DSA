#include<iostream>
using namespace std;
int checkpallindrome( string str,int s,int e){
 //base condition
 if(s>=e){
    return true;
 }
 // solve one case
 if(str[s]!=str[e]){
    return false;
 }else{
    return true;
 }
 return checkpallindrome(str,s+1,e-1);
 }

int main(){
    string str="nitin";
    int s=0;
    int e=str.length()-1;
  if(checkpallindrome(str,s,e)){
    cout<<"Pallindrome"<<endl;
  }else{
    cout<<"not pallindrome"<<endl;
  }
}