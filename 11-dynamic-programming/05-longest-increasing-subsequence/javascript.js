// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// At each index you take (if it is larger than prev) or skip. No cache, so every subset of positions is explored. Depth is n.

function lengthOfLIS(nums) {
  function go(i, prev) {
    if (i === nums.length) return 0;
    const skip = go(i + 1, prev);
    let take = 0;
    if (prev === -1 || nums[i] > nums[prev]) {
      take = 1 + go(i + 1, i);
    }
    return Math.max(skip, take);
  }
  return go(0, -1);
}


// Method 2: Optimal
// Time: O(n^2) | Space: O(n)
// len[i] is the longest increasing subsequence that ends at i. Each pair (j, i) with j < i is checked once. n^2 states of work, one array of n cells. Standard interview DP.

function lengthOfLIS(nums) {
  const n = nums.length;
  if (n === 0) return 0;
  const len = Array(n).fill(1);
  let best = 1;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < i; j++) {
      if (nums[j] < nums[i]) {
        len[i] = Math.max(len[i], len[j] + 1);
      }
    }
    best = Math.max(best, len[i]);
  }
  return best;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// tails[k] is the smallest tail of all increasing subsequences of length k+1. For each number, binary search the first tail that is >= num and replace it (or append). Length of tails is the LIS length. Tails is not the LIS itself.

function lengthOfLIS(nums) {
  const tails = [];
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    let left = 0;
    let right = tails.length;
    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (tails[mid] < num) left = mid + 1;
      else right = mid;
    }
    if (left === tails.length) tails.push(num);
    else tails[left] = num;
  }
  return tails.length;
}
