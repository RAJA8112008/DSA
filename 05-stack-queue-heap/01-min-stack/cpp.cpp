// Method 1: Brute
// Time: O(n) getMin | Space: O(n)
// A plain array. getMin walks every item. Correct, but the interview asks for O(1) getMin.

class MinStack {
  vector<int> a;
public:
  void push(int val) { a.push_back(val); }
  void pop() { a.pop_back(); }
  int top() { return a.back(); }
  int getMin() {
    int m = a[0];
    for (int i = 1; i < (int)a.size(); i++) if (a[i] < m) m = a[i];
    return m;
  }
};


// Method 2: Optimal
// Time: O(1) | Space: O(n)
// mins tracks the current minimum. Push val onto mins if it is <= current min. Pop mins when the popped value equals mins top. Duplicate mins matter: use <= so two equal mins both sit on mins.

class MinStack {
  vector<int> st, mins;
public:
  void push(int val) {
    st.push_back(val);
    if (mins.empty() || val <= mins.back()) mins.push_back(val);
  }
  void pop() {
    int val = st.back(); st.pop_back();
    if (val == mins.back()) mins.pop_back();
  }
  int top() { return st.back(); }
  int getMin() { return mins.back(); }
};


// Method 3: More optimal
// Time: O(1) | Space: O(n)
// One stack of pairs [val, minSoFar]. Each node already knows the min of the prefix. Slightly more memory per item, one structure to talk through. Still O(1) everything.

class MinStack {
  vector<pair<int,int>> st;
public:
  void push(int val) {
    int m = st.empty() ? val : min(st.back().second, val);
    st.push_back({val, m});
  }
  void pop() { st.pop_back(); }
  int top() { return st.back().first; }
  int getMin() { return st.back().second; }
};
