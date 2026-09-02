// Method 1: Brute
// Time: O(2ⁿ) | Space: O(n)
// From each index you may try every jump length. Overlapping paths are recomputed, so the tree is exponential. Stack depth is O(n).
// How it works: dfs(i) is true if i is the last index, or any i + step can reach the end.

class Solution {
  public boolean canJump(int[] nums) {
    int n = nums.length;
    public void dfs(i) {
      if (i >= n - 1) return true;
      int maxStep = nums[i];
      for (int step = 1; step <= maxStep; step++) {
        if (dfs(i + step)) return true;
      }
      return false;
    }
    return dfs(0);
  }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// For each index you may look at every previous index. Worst case quadratic. Extra array of n booleans.
// How it works: ok[0] is true. ok[j] becomes true if some earlier ok[i] can jump to j. Return ok[n-1].

class Solution {
  public boolean canJump(int[] nums) {
    int n = nums.length;
    boolean[] ok = new boolean[n];
    ok[0] = true;
    for (int i = 0; i < n; i++) {
      if (!ok[i]) continue;
      int last = Math.min(n - 1, i + nums[i]);
      for (int j = i + 1; j <= last; j++) ok[j] = true;
    }
    return ok[n - 1];
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One left-to-right pass. farthest is the rightmost index you can reach so far.
// How it works: if i > farthest you cannot even stand here. Update farthest with i + nums[i]. If farthest covers the last index, return true.

class Solution {
  public boolean canJump(int[] nums) {
    int farthest = 0;
    int n = nums.length;
    for (int i = 0; i < n; i++) {
      if (i > farthest) return false;
      int reach = i + nums[i];
      if (reach > farthest) farthest = reach;
      if (farthest >= n - 1) return true;
    }
    return true;
  }
}
