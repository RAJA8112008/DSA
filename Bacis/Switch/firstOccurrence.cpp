#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;

bool raja(char a, char b) {
    return a <b;
}

int main() {
    string s = "babbar";
    sort(s.begin(), s.end(), raja);
    cout << s << endl;
    return 0;
}
