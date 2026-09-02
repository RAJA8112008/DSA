// Method 1: Brute
// Time: O(C(9, k) * k) | Space: O(k)
// Generate every k-subset with path copies, then filter by sum. C(9,k) is tiny, but you still build losers and copy arrays on every call.

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum3(int k, int n) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(1, k, n, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int start, int k, int n, List<Integer> path, List<List<Integer>> ans) {
    if (path.size() == k) {
      int sum = 0;
      for (int x : path) sum += x;
      if (sum == n) ans.add(new ArrayList<Integer>(path));
      return;
    }
    for (int x = start; x <= 9; x++) {
      List<Integer> next = new ArrayList<Integer>(path);
      next.add(x);
      go(x + 1, k, n, next, ans);
    }
  }
}


// Method 2: Optimal
// Time: O(C(9, k) * k) | Space: O(k)
// One path. Push x, remain -= x, recurse x+1, pop. Snapshot when k numbers are chosen and remain is 0. No extra copies on internal nodes.

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum3(int k, int n) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(1, k, n, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int start, int left, int remain, List<Integer> path, List<List<Integer>> ans) {
    if (left == 0) { if (remain == 0) ans.add(new ArrayList<Integer>(path)); return; }
    for (int x = start; x <= 9; x++) {
      path.add(x);
      go(x + 1, left - 1, remain - x, path, ans);
      path.remove(path.size() - 1);
    }
  }
}


// Method 3: More optimal
// Time: O(C(9, k) * k) | Space: O(k)
// Prune: remain < 0, or remain bigger than the largest left numbers, or remain smaller than the smallest left numbers. Stop the loop when x itself is already too big.

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum3(int k, int n) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(1, k, n, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int start, int left, int remain, List<Integer> path, List<List<Integer>> ans) {
    if (left == 0) { if (remain == 0) ans.add(new ArrayList<Integer>(path)); return; }
    int minSum = left * (2 * start + left - 1) / 2;
    int maxSum = left * (2 * 9 - left + 1) / 2;
    if (remain < minSum || remain > maxSum) return;
    for (int x = start; x <= 9; x++) {
      if (x > remain) break;
      path.add(x);
      go(x + 1, left - 1, remain - x, path, ans);
      path.remove(path.size() - 1);
    }
  }
}
