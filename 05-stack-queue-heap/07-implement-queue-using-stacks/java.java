// Method 1: Brute
// Time: O(n) pop/peek | Space: O(n)
// On pop, pour all into temp (that reverses), pop, pour back. Every call is O(n). Easy to see FIFO, slow.

import java.util.*;
class MyQueue {
  ArrayDeque<Integer> st = new ArrayDeque<Integer>();
  public MyQueue() {}
  public void push(int x) { st.push(x); }
  public int pop() {
    ArrayDeque<Integer> tmp = new ArrayDeque<Integer>();
    while (!st.isEmpty()) tmp.push(st.pop());
    int val = tmp.pop();
    while (!tmp.isEmpty()) st.push(tmp.pop());
    return val;
  }
  public int peek() {
    ArrayDeque<Integer> tmp = new ArrayDeque<Integer>();
    while (!st.isEmpty()) tmp.push(st.pop());
    int val = tmp.peek();
    while (!tmp.isEmpty()) st.push(tmp.pop());
    return val;
  }
  public boolean empty() { return st.isEmpty(); }
}
class Solution {}


// Method 2: Optimal
// Time: O(1) amortized | Space: O(n)
// push always goes to inSt. pop/peek pour inSt into outSt only when outSt is empty. Each item moves at most twice.

import java.util.*;
class MyQueue {
  ArrayDeque<Integer> inSt = new ArrayDeque<Integer>();
  ArrayDeque<Integer> outSt = new ArrayDeque<Integer>();
  public MyQueue() {}
  void pour() {
    if (!outSt.isEmpty()) return;
    while (!inSt.isEmpty()) outSt.push(inSt.pop());
  }
  public void push(int x) { inSt.push(x); }
  public int pop() { pour(); return outSt.pop(); }
  public int peek() { pour(); return outSt.peek(); }
  public boolean empty() { return inSt.isEmpty() && outSt.isEmpty(); }
}
class Solution {}


// Method 3: More optimal
// Time: O(1) amortized | Space: O(n)
// Same two stacks. pop is written as peek plus a pop so pour lives in one place. Interviewers like this factoring; complexity matches Optimal.

import java.util.*;
class MyQueue {
  ArrayDeque<Integer> inSt = new ArrayDeque<Integer>();
  ArrayDeque<Integer> outSt = new ArrayDeque<Integer>();
  public MyQueue() {}
  public void push(int x) { inSt.push(x); }
  public int peek() {
    if (outSt.isEmpty()) while (!inSt.isEmpty()) outSt.push(inSt.pop());
    return outSt.peek();
  }
  public int pop() { peek(); return outSt.pop(); }
  public boolean empty() { return inSt.isEmpty() && outSt.isEmpty(); }
}
class Solution {}
