// Method 1: Brute
// Time: O(n·k) | Space: O(1)
// Each single rotate copies n items. Doing that k times (after k %= n, still up to n-1 times) is O(n²) in the worst case.
// How it works: save the last item, shift everyone right by one, put the saved item at index 0. Repeat k times.

function rotate(nums, k) {
  const n = nums.length;
  if (n === 0) return nums;
  k = k % n;
  for (let step = 0; step < k; step++) {
    const last = nums[n - 1];
    for (let i = n - 1; i > 0; i--) nums[i] = nums[i - 1];
    nums[0] = last;
  }
  return nums;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One extra array of length n, two linear copies.
// How it works: extra[(i + k) % n] = nums[i], then copy extra back into nums.

function rotate(nums, k) {
  const n = nums.length;
  if (n === 0) return nums;
  k = k % n;
  const extra = new Array(n);
  for (let i = 0; i < n; i++) extra[(i + k) % n] = nums[i];
  for (let i = 0; i < n; i++) nums[i] = extra[i];
  return nums;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Each item is swapped a constant number of times. No extra list.
// How it works: reverse the whole array, reverse the first k items, reverse the rest. That is the right rotation.

function rotate(nums, k) {
  const n = nums.length;
  if (n === 0) return nums;
  k = k % n;

  function reverse(left, right) {
    while (left < right) {
      const t = nums[left];
      nums[left] = nums[right];
      nums[right] = t;
      left++;
      right--;
    }
  }

  reverse(0, n - 1);
  reverse(0, k - 1);
  reverse(k, n - 1);
  return nums;
}
