// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Copy, sort, then walk looking for the next needed positive. Sorting dominates.
// How it works: ignore non-positives and duplicates. need starts at 1. When you see need, bump it. At the end, need is missing.

function firstMissingPositive(nums) {
  const list = nums.slice().sort(function (a, b) { return a - b; });
  let need = 1;
  for (let i = 0; i < list.length; i++) {
    if (list[i] <= 0) continue;
    if (list[i] === need) need++;
    else if (list[i] > need) return need;
  }
  return need;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One Set of the input, then at most n+1 membership tests.
// How it works: the answer is in 1..n+1. Probe 1, 2, 3, … until a value is not in the set.

function firstMissingPositive(nums) {
  const set = new Set(nums);
  let need = 1;
  while (set.has(need)) need++;
  return need;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Index-as-hash / cyclic placement. Extra memory is a few integers. The input is overwritten.
// How it works: swap nums[i] to index nums[i]-1 while that value is in 1..n and not already home. Then the first i with nums[i] !== i+1 is the missing number; else n+1.

function firstMissingPositive(nums) {
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    while (
      nums[i] >= 1 &&
      nums[i] <= n &&
      nums[nums[i] - 1] !== nums[i]
    ) {
      const dest = nums[i] - 1;
      const t = nums[i];
      nums[i] = nums[dest];
      nums[dest] = t;
    }
  }
  for (let i = 0; i < n; i++) {
    if (nums[i] !== i + 1) return i + 1;
  }
  return n + 1;
}
