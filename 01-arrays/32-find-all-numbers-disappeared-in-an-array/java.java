// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each candidate v in 1..n, scan the array. If it never appears, it is missing.

import java.util.*;
class Solution {
  public List<Integer> findDisappearedNumbers(int[] nums) {
    List<Integer> out = new ArrayList<Integer>();
    int n = nums.length;
    for (int v = 1; v <= n; v++) {
      boolean found = false;
      for (int x : nums) if (x == v) { found = true; break; }
      if (!found) out.add(v);
    }
    return out;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A boolean array (or a set) of seen values. Then walk 1..n and collect the false slots.

import java.util.*;
class Solution {
  public List<Integer> findDisappearedNumbers(int[] nums) {
    int n = nums.length;
    boolean[] seen = new boolean[n + 1];
    for (int x : nums) seen[x] = true;
    List<Integer> out = new ArrayList<Integer>();
    for (int v = 1; v <= n; v++) if (!seen[v]) out.add(v);
    return out;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra
// For each value x, negate nums[abs(x)-1]. Values whose slots stay positive never appeared. Same marking trick as Find All Duplicates.

import java.util.*;
class Solution {
  public List<Integer> findDisappearedNumbers(int[] nums) {
    for (int x : nums) {
      int slot = Math.abs(x) - 1;
      if (nums[slot] > 0) nums[slot] = -nums[slot];
    }
    List<Integer> out = new ArrayList<Integer>();
    for (int i = 0; i < nums.length; i++) if (nums[i] > 0) out.add(i + 1);
    return out;
  }
}
