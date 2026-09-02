// Method 1: Brute
// Time: O(n * n!) | Space: O(n)
// Generate every permutation with leftover copies. After a full perm, scan all n positions. n! full arrays, most fail only at the end.

import java.util.*;
class Solution {
  int count;
  public int countArrangement(int n) {
    count = 0;
    List<Integer> left = new ArrayList<Integer>();
    for (int x = 1; x <= n; x++) left.add(x);
    go(n, left, new ArrayList<Integer>());
    return count;
  }
  boolean ok(int n, List<Integer> perm) {
    for (int i = 1; i <= n; i++) {
      int v = perm.get(i - 1);
      if (v % i != 0 && i % v != 0) return false;
    }
    return true;
  }
  void go(int n, List<Integer> left, List<Integer> perm) {
    if (left.isEmpty()) { if (ok(n, perm)) count++; return; }
    for (int i = 0; i < left.size(); i++) {
      List<Integer> nextLeft = new ArrayList<Integer>(left);
      List<Integer> nextPerm = new ArrayList<Integer>(perm);
      nextPerm.add(nextLeft.remove(i));
      go(n, nextLeft, nextPerm);
    }
  }
}


// Method 2: Optimal
// Time: O(n!) | Space: O(n)
// At position pos (1-based), try unused numbers that already satisfy the divisibility rule. Fail early. used[] plus undo. Count leaves that fill n.

class Solution {
  int count;
  public int countArrangement(int n) {
    count = 0;
    go(n, 1, new boolean[n + 1]);
    return count;
  }
  void go(int n, int pos, boolean[] used) {
    if (pos > n) { count++; return; }
    for (int num = 1; num <= n; num++) {
      if (used[num]) continue;
      if (num % pos != 0 && pos % num != 0) continue;
      used[num] = true;
      go(n, pos + 1, used);
      used[num] = false;
    }
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n * 2^n)
// n <= 15. mask bit (num-1) means num is used. pos = popcount(mask)+1. Memo[mask] caches how many ways finish from this used-set. Bitmask + prune + no leftover copies.

class Solution {
  public int countArrangement(int n) {
    int[] memo = new int[1 << n];
    java.util.Arrays.fill(memo, -1);
    return go(n, 0, memo);
  }
  int go(int n, int mask, int[] memo) {
    int pos = Integer.bitCount(mask) + 1;
    if (pos > n) return 1;
    if (memo[mask] != -1) return memo[mask];
    int ways = 0;
    for (int num = 1; num <= n; num++) {
      if ((mask & (1 << (num - 1))) != 0) continue;
      if (num % pos != 0 && pos % num != 0) continue;
      ways += go(n, mask | (1 << (num - 1)), memo);
    }
    memo[mask] = ways;
    return ways;
  }
}
