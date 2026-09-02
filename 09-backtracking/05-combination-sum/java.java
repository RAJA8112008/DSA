// Method 1: Brute
// Time: O(n^{target/min}) | Space: O(target/min)
// Every call copies path.concat. You keep going while the sum is not past target, with no sort prune. Extra arrays at every node. Correct but heavy.

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum(int[] cands, int target) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(cands, 0, 0, target, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] cands, int start, int sum, int target, List<Integer> path, List<List<Integer>> ans) {
    if (sum == target) { ans.add(new ArrayList<Integer>(path)); return; }
    if (sum > target) return;
    for (int i = start; i < cands.length; i++) {
      List<Integer> next = new ArrayList<Integer>(path);
      next.add(cands[i]);
      go(cands, i, sum + cands[i], target, next, ans);
    }
  }
}


// Method 2: Optimal
// Time: O(n^{target/min}) | Space: O(target/min)
// One path, push/pop. remain shrinks. Call go(i, remain - cands[i]) to reuse this value, or move to i+1 to skip. Copy only at remain == 0.

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum(int[] cands, int target) {
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(cands, 0, target, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] cands, int i, int remain, List<Integer> path, List<List<Integer>> ans) {
    if (remain == 0) { ans.add(new ArrayList<Integer>(path)); return; }
    if (i == cands.length || remain < 0) return;
    go(cands, i + 1, remain, path, ans);
    path.add(cands[i]);
    go(cands, i, remain - cands[i], path, ans);
    path.remove(path.size() - 1);
  }
}


// Method 3: More optimal
// Time: O(n^{target/min}) | Space: O(target/min)
// Sort first. In the for-loop, break when cands[i] > remain so larger later values are never tried. Same answers, fewer dead branches.

import java.util.*;
class Solution {
  public List<List<Integer>> combinationSum(int[] cands, int target) {
    Arrays.sort(cands);
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    go(cands, 0, target, new ArrayList<Integer>(), ans);
    return ans;
  }
  void go(int[] cands, int start, int remain, List<Integer> path, List<List<Integer>> ans) {
    if (remain == 0) { ans.add(new ArrayList<Integer>(path)); return; }
    for (int i = start; i < cands.length; i++) {
      if (cands[i] > remain) break;
      path.add(cands[i]);
      go(cands, i, remain - cands[i], path, ans);
      path.remove(path.size() - 1);
    }
  }
}
