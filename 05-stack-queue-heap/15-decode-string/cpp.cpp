// Method 1: Brute
// Time: O(n · out) | Space: O(n · out)
// Recursion: parse a chunk, and when you see k[...], slice the inner substring, decode it, repeat. Extra string copies of the remaining suffix. Correct, messy bounds.

class Solution {
  pair<string,int> parse(const string& s, int i) {
    string out;
    while (i < (int)s.size() && s[i] != ']') {
      if (s[i] < '0' || s[i] > '9') { out += s[i]; i++; continue; }
      int k = 0;
      while (s[i] >= '0' && s[i] <= '9') { k = k * 10 + (s[i] - '0'); i++; }
      i++; // skip '['
      auto inner = parse(s, i);
      for (int t = 0; t < k; t++) out += inner.first;
      i = inner.second + 1; // skip ']'
    }
    return {out, i};
  }
public:
  string decodeString(string s) { return parse(s, 0).first; }
};


// Method 2: Optimal
// Time: O(n + out) | Space: O(n + out)
// One stack. Digits build k. '[' pushes the current string and k, then resets. Letters append. ']' pops and repeats. Linear in input plus output size.

class Solution {
public:
  string decodeString(string s) {
    vector<pair<string,int>> st;
    string cur; int k = 0;
    for (char ch : s) {
      if (ch >= '0' && ch <= '9') k = k * 10 + (ch - '0');
      else if (ch == '[') { st.push_back({cur, k}); cur = ""; k = 0; }
      else if (ch == ']') {
        auto frame = st.back(); st.pop_back();
        string next = frame.first;
        for (int t = 0; t < frame.second; t++) next += cur;
        cur = next;
      } else cur += ch;
    }
    return cur;
  }
};


// Method 3: More optimal
// Time: O(n + out) | Space: O(n + out)
// Two stacks: counts and strings. Same linear bound. Some interviewers prefer two named stacks over pairs. Repeat still dominates the output cost.

class Solution {
public:
  string decodeString(string s) {
    vector<int> counts;
    vector<string> strs;
    string cur; int k = 0;
    for (char ch : s) {
      if (ch >= '0' && ch <= '9') k = k * 10 + (ch - '0');
      else if (ch == '[') { counts.push_back(k); strs.push_back(cur); cur = ""; k = 0; }
      else if (ch == ']') {
        int ck = counts.back(); counts.pop_back();
        string prev = strs.back(); strs.pop_back();
        for (int t = 0; t < ck; t++) prev += cur;
        cur = prev;
      } else cur += ch;
    }
    return cur;
  }
};
