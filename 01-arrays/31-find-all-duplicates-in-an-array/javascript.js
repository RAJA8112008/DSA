// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each value, count how many times it appears. Push it once if the count is 2. Slow, no extra set.

function findDuplicates(nums) {
  const out = [];
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    let c = 0;
    for (let j = 0; j < n; j++) if (nums[j] === nums[i]) c++;
    if (c === 2) {
      let seen = false;
      for (let k = 0; k < out.length; k++) if (out[k] === nums[i]) seen = true;
      if (!seen) out.push(nums[i]);
    }
  }
  return out;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(1) extra
// Sort, then walk adjacent pairs. Equal neighbors are a duplicate. Simple, mutates order.

function findDuplicates(nums) {
  const a = nums.slice().sort(function (x, y) { return x - y; });
  const out = [];
  for (let i = 1; i < a.length; i++) {
    if (a[i] === a[i - 1]) out.push(a[i]);
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra
// Value x belongs at index x-1. Negate that slot when you first see x. If it is already negative, x is the duplicate. Restore signs later if you must.

function findDuplicates(nums) {
  const out = [];
  for (let i = 0; i < nums.length; i++) {
    const x = nums[i] < 0 ? -nums[i] : nums[i];
    const slot = x - 1;
    if (nums[slot] < 0) out.push(x);
    else nums[slot] = -nums[slot];
  }
  return out;
}
