// Method 1: Brute
// Time: O(n! · n) | Space: O(n! · n)
// All unique permutations are generated and stored. n! grows immediately out of interview time limits.
// How it works: backtracking builds every perm. Sort the bag lexicographically. Find the current sequence and copy the next one (or the first) back into nums.

function nextPermutation(nums) {
  const n = nums.length;
  const start = nums.slice();
  const bag = [];

  function permute(arr, from) {
    if (from === n) {
      bag.push(arr.slice());
      return;
    }
    const used = new Set();
    for (let i = from; i < n; i++) {
      if (used.has(arr[i])) continue;
      used.add(arr[i]);
      const t = arr[from];
      arr[from] = arr[i];
      arr[i] = t;
      permute(arr, from + 1);
      arr[i] = arr[from];
      arr[from] = t;
    }
  }

  permute(nums.slice(), 0);
  bag.sort(function (a, b) {
    for (let i = 0; i < n; i++) {
      if (a[i] !== b[i]) return a[i] - b[i];
    }
    return 0;
  });

  let idx = 0;
  for (let i = 0; i < bag.length; i++) {
    let same = true;
    for (let j = 0; j < n; j++) {
      if (bag[i][j] !== start[j]) { same = false; break; }
    }
    if (same) { idx = i; break; }
  }
  const next = bag[(idx + 1) % bag.length];
  for (let i = 0; i < n; i++) nums[i] = next[i];
  return nums;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(1)
// One reverse scan for the pivot, then a sort of the suffix. Sort of n items is the extra log factor.
// How it works: find the rightmost i with nums[i] < nums[i+1]. Find the smallest value to the right that is still larger than nums[i], swap, then sort the suffix ascending.

function nextPermutation(nums) {
  const n = nums.length;
  let i = n - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) i--;
  if (i >= 0) {
    let j = n - 1;
    while (nums[j] <= nums[i]) j--;
    const t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }
  const suffix = nums.slice(i + 1).sort(function (a, b) { return a - b; });
  for (let k = 0; k < suffix.length; k++) nums[i + 1 + k] = suffix[k];
  return nums;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// The suffix is already non-increasing, so reverse is enough instead of sort.
// How it works: same pivot and swap. Reverse nums[i+1 .. end] in place.

function nextPermutation(nums) {
  const n = nums.length;
  let i = n - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) i--;

  function reverse(left, right) {
    while (left < right) {
      const t = nums[left];
      nums[left] = nums[right];
      nums[right] = t;
      left++;
      right--;
    }
  }

  if (i >= 0) {
    let j = n - 1;
    while (nums[j] <= nums[i]) j--;
    const t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }
  reverse(i + 1, n - 1);
  return nums;
}
