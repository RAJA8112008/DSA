// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each candidate you count how many times it appears. Quadratic comparisons.
// How it works: if a value’s count is > n/2, return it.

function majorityElement(nums) {
  const n = nums.length;
  const need = Math.floor(n / 2);
  for (let i = 0; i < n; i++) {
    let count = 0;
    for (let j = 0; j < n; j++) {
      if (nums[j] === nums[i]) count++;
    }
    if (count > need) return nums[i];
  }
  return nums[0];
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One pass over the list, extra map of distinct values.
// How it works: increment counts. As soon as a count exceeds n/2, return that key.

function majorityElement(nums) {
  const freq = new Map();
  const need = Math.floor(nums.length / 2);
  for (let i = 0; i < nums.length; i++) {
    const x = nums[i];
    freq.set(x, (freq.get(x) || 0) + 1);
    if (freq.get(x) > need) return x;
  }
  return nums[0];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Boyer–Moore: two integers, one pass. Because a majority exists, the last candidate is it.
// How it works: vote for the current candidate. Matching values add a vote; others subtract. At 0, pick a new candidate.

function majorityElement(nums) {
  let candidate = nums[0];
  let vote = 0;
  for (let i = 0; i < nums.length; i++) {
    if (vote === 0) candidate = nums[i];
    vote += nums[i] === candidate ? 1 : -1;
  }
  return candidate;
}
