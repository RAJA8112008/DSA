// Method 1: Brute
// Time: O(2ⁿ) | Space: O(n)
// From each index you may try every jump length. Overlapping paths are recomputed, so the tree is exponential. Stack depth is O(n).
// How it works: dfs(i) is true if i is the last index, or any i + step can reach the end.

function canJump(nums) {
  const n = nums.length;
  function dfs(i) {
    if (i >= n - 1) return true;
    const maxStep = nums[i];
    for (let step = 1; step <= maxStep; step++) {
      if (dfs(i + step)) return true;
    }
    return false;
  }
  return dfs(0);
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// For each index you may look at every previous index. Worst case quadratic. Extra array of n booleans.
// How it works: ok[0] is true. ok[j] becomes true if some earlier ok[i] can jump to j. Return ok[n-1].

function canJump(nums) {
  const n = nums.length;
  const ok = new Array(n).fill(false);
  ok[0] = true;
  for (let i = 0; i < n; i++) {
    if (!ok[i]) continue;
    const last = Math.min(n - 1, i + nums[i]);
    for (let j = i + 1; j <= last; j++) ok[j] = true;
  }
  return ok[n - 1];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One left-to-right pass. farthest is the rightmost index you can reach so far.
// How it works: if i > farthest you cannot even stand here. Update farthest with i + nums[i]. If farthest covers the last index, return true.

function canJump(nums) {
  let farthest = 0;
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    if (i > farthest) return false;
    const reach = i + nums[i];
    if (reach > farthest) farthest = reach;
    if (farthest >= n - 1) return true;
  }
  return true;
}
