// Method 1: Brute
// Time: O(n · k) | Space: O(1)
// For each window start, scan k items for the max. Simple and too slow when k is n/2.

class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    int n = nums.length;
    int[] out = new int[n - k + 1];
    for (int i = 0; i + k - 1 < n; i++) {
      int m = nums[i];
      for (int j = i + 1; j < i + k; j++) if (nums[j] > m) m = nums[j];
      out[i] = m;
    }
    return out;
  }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Max-heap of [value, index] (store negated value in a min-heap). Pop the top while its index left the window. Lazy delete keeps the heap honest. Better than n*k, worse than a deque.

import java.util.*;
class Solution {
  static class MinHeap {
    ArrayList<int[]> a = new ArrayList<int[]>();
    void push(int[] x) { a.add(x); int i = a.size()-1;
      while (i > 0) { int p = (i-1)>>1; if (a.get(i)[0] >= a.get(p)[0]) break;
        int[] t = a.get(i); a.set(i, a.get(p)); a.set(p, t); i = p; } }
    int[] pop() {
      int[] top = a.get(0); int[] last = a.remove(a.size()-1);
      if (!a.isEmpty()) { a.set(0, last); int i = 0;
        while (true) { int s = i, l = i*2+1, r = l+1;
          if (l < a.size() && a.get(l)[0] < a.get(s)[0]) s = l;
          if (r < a.size() && a.get(r)[0] < a.get(s)[0]) s = r;
          if (s == i) break;
          int[] t = a.get(i); a.set(i, a.get(s)); a.set(s, t); i = s; } }
      return top; }
    int[] peek() { return a.get(0); }
  }
  public int[] maxSlidingWindow(int[] nums, int k) {
    MinHeap heap = new MinHeap();
    int[] out = new int[nums.length - k + 1];
    int p = 0;
    for (int i = 0; i < nums.length; i++) {
      heap.push(new int[]{-nums[i], i});
      if (i < k - 1) continue;
      while (heap.peek()[1] <= i - k) heap.pop();
      out[p++] = -heap.peek()[0];
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(k)
// Decreasing deque of indices. Pop back while nums[i] is larger. Pop front if it left the window. Front is the max. Each index enters and leaves once.

import java.util.*;
class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    ArrayDeque<Integer> dq = new ArrayDeque<Integer>();
    int[] out = new int[nums.length - k + 1];
    int p = 0;
    for (int i = 0; i < nums.length; i++) {
      while (!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]) dq.pollLast();
      dq.addLast(i);
      if (dq.peekFirst() <= i - k) dq.pollFirst();
      if (i >= k - 1) out[p++] = nums[dq.peekFirst()];
    }
    return out;
  }
}
