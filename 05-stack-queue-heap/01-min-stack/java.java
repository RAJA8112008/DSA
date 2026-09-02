// Method 1: Brute
// Time: O(n) getMin | Space: O(n)
// A plain array. getMin walks every item. Correct, but the interview asks for O(1) getMin.

import java.util.*;
class MinStack {
  ArrayList<Integer> a = new ArrayList<Integer>();
  public MinStack() {}
  public void push(int val) { a.add(val); }
  public void pop() { a.remove(a.size() - 1); }
  public int top() { return a.get(a.size() - 1); }
  public int getMin() {
    int m = a.get(0);
    for (int i = 1; i < a.size(); i++) if (a.get(i) < m) m = a.get(i);
    return m;
  }
}
class Solution {}


// Method 2: Optimal
// Time: O(1) | Space: O(n)
// mins tracks the current minimum. Push val onto mins if it is <= current min. Pop mins when the popped value equals mins top. Duplicate mins matter: use <= so two equal mins both sit on mins.

import java.util.*;
class MinStack {
  ArrayDeque<Integer> st = new ArrayDeque<Integer>();
  ArrayDeque<Integer> mins = new ArrayDeque<Integer>();
  public MinStack() {}
  public void push(int val) {
    st.push(val);
    if (mins.isEmpty() || val <= mins.peek()) mins.push(val);
  }
  public void pop() {
    int val = st.pop();
    if (val == mins.peek()) mins.pop();
  }
  public int top() { return st.peek(); }
  public int getMin() { return mins.peek(); }
}
class Solution {}


// Method 3: More optimal
// Time: O(1) | Space: O(n)
// One stack of pairs [val, minSoFar]. Each node already knows the min of the prefix. Slightly more memory per item, one structure to talk through. Still O(1) everything.

import java.util.*;
class MinStack {
  ArrayDeque<int[]> st = new ArrayDeque<int[]>();
  public MinStack() {}
  public void push(int val) {
    int m = st.isEmpty() ? val : Math.min(st.peek()[1], val);
    st.push(new int[]{val, m});
  }
  public void pop() { st.pop(); }
  public int top() { return st.peek()[0]; }
  public int getMin() { return st.peek()[1]; }
}
class Solution {}
