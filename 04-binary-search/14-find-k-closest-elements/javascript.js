// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Pair each value with its distance, sort by distance then by value, take k items, sort those k again so the answer is ascending. Heavy, but matches the tie rule clearly.

function findClosestElements(arr, k, x) {
  const idx = [];
  for (let i = 0; i < arr.length; i++) idx.push(i);
  idx.sort(function (i, j) {
    const di = Math.abs(arr[i] - x), dj = Math.abs(arr[j] - x);
    if (di !== dj) return di - dj;
    return arr[i] - arr[j];
  });
  const pick = idx.slice(0, k).map(function (i) { return arr[i]; });
  pick.sort(function (a, b) { return a - b; });
  return pick;
}


// Method 2: Optimal
// Time: O(n - k) | Space: O(k)
// The answer is a contiguous window of length k (the array is sorted). Shrink from both ends until the window is size k. Drop the farther end; on a tie drop the right (larger) value.

function findClosestElements(arr, k, x) {
  let lo = 0, hi = arr.length - 1;
  while (hi - lo + 1 > k) {
    if (Math.abs(arr[lo] - x) > Math.abs(arr[hi] - x)) lo++;
    else hi--;
  }
  return arr.slice(lo, hi + 1);
}


// Method 3: More optimal
// Time: O(log(n - k) + k) | Space: O(k)
// Binary search the left index of the k-window in [0, n-k]. If x is closer to arr[mid+k] than to arr[mid], the window should start further right. Overflow-safe mid. Copy k values at the end.

function findClosestElements(arr, k, x) {
  let lo = 0, hi = arr.length - k;
  while (lo < hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (x - arr[mid] > arr[mid + k] - x) lo = mid + 1;
    else hi = mid;
  }
  return arr.slice(lo, lo + k);
}
