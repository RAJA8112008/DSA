// Method 1: Brute
// Time: O(n) pop/peek | Space: O(n)
// On pop, pour all into temp (that reverses), pop, pour back. Every call is O(n). Easy to see FIFO, slow.

class MyQueue {
  vector<int> st;
public:
  void push(int x) { st.push_back(x); }
  int pop() {
    vector<int> tmp;
    while (!st.empty()) { tmp.push_back(st.back()); st.pop_back(); }
    int val = tmp.back(); tmp.pop_back();
    while (!tmp.empty()) { st.push_back(tmp.back()); tmp.pop_back(); }
    return val;
  }
  int peek() {
    vector<int> tmp;
    while (!st.empty()) { tmp.push_back(st.back()); st.pop_back(); }
    int val = tmp.back();
    while (!tmp.empty()) { st.push_back(tmp.back()); tmp.pop_back(); }
    return val;
  }
  bool empty() { return st.empty(); }
};


// Method 2: Optimal
// Time: O(1) amortized | Space: O(n)
// push always goes to inSt. pop/peek pour inSt into outSt only when outSt is empty. Each item moves at most twice.

class MyQueue {
  vector<int> inSt, outSt;
  void pour() {
    if (!outSt.empty()) return;
    while (!inSt.empty()) { outSt.push_back(inSt.back()); inSt.pop_back(); }
  }
public:
  void push(int x) { inSt.push_back(x); }
  int pop() { pour(); int x = outSt.back(); outSt.pop_back(); return x; }
  int peek() { pour(); return outSt.back(); }
  bool empty() { return inSt.empty() && outSt.empty(); }
};


// Method 3: More optimal
// Time: O(1) amortized | Space: O(n)
// Same two stacks. pop is written as peek plus a pop so pour lives in one place. Interviewers like this factoring; complexity matches Optimal.

class MyQueue {
  vector<int> inSt, outSt;
public:
  void push(int x) { inSt.push_back(x); }
  int peek() {
    if (outSt.empty()) while (!inSt.empty()) { outSt.push_back(inSt.back()); inSt.pop_back(); }
    return outSt.back();
  }
  int pop() { peek(); int x = outSt.back(); outSt.pop_back(); return x; }
  bool empty() { return inSt.empty() && outSt.empty(); }
};
