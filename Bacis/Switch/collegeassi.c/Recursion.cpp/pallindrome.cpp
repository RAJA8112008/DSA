#include<iostream>
using namespace std;
bool checkpallindrome( string str,int s,int e){
 //base condition
 if(s>=e){
    return true;
 }
 // solve one case
 if(str[s]!=str[e]){
    return false;
 }
 return checkpallindrome(str,s+1,e-1);
 }

int main(){
    string str="Nitin";
     for(auto&ch:str){
        if(ch>='A' && ch<='Z'){
            ch=ch+32;
        }
    }
    int s=0;
    int e=str.length()-1;
   
  if(checkpallindrome(str,s,e)){
    cout<<"Pallindrome"<<endl;
  }else{
    cout<<"not pallindrome"<<endl;
  }
}