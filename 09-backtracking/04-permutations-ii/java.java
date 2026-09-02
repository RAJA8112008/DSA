// Method 1: Brute
// Time: O(n * n!) | Space: O(n * n!)
// Generate every leftover-copy permutation, stringify, keep a Set. Duplicate 1s still walk the full n! tree. Extra copies plus the Set.

import java.util.*;
class Solution {
  public List<List<Integer>> permuteUnique(int[] nums) {
    Set<String> seen = new HashSet<String>();
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    List<Integer> left = new ArrayList<Integer>();
    for (int x : nums) left.add(x);
    go(left, new ArrayList<Integer>(), seen, ans);
    return ans;
  }
  void go(List<Integer> left, List<Integer> path, Set<String> seen, List<List<Integer>> ans) {
    if (left.isEmpty()) {
      if (seen.add(path.toString())) ans.add(path);
      return;
    }
    for (int i = 0; i < left.size(); i++) {
      List<Integer> nextLeft = new ArrayList<Integer>(left);
      List<Integer> nextPath = new ArrayList<Integer>(path);
      nextPath.add(nextLeft.remove(i));
      go(nextLeft, nextPath, seen, ans);
    }
  }
}


// Method 2: Optimal
// Time: O(n * n!) | Space: O(n)
// Sort so equal values are adjacent. Skip nums[j] when it equals nums[j-1] and used[j-1] is false. That forces a fixed order on identical numbers. One path, used[].

import java.util.*;
class Solution {
  public List<List<Integer>> permuteUnique(int[] nums) {
    Arrays.sort(nums);
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(nums, new boolean[nums.length], new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] nums, boolean[] used, List<Integer> path, List<List<Integer>> ans) {
    if (path.size() == nums.length) { ans.add(new ArrayList<Integer>(path)); return; }
    for (int j = 0; j < nums.length; j++) {
      if (used[j]) continue;
      if (j > 0 && nums[j] == nums[j - 1] && !used[j - 1]) continue;
      used[j] = true;
      path.add(nums[j]);
      go(nums, used, path, ans);
      path.remove(path.size() - 1);
      used[j] = false;
    }
  }
}


// Method 3: More optimal
// Time: O(n * n!) | Space: O(n)
// In-place swap. A tiny set of values already swapped into start this round stops identical branches. No sort required. Same unique output, less leftover copying.

import java.util.*;
class Solution {
  public List<List<Integer>> permuteUnique(int[] nums) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(nums, 0, ans);
    return ans;
  }
  void go(int[] nums, int start, List<List<Integer>> ans) {
    if (start == nums.length) {
      List<Integer> cur = new ArrayList<Integer>();
      for (int x : nums) cur.add(x);
      ans.add(cur);
      return;
    }
    Set<Integer> seen = new HashSet<Integer>();
    for (int i = start; i < nums.length; i++) {
      if (!seen.add(nums[i])) continue;
      int t = nums[start]; nums[start] = nums[i]; nums[i] = t;
      go(nums, start + 1, ans);
      t = nums[start]; nums[start] = nums[i]; nums[i] = t;
    }
  }
}
