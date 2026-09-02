// Method 1: Brute
// Time: O(2ⁿ) | Space: O(n)
// From each index you may try every jump length. Overlapping paths are recomputed, so the tree is exponential. Stack depth is O(n).
// How it works: dfs(i) is true if i is the last index, or any i + step can reach the end.

/* pass n for array length; simple loops */
int canJump(int* nums, int n) {
  /* n is the given length */
  void dfs(/* i */) {
    if (i >= n - 1) return 1;
    int maxStep = nums[i];
    for (int step = 1; step <= maxStep; step++) {
      if (dfs(i + step)) return 1;
    }
    return 0;
  }
  return dfs(0);
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// For each index you may look at every previous index. Worst case quadratic. Extra array of n booleans.
// How it works: ok[0] is true. ok[j] becomes true if some earlier ok[i] can jump to j. Return ok[n-1].

/* pass n for array length; simple loops */
int canJump(int* nums, int n) {
  /* n is the given length */
  int ok = /* zeros n */;
  ok[0] = 1;
  for (int i = 0; i < n; i++) {
    if (!ok[i]) continue;
    int last = (n - 1 < i + nums[i] ? n - 1 : i + nums[i]);
    for (int j = i + 1; j <= last; j++) ok[j] = 1;
  }
  return ok[n - 1];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One left-to-right pass. farthest is the rightmost index you can reach so far.
// How it works: if i > farthest you cannot even stand here. Update farthest with i + nums[i]. If farthest covers the last index, return true.

/* pass n for array length; simple loops */
int canJump(int* nums, int n) {
  int farthest = 0;
  /* n is the given length */
  for (int i = 0; i < n; i++) {
    if (i > farthest) return 0;
    int reach = i + nums[i];
    if (reach > farthest) farthest = reach;
    if (farthest >= n - 1) return 1;
  }
  return 1;
}
