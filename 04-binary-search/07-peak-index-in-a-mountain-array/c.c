// Method 1: Brute
// Time: O(n) | Space: O(1)
// The peak is the unique maximum. Track the index of the largest value. Fine for tiny n; they still want log n because n can be 10^5.

int peakIndexInMountainArray(int* arr, int n) {
  int best = 0;
  for (int i = 1; i < n; i++) if (arr[i] > arr[best]) best = i;
  return best;
}


// Method 2: Optimal
// Time: O(log n) | Space: O(1)
// Uphill means lo = mid + 1. Downhill or peak means hi = mid. The two pointers meet on the unique peak. mid + 1 is in range while lo < hi.

int peakIndexInMountainArray(int* arr, int n) {
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (arr[mid] < arr[mid + 1]) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}


// Method 3: More optimal
// Time: O(log n) | Space: O(1)
// Overflow-safe mid. Search inside (0, n-1) because ends cannot be the peak on a mountain. If both neighbors are smaller, return mid immediately.

int peakIndexInMountainArray(int* arr, int n) {
  int lo = 1, hi = n - 2;
  while (lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
    if (arr[mid] < arr[mid + 1]) lo = mid + 1;
    else hi = mid - 1;
  }
  return lo;
}
