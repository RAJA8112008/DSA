// Method 1: Brute
// Time: O(n * n!) | Space: O(n * n!)
// At each step you copy the leftover numbers into a new array and copy the path. Extra copies on every internal node. n! leaves, each of length n.

import java.util.*;
class Solution {
  public List<List<Integer>> permute(int[] nums) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    List<Integer> left = new ArrayList<Integer>();
    for (int x : nums) left.add(x);
    go(left, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(List<Integer> left, List<Integer> path, List<List<Integer>> ans) {
    if (left.isEmpty()) { ans.add(path); return; }
    for (int i = 0; i < left.size(); i++) {
      List<Integer> nextLeft = new ArrayList<Integer>(left);
      List<Integer> nextPath = new ArrayList<Integer>(path);
      nextPath.add(nextLeft.remove(i));
      go(nextLeft, nextPath, ans);
    }
  }
}


// Method 2: Optimal
// Time: O(n * n!) | Space: O(n)
// used[j] marks nums[j] as taken. One path, mark/unmark. Extra space is O(n) besides the n! output lists.

import java.util.*;
class Solution {
  public List<List<Integer>> permute(int[] nums) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(nums, new boolean[nums.length], new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] nums, boolean[] used, List<Integer> path, List<List<Integer>> ans) {
    if (path.size() == nums.length) {
      ans.add(new ArrayList<Integer>(path));
      return;
    }
    for (int j = 0; j < nums.length; j++) {
      if (used[j]) continue;
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
// Swap nums[start] with each later index, recurse start+1, swap back. The prefix is the path. No used[] and no leftover copies. Still n! output.

import java.util.*;
class Solution {
  public List<List<Integer>> permute(int[] nums) {
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
    for (int i = start; i < nums.length; i++) {
      int t = nums[start]; nums[start] = nums[i]; nums[i] = t;
      go(nums, start + 1, ans);
      t = nums[start]; nums[start] = nums[i]; nums[i] = t;
    }
  }
}
