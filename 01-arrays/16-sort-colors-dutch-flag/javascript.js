// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Generic sort does not use the fact there are only three values. Engine sort also uses extra memory.
// How it works: nums.sort with a numeric comparator. Correct, but not the point of the problem.

function sortColors(nums) {
  nums.sort(function (a, b) { return a - b; });
  return nums;
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// Two linear passes and three counters. Extra memory is three integers.
// How it works: count zeros, ones, and twos. Write that many 0s, then 1s, then 2s into nums.

function sortColors(nums) {
  let zeros = 0;
  let ones = 0;
  let twos = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === 0) zeros++;
    else if (nums[i] === 1) ones++;
    else twos++;
  }
  let i = 0;
  while (zeros--) nums[i++] = 0;
  while (ones--) nums[i++] = 1;
  while (twos--) nums[i++] = 2;
  return nums;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pass, constant extra memory. Each index is visited a constant number of times.
// How it works: low writes 0s, high writes 2s, mid walks. After a swap with high, mid stays so the swapped-in value is classified.

function sortColors(nums) {
  let low = 0;
  let mid = 0;
  let high = nums.length - 1;
  while (mid <= high) {
    if (nums[mid] === 0) {
      const t = nums[low];
      nums[low] = nums[mid];
      nums[mid] = t;
      low++;
      mid++;
    } else if (nums[mid] === 2) {
      const t = nums[high];
      nums[high] = nums[mid];
      nums[mid] = t;
      high--;
    } else {
      mid++;
    }
  }
  return nums;
}
