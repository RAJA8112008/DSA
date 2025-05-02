#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;

bool ramu(char a,char b){
    return a < b;
}

int main(){

    string  monk ="rampal_tau";
    sort(monk.begin(),monk.end(),ramu);
    cout<<monk<<endl;
    return 0;

}