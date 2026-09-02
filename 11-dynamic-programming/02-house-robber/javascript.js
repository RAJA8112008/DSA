// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Every house branches into take or skip with no cache, so the tree is exponential. The stack is one frame per house along a path.

function rob(nums) {
  function go(i) {
    if (i >= nums.length) return 0;
    const take = nums[i] + go(i + 2);
    const skip = go(i + 1);
    return Math.max(take, skip);
  }
  return go(0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// best[i] is the best total using the first i houses. Each i is filled from i-1 and i-2 in constant time. n states, linear time and linear extra memory.

function rob(nums) {
  const n = nums.length;
  const best = Array(n + 1).fill(0);
  for (let i = 1; i <= n; i++) {
    const take = nums[i - 1] + (i >= 2 ? best[i - 2] : 0);
    const skip = best[i - 1];
    best[i] = Math.max(take, skip);
  }
  return best[n];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only skip (best without the previous house as a take-chain) and take (best that used the previous house) are live. One pass updates both. Same linear scan, constant extra memory.

function rob(nums) {
  let skip = 0;
  let take = 0;
  for (let i = 0; i < nums.length; i++) {
    const nextTake = skip + nums[i];
    skip = Math.max(skip, take);
    take = nextTake;
  }
  return Math.max(skip, take);
}
