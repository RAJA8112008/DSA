// Method 1: Brute
// Time: O(n) | Space: O(1)
// The peak is the unique maximum. Track the index of the largest value. Fine for tiny n; they still want log n because n can be 10^5.

function peakIndexInMountainArray(arr) {
  let best = 0;
  for (let i = 1; i < arr.length; i++) if (arr[i] > arr[best]) best = i;
  return best;
}


// Method 2: Optimal
// Time: O(log n) | Space: O(1)
// Uphill means lo = mid + 1. Downhill or peak means hi = mid. The two pointers meet on the unique peak. mid + 1 is in range while lo < hi.

function peakIndexInMountainArray(arr) {
  let lo = 0, hi = arr.length - 1;
  while (lo < hi) {
    const mid = (lo + hi) >> 1;
    if (arr[mid] < arr[mid + 1]) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}


// Method 3: More optimal
// Time: O(log n) | Space: O(1)
// Overflow-safe mid. Search inside (0, n-1) because ends cannot be the peak on a mountain. If both neighbors are smaller, return mid immediately.

function peakIndexInMountainArray(arr) {
  let lo = 1, hi = arr.length - 2;
  while (lo <= hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
    if (arr[mid] < arr[mid + 1]) lo = mid + 1;
    else hi = mid - 1;
  }
  return lo;
}
