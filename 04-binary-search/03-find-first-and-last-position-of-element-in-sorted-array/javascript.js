// Method 1: Brute
// Time: O(n) | Space: O(1)
// One left-to-right pass. First time you see target, store i. Every time you see it, update last. Missing target leaves both at -1.

function searchRange(nums, target) {
  let first = -1, last = -1;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === target) {
      if (first < 0) first = i;
      last = i;
    }
  }
  return [first, last];
}


// Method 2: Optimal
// Time: O(log n) | Space: O(1)
// Two binary searches. When mid equals target, first-occurrence keeps searching left (hi = mid - 1) and last-occurrence keeps searching right (lo = mid + 1). Each is O(log n).

function searchRange(nums, target) {
  function find(first) {
    let lo = 0, hi = nums.length - 1, ans = -1;
    while (lo <= hi) {
      const mid = (lo + hi) >> 1;
      if (nums[mid] === target) {
        ans = mid;
        if (first) hi = mid - 1;
        else lo = mid + 1;
      } else if (nums[mid] < target) lo = mid + 1;
      else hi = mid - 1;
    }
    return ans;
  }
  return [find(true), find(false)];
}


// Method 3: More optimal
// Time: O(log n) | Space: O(1)
// Lower bound (first >= target) and upper bound (first > target). Last index is upper - 1. Overflow-safe mid. One helper, two flags, no extra ans in the loop.

function searchRange(nums, target) {
  function bound(gt) {
    let lo = 0, hi = nums.length;
    while (lo < hi) {
      const mid = lo + ((hi - lo) >> 1);
      if (nums[mid] < target || (gt && nums[mid] === target)) lo = mid + 1;
      else hi = mid;
    }
    return lo;
  }
  const L = bound(false);
  if (L === nums.length || nums[L] !== target) return [-1, -1];
  return [L, bound(true) - 1];
}
