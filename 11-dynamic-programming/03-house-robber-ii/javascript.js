// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each range is still a take/skip tree with no memo. Two ranges do not change the exponential shape. Stack depth is O(n).

function rob(nums) {
  const n = nums.length;
  if (n === 1) return nums[0];
  function go(i, end) {
    if (i > end) return 0;
    const take = nums[i] + go(i + 2, end);
    const skip = go(i + 1, end);
    return Math.max(take, skip);
  }
  return Math.max(go(0, n - 2), go(1, n - 1));
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Each linear street is the house-robber table. Two passes, each O(n) states. You still store a best[] array per pass. Handles n = 1 before splitting.

function rob(nums) {
  const n = nums.length;
  if (n === 1) return nums[0];
  function robLine(start, end) {
    const len = end - start + 1;
    const best = Array(len).fill(0);
    for (let i = start; i <= end; i++) {
      const j = i - start;
      const take = nums[i] + (j >= 2 ? best[j - 2] : 0);
      const skip = j >= 1 ? best[j - 1] : 0;
      best[j] = Math.max(take, skip);
    }
    return best[len - 1];
  }
  return Math.max(robLine(0, n - 2), robLine(1, n - 1));
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// The same two ranges, each robbed with two rolling numbers. Extra memory no longer depends on n. Time is still two linear scans.

function rob(nums) {
  const n = nums.length;
  if (n === 1) return nums[0];
  function robLine(start, end) {
    let skip = 0;
    let take = 0;
    for (let i = start; i <= end; i++) {
      const nextTake = skip + nums[i];
      skip = Math.max(skip, take);
      take = nextTake;
    }
    return Math.max(skip, take);
  }
  return Math.max(robLine(0, n - 2), robLine(1, n - 1));
}
