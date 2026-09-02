// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each L, grow R, multiply. Count when prod < k. Watch overflow in fixed-width ints; JS numbers are fine for the usual constraints.

function numSubarrayProductLessThanK(nums, k) {
  const n = nums.length;
  let c = 0;
  for (let i = 0; i < n; i++) {
    let p = 1;
    for (let j = i; j < n; j++) {
      p *= nums[j];
      if (p < k) c++;
      else break;
    }
  }
  return c;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(1)
// Same nested loops, but this is already the best brute because products only grow (nums >= 1) so you can break. Still quadratic worst case when k is huge.

function numSubarrayProductLessThanK(nums, k) {
  if (k <= 1) return 0;
  let c = 0;
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    let p = 1;
    for (let j = i; j < n && p * nums[j] < k; j++) {
      p *= nums[j];
      c++;
    }
  }
  return c;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Window [left, right]. Multiply nums[right]. While product >= k, divide nums[left] and left++. Every new right adds (right-left+1) subarrays that end at right. If k <= 1 the answer is 0.

function numSubarrayProductLessThanK(nums, k) {
  if (k <= 1) return 0;
  let prod = 1, left = 0, c = 0;
  for (let right = 0; right < nums.length; right++) {
    prod *= nums[right];
    while (prod >= k) {
      prod /= nums[left];
      left++;
    }
    c += right - left + 1;
  }
  return c;
}
