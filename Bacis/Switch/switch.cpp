#include<iostream>
using namespace std;
int main(){
  int a=5;
  int*p=&a;
  int**q=&p;
  cout<<a<<endl;
  cout<<"Adress of a"<<&a<<endl;
  cout<<"address of p"<<p<<endl;
  cout<<"address of p"<<&p<<endl;
  cout<<"adress of q"<<q<<endl;
  cout<<"adress of q"<<&q<<endl;
  cout<<"adress of q"<<q[0]<<endl;
}