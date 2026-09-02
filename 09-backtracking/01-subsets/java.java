// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Each call does path.concat so every node of the tree allocates a new array. Correct, but you pay extra copies on internal nodes, not only at leaves. Time is still exponential because there are 2^n subsets.

import java.util.*;
class Solution {
  public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(nums, 0, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] nums, int i, List<Integer> path, List<List<Integer>> ans) {
    if (i == nums.length) { ans.add(path); return; }
    go(nums, i + 1, new ArrayList<Integer>(path), ans);
    List<Integer> take = new ArrayList<Integer>(path);
    take.add(nums[i]);
    go(nums, i + 1, take, ans);
  }
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// One path array is shared. Push, recurse, pop. You copy only at a leaf. Extra memory besides the output is the path plus O(n) stack.

import java.util.*;
class Solution {
  public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(nums, 0, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] nums, int i, List<Integer> path, List<List<Integer>> ans) {
    if (i == nums.length) {
      ans.add(new ArrayList<Integer>(path));
      return;
    }
    go(nums, i + 1, path, ans);
    path.add(nums[i]);
    go(nums, i + 1, path, ans);
    path.remove(path.size() - 1);
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// No recursion. Each mask from 0 to 2^n-1 is one subset. Bit i on means nums[i] is in. Same output size, no call stack, tight inner loop.

import java.util.*;
class Solution {
  public List<List<Integer>> subsets(int[] nums) {
    int n = nums.length;
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    int total = 1 << n;
    for (int mask = 0; mask < total; mask++) {
      List<Integer> cur = new ArrayList<Integer>();
      for (int i = 0; i < n; i++) if ((mask & (1 << i)) != 0) cur.add(nums[i]);
      ans.add(cur);
    }
    return ans;
  }
}
