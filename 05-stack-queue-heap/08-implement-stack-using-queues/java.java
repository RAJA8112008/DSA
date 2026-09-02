// Method 1: Brute
// Time: O(n) pop | Space: O(n)
// Two queues. pop moves all but the last item to the other queue, then swaps names. Push is O(1). Pop is O(n).

import java.util.*;
class MyStack {
  ArrayDeque<Integer> q1 = new ArrayDeque<Integer>();
  ArrayDeque<Integer> q2 = new ArrayDeque<Integer>();
  public MyStack() {}
  public void push(int x) { q1.addLast(x); }
  public int pop() {
    while (q1.size() > 1) q2.addLast(q1.pollFirst());
    int val = q1.pollFirst();
    ArrayDeque<Integer> tmp = q1; q1 = q2; q2 = tmp;
    return val;
  }
  public int top() { int val = pop(); push(val); return val; }
  public boolean empty() { return q1.isEmpty(); }
}
class Solution {}


// Method 2: Optimal
// Time: O(n) push, O(1) pop | Space: O(n)
// One queue. After push, rotate length-1 items so the new item sits at the front. pop/top/empty are then O(1).

import java.util.*;
class MyStack {
  ArrayDeque<Integer> q = new ArrayDeque<Integer>();
  public MyStack() {}
  public void push(int x) {
    q.addLast(x);
    for (int i = 0; i < q.size() - 1; i++) q.addLast(q.pollFirst());
  }
  public int pop() { return q.pollFirst(); }
  public int top() { return q.peekFirst(); }
  public boolean empty() { return q.isEmpty(); }
}
class Solution {}


// Method 3: More optimal
// Time: O(1) push, O(n) pop | Space: O(n)
// One queue, no rotate on push. pop rotates n-1 items then shifts. Prefer this when pushes are common and pops are rare. Same extra space.

import java.util.*;
class MyStack {
  ArrayDeque<Integer> q = new ArrayDeque<Integer>();
  public MyStack() {}
  public void push(int x) { q.addLast(x); }
  public int pop() {
    for (int i = 0; i < q.size() - 1; i++) q.addLast(q.pollFirst());
    return q.pollFirst();
  }
  public int top() { return q.peekLast(); }
  public boolean empty() { return q.isEmpty(); }
}
class Solution {}
