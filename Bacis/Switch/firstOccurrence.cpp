#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;

bool caseInsensitiveCompare(char a, char b) {
    return tolower(a) < tolower(b);
}

int main() {
    string s = "Keshav";
    sort(s.begin(), s.end(), caseInsensitiveCompare);
    cout << s << endl;
    return 0;
}
