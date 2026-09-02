// Method 1: Brute
// Time: O(4^n / n^{3/2}) | Space: O(n)
// Naive recursion: try each root and multiply left-count * right-count. Exponential overlapping subproblems.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function numTrees(n) {
  function count(len) {
    if (len <= 1) return 1;
    let total = 0;
    for (let left = 0; left < len; left++) {
      total += count(left) * count(len - 1 - left);
    }
    return total;
  }
  return count(n);
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// dp[k] = number of BSTs on k keys. dp[0]=1. Each k sums dp[left]*dp[k-1-left]. Standard Catalan DP.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function numTrees(n) {
  const dp = Array(n + 1).fill(0);
  dp[0] = 1;
  for (let k = 1; k <= n; k++) {
    for (let left = 0; left < k; left++) dp[k] += dp[left] * dp[k - 1 - left];
  }
  return dp[n];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// C(n) = C(n-1) * 2(2n-1)/(n+1). Multiply carefully with integer arithmetic. One pass, constant extra memory.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function numTrees(n) {
  let c = 1;
  for (let i = 2; i <= n; i++) c = c * 2 * (2 * i - 1) / (i + 1);
  return Math.round(c);
}
