// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Build every subset with extra path copies, stringify, and keep a Set. Duplicate work is thrown away after you already built it. Fine for tiny n, not the interview finish.

import java.util.*;
class Solution {
  public List<List<Integer>> subsetsWithDup(int[] nums) {
    Set<String> seen = new HashSet<String>();
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(nums, 0, new ArrayList<Integer>(), seen, ans);
    return ans;
  }
  void go(int[] nums, int i, List<Integer> path, Set<String> seen, List<List<Integer>> ans) {
    if (i == nums.length) {
      List<Integer> copy = new ArrayList<Integer>(path);
      Collections.sort(copy);
      if (seen.add(copy.toString())) ans.add(copy);
      return;
    }
    go(nums, i + 1, new ArrayList<Integer>(path), seen, ans);
    List<Integer> take = new ArrayList<Integer>(path);
    take.add(nums[i]);
    go(nums, i + 1, take, seen, ans);
  }
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// Sort, then at each start skip nums[i] when it equals nums[i-1]. Those two 2s cannot start the same role twice, so [1,2] appears once. One path, push/pop.

import java.util.*;
class Solution {
  public List<List<Integer>> subsetsWithDup(int[] nums) {
    Arrays.sort(nums);
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(nums, 0, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] nums, int start, List<Integer> path, List<List<Integer>> ans) {
    ans.add(new ArrayList<Integer>(path));
    for (int i = start; i < nums.length; i++) {
      if (i > start && nums[i] == nums[i - 1]) continue;
      path.add(nums[i]);
      go(nums, i + 1, path, ans);
      path.remove(path.size() - 1);
    }
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// Same sort-and-skip, plus you can count how many copies of this value exist and take 0..count in one shot. That collapses a chain of duplicate-index decisions into one loop.

import java.util.*;
class Solution {
  public List<List<Integer>> subsetsWithDup(int[] nums) {
    Arrays.sort(nums);
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(nums, 0, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] nums, int start, List<Integer> path, List<List<Integer>> ans) {
    ans.add(new ArrayList<Integer>(path));
    int i = start;
    while (i < nums.length) {
      int j = i;
      while (j < nums.length && nums[j] == nums[i]) j++;
      int count = j - i;
      for (int t = 1; t <= count; t++) {
        path.add(nums[i]);
        go(nums, j, path, ans);
      }
      for (int t = 1; t <= count; t++) path.remove(path.size() - 1);
      i = j;
    }
  }
}
