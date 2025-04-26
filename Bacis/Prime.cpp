#include <bits/stdc++.h>
using namespace std;

// Correct: function to check if a character is alphanumeric
bool convertor(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= '0' && s <= '9') || (s >= 'A' && s <= 'Z')) {
        return true;
    }
    return false;
}

// Correct: function to manually convert uppercase to lowercase
char towler(char s) {
    if (s >= 'A' && s <= 'Z') {
        s = s + 32; // 'A' + 32 = 'a', 'B' + 32 = 'b', etc
    }
    return s;
}

// Correct: main function to check palindrome
bool checkPalindrome(string s) {
    int st = 0;
    int end = s.size() - 1;
    
    while (st < end) {
        // Skip non-alphanumeric characters
        if (!convertor(s[st])) {
            st++;
        }
        else if (!convertor(s[end])) {
            end--;
        }
        else {
            // Compare after converting to lowercase
            if (towler(s[st]) != towler(s[end])) {
                return false;
            }
            st++;

            
            end--;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    if (checkPalindrome(s)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }
}

