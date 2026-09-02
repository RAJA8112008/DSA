// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Walk every node into an array, sort, then wire a new list. Ignores that each list is already sorted. Easy to code under pressure.

import java.util.*;
class ListNode {
  int val; ListNode next;
  ListNode(int v) { val = v; }
}
class Solution {
  public ListNode mergeKLists(ListNode[] lists) {
    ArrayList<Integer> vals = new ArrayList<Integer>();
    for (ListNode p : lists) {
      while (p != null) { vals.add(p.val); p = p.next; }
    }
    Collections.sort(vals);
    ListNode dummy = new ListNode(0), cur = dummy;
    for (int v : vals) { cur.next = new ListNode(v); cur = cur.next; }
    return dummy.next;
  }
}


// Method 2: Optimal
// Time: O(n log k) | Space: O(k)
// Min-heap of list heads keyed by val. Pop the smallest, push its next. n pops, heap size k. Uses the sorted property.

class ListNode {
  int val; ListNode next;
  ListNode(int v) { val = v; }
}
class Solution {
  java.util.ArrayList<ListNode> h = new java.util.ArrayList<ListNode>();
  int key(ListNode x) { return x.val; }
  void up(int i) {
    while (i > 0) { int p=(i-1)>>1; if (key(h.get(i))>=key(h.get(p))) break;
      ListNode t=h.get(i); h.set(i,h.get(p)); h.set(p,t); i=p; }
  }
  void down(int i) {
    while (true) { int s=i, l=i*2+1, r=l+1;
      if (l<h.size() && key(h.get(l))<key(h.get(s))) s=l;
      if (r<h.size() && key(h.get(r))<key(h.get(s))) s=r;
      if (s==i) break; ListNode t=h.get(i); h.set(i,h.get(s)); h.set(s,t); i=s; }
  }
  void push(ListNode node) { h.add(node); up(h.size()-1); }
  ListNode pop() {
    ListNode top = h.get(0); ListNode last = h.remove(h.size()-1);
    if (!h.isEmpty()) { h.set(0, last); down(0); }
    return top;
  }
  public ListNode mergeKLists(ListNode[] lists) {
    for (ListNode node : lists) if (node != null) push(node);
    ListNode dummy = new ListNode(0), cur = dummy;
    while (!h.isEmpty()) {
      ListNode node = pop();
      cur.next = node; cur = node;
      if (node.next != null) push(node.next);
    }
    return dummy.next;
  }
}


// Method 3: More optimal
// Time: O(n log k) | Space: O(log k)
// Pairwise merge like merge sort. Recursion depth log k. No heap to implement. Same n log k, often faster constants in JS, and O(1) extra besides the call stack.

class ListNode {
  int val; ListNode next;
  ListNode(int v) { val = v; }
}
class Solution {
  ListNode mergeTwo(ListNode a, ListNode b) {
    ListNode dummy = new ListNode(0), cur = dummy;
    while (a != null && b != null) {
      if (a.val <= b.val) { cur.next = a; a = a.next; }
      else { cur.next = b; b = b.next; }
      cur = cur.next;
    }
    cur.next = a != null ? a : b;
    return dummy.next;
  }
  ListNode split(ListNode[] lists, int lo, int hi) {
    if (lo == hi) return lists[lo];
    int mid = (lo + hi) >> 1;
    return mergeTwo(split(lists, lo, mid), split(lists, mid + 1, hi));
  }
  public ListNode mergeKLists(ListNode[] lists) {
    if (lists.length == 0) return null;
    return split(lists, 0, lists.length - 1);
  }
}
