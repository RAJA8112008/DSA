// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Copy the list. Each round find the first operator, replace the triple with one number. Splice is O(n), and you do it O(n) times.

class Solution {
  int calc(int a, int b, const string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    return a / b;
  }
public:
  int evalRPN(vector<string>& tokens) {
    vector<string> a = tokens;
    while (a.size() > 1) {
      int i = 0;
      while (a[i] != "+" && a[i] != "-" && a[i] != "*" && a[i] != "/") i++;
      int val = calc(stoi(a[i - 2]), stoi(a[i - 1]), a[i]);
      a.erase(a.begin() + (i - 1), a.begin() + (i + 1));
      a[i - 2] = to_string(val);
    }
    return stoi(a[0]);
  }
};


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One stack. Numbers go on. An operator pops b then a (order matters for - and /), pushes the result. One pass.

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    vector<int> st;
    for (auto& t : tokens) {
      if (t != "+" && t != "-" && t != "*" && t != "/") { st.push_back(stoi(t)); continue; }
      int b = st.back(); st.pop_back();
      int a = st.back(); st.pop_back();
      if (t == "+") st.push_back(a + b);
      else if (t == "-") st.push_back(a - b);
      else if (t == "*") st.push_back(a * b);
      else st.push_back(a / b);
    }
    return st[0];
  }
};


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same stack, but a small apply helper and bitwise trunc for JS integers (or Math.trunc). Cleaner talk track. Complexity unchanged.

class Solution {
  int apply(const string& op, int a, int b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    return a / b;
  }
public:
  int evalRPN(vector<string>& tokens) {
    vector<int> st;
    for (auto& t : tokens) {
      if (t == "+" || t == "-" || t == "*" || t == "/") {
        int b = st.back(); st.pop_back();
        int a = st.back(); st.pop_back();
        st.push_back(apply(t, a, b));
      } else st.push_back(stoi(t));
    }
    return st[0];
  }
};
