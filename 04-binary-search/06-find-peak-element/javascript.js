// Method 1: Brute
// Time: O(n) | Space: O(1)
// Check each index against its neighbors. First (or any) success is a peak. Ends only need one comparison. Simple, not log n.

function findPeakElement(nums) {
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    const leftOk = i === 0 || nums[i] > nums[i - 1];
    const rightOk = i === n - 1 || nums[i] > nums[i + 1];
    if (leftOk && rightOk) return i;
  }
  return 0;
}


// Method 2: Optimal
// Time: O(log n) | Space: O(1)
// Slope test: if mid is less than mid + 1, drop the left (including mid). Else drop the right. The remaining range always contains a peak because the ends behave like -infinity.

function findPeakElement(nums) {
  let lo = 0, hi = nums.length - 1;
  while (lo < hi) {
    const mid = (lo + hi) >> 1;
    if (nums[mid] < nums[mid + 1]) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}


// Method 3: More optimal
// Time: O(log n) | Space: O(log n)
// Same slope rule as a recursive function. Overflow-safe mid. The extra space is the call stack of log n frames. Iterative is usually preferred; this is the form you write if they ask for recursion.

function findPeakElement(nums) {
  function go(lo, hi) {
    if (lo === hi) return lo;
    const mid = lo + ((hi - lo) >> 1);
    if (nums[mid] < nums[mid + 1]) return go(mid + 1, hi);
    return go(lo, mid);
  }
  return go(0, nums.length - 1);
}
