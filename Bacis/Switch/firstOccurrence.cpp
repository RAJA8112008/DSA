#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;

bool raja(char a, char b) {
    return b <a;
}

int main() {
    string s = "Keshav";
    sort(s.begin(), s.end(), raja);
    cout << s << endl;
    return 0;
}
