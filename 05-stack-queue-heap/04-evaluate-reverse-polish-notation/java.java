// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Copy the list. Each round find the first operator, replace the triple with one number. Splice is O(n), and you do it O(n) times.

import java.util.*;
class Solution {
  int calc(int a, int b, String op) {
    if (op.equals("+")) return a + b;
    if (op.equals("-")) return a - b;
    if (op.equals("*")) return a * b;
    return a / b; // trunc toward 0
  }
  public int evalRPN(String[] tokens) {
    ArrayList<String> a = new ArrayList<String>(Arrays.asList(tokens));
    while (a.size() > 1) {
      int i = 0;
      while (!(a.get(i).equals("+") || a.get(i).equals("-") || a.get(i).equals("*") || a.get(i).equals("/"))) i++;
      int val = calc(Integer.parseInt(a.get(i - 2)), Integer.parseInt(a.get(i - 1)), a.get(i));
      a.set(i - 2, String.valueOf(val));
      a.remove(i);
      a.remove(i - 1);
    }
    return Integer.parseInt(a.get(0));
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One stack. Numbers go on. An operator pops b then a (order matters for - and /), pushes the result. One pass.

import java.util.*;
class Solution {
  public int evalRPN(String[] tokens) {
    ArrayDeque<Integer> st = new ArrayDeque<Integer>();
    for (String t : tokens) {
      if (!t.equals("+") && !t.equals("-") && !t.equals("*") && !t.equals("/")) {
        st.push(Integer.parseInt(t));
        continue;
      }
      int b = st.pop(), a = st.pop();
      if (t.equals("+")) st.push(a + b);
      else if (t.equals("-")) st.push(a - b);
      else if (t.equals("*")) st.push(a * b);
      else st.push(a / b);
    }
    return st.peek();
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same stack, but a small apply helper and bitwise trunc for JS integers (or Math.trunc). Cleaner talk track. Complexity unchanged.

import java.util.*;
class Solution {
  int apply(String op, int a, int b) {
    if (op.equals("+")) return a + b;
    if (op.equals("-")) return a - b;
    if (op.equals("*")) return a * b;
    return a / b;
  }
  public int evalRPN(String[] tokens) {
    ArrayDeque<Integer> st = new ArrayDeque<Integer>();
    for (String t : tokens) {
      if (t.equals("+") || t.equals("-") || t.equals("*") || t.equals("/")) {
        int b = st.pop(), a = st.pop();
        st.push(apply(t, a, b));
      } else st.push(Integer.parseInt(t));
    }
    return st.peek();
  }
}
