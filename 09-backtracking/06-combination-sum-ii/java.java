// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Every index is take or skip with extra path copies. Keep combinations whose sum is target, unique them with a sorted-tuple Set. Duplicate indexes still explore the full 2^n tree.

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum2(int[] cands, int target) {
    Set<String> seen = new HashSet<String>();
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(cands, 0, 0, target, new ArrayList<Integer>(), seen, ans);
    return ans;
  }
  void go(int[] cands, int i, int sum, int target, List<Integer> path, Set<String> seen, List<List<Integer>> ans) {
    if (sum == target) {
      List<Integer> copy = new ArrayList<Integer>(path);
      Collections.sort(copy);
      if (seen.add(copy.toString())) ans.add(copy);
      return;
    }
    if (i == cands.length || sum > target) return;
    go(cands, i + 1, sum, target, new ArrayList<Integer>(path), seen, ans);
    List<Integer> take = new ArrayList<Integer>(path);
    take.add(cands[i]);
    go(cands, i + 1, sum + cands[i], target, take, seen, ans);
  }
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// Sort. Skip nums[i] == nums[i-1] at the same start so identical values do not start the same role twice. Each index is used at most once (go(i+1)).

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum2(int[] cands, int target) {
    Arrays.sort(cands);
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(cands, 0, target, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] cands, int start, int remain, List<Integer> path, List<List<Integer>> ans) {
    if (remain == 0) { ans.add(new ArrayList<Integer>(path)); return; }
    for (int i = start; i < cands.length; i++) {
      if (i > start && cands[i] == cands[i - 1]) continue;
      if (cands[i] > remain) continue;
      path.add(cands[i]);
      go(cands, i + 1, remain - cands[i], path, ans);
      path.remove(path.size() - 1);
    }
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// After sort, break when cands[i] > remain. Later values are larger, so they cannot help. Same unique combinations, fewer recursive calls.

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum2(int[] cands, int target) {
    Arrays.sort(cands);
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(cands, 0, target, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] cands, int start, int remain, List<Integer> path, List<List<Integer>> ans) {
    if (remain == 0) { ans.add(new ArrayList<Integer>(path)); return; }
    for (int i = start; i < cands.length; i++) {
      if (cands[i] > remain) break;
      if (i > start && cands[i] == cands[i - 1]) continue;
      path.add(cands[i]);
      go(cands, i + 1, remain - cands[i], path, ans);
      path.remove(path.size() - 1);
    }
  }
}
