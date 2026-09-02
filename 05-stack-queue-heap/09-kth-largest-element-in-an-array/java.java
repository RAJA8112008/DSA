// Method 1: Brute
// Time: O(n · k) | Space: O(n)
// Copy the array. k times, find and remove the current max. Fine for tiny k, slow for k near n.

import java.util.*;
class Solution {
  public int findKthLargest(int[] nums, int k) {
    ArrayList<Integer> a = new ArrayList<Integer>();
    for (int x : nums) a.add(x);
    int ans = 0;
    for (int t = 0; t < k; t++) {
      int best = 0;
      for (int i = 1; i < a.size(); i++) if (a.get(i) > a.get(best)) best = i;
      ans = a.get(best);
      a.remove(best);
    }
    return ans;
  }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort descending (or ascending and index). Honest and short. Use this first in an interview, then offer a heap.

import java.util.*;
class Solution {
  public int findKthLargest(int[] nums, int k) {
    int[] a = nums.clone();
    Arrays.sort(a);
    return a[a.length - k];
  }
}


// Method 3: More optimal
// Time: O(n log k) | Space: O(k)
// Min-heap of size k. If the heap is full and x is bigger than the peek, replace the peek. The peek is the k-th largest. Tiny binary heap inlined. Quickselect is expected O(n) if they want that next.

class Solution {
  void up(int[] h, int i) {
    while (i > 0) { int p = (i-1)>>1; if (h[i] >= h[p]) break; int t=h[i]; h[i]=h[p]; h[p]=t; i=p; }
  }
  void down(int[] h, int n, int i) {
    while (true) { int s=i, l=i*2+1, r=l+1;
      if (l<n && h[l]<h[s]) s=l; if (r<n && h[r]<h[s]) s=r;
      if (s==i) break; int t=h[i]; h[i]=h[s]; h[s]=t; i=s; }
  }
  public int findKthLargest(int[] nums, int k) {
    int[] h = new int[k];
    int n = 0;
    for (int x : nums) {
      if (n < k) { h[n++] = x; up(h, n-1); }
      else if (x > h[0]) {
        h[0] = h[--n]; if (n>0) down(h, n, 0);
        h[n++] = x; up(h, n-1);
      }
    }
    return h[0];
  }
}
