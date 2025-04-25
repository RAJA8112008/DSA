#include<iostream>
using namespace std;

int getlength(char name[]){
    int count =0;
    for(int i=0;name[i]!='/0';i++){
        count++;
    }
    return count;
}

int main(){
   char name[10];
   cin>>name;
   cout<<"my name"<<name<<endl;
   cout<<"length"<<getlength(name)<<endl;
   return 0;
}
