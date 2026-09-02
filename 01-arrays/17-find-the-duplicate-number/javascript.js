// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each index you scan the rest of the list looking for the same value.
// How it works: if nums[j] === nums[i] for j > i, that value is the duplicate.

function findDuplicate(nums) {
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      if (nums[i] === nums[j]) return nums[i];
    }
  }
  return -1;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Copy and sort, then scan neighbors. Sorting dominates. Extra memory is the copy (input stays unchanged).
// How it works: after sort, the repeated number sits next to itself.

function findDuplicate(nums) {
  const copy = nums.slice().sort(function (a, b) { return a - b; });
  for (let i = 1; i < copy.length; i++) {
    if (copy[i] === copy[i - 1]) return copy[i];
  }
  return -1;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Floyd cycle detection. Values in 1..n act as next pointers, so a duplicate creates a cycle. No extra array, input not written.
// How it works: slow moves one hop, fast moves two, until they meet. Reset slow to the start; the next meeting is the cycle entrance, which is the duplicate.

function findDuplicate(nums) {
  let slow = nums[0];
  let fast = nums[0];
  do {
    slow = nums[slow];
    fast = nums[nums[fast]];
  } while (slow !== fast);
  slow = nums[0];
  while (slow !== fast) {
    slow = nums[slow];
    fast = nums[fast];
  }
  return slow;
}
