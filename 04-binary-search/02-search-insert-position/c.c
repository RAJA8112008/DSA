// Method 1: Brute
// Time: O(n) | Space: O(1)
// The first index with nums[i] >= target is the insert slot. If none exist, insert at n. Fine for tiny n; too slow when they ask for log n.

int searchInsert(int* nums, int n, int target) {
  for (int i = 0; i < n; i++) if (nums[i] >= target) return i;
  return n;
}


// Method 2: Optimal
// Time: O(log n) | Space: O(1)
// Track the best insert index seen so far. When mid is >= target, mid is a candidate and you search left. When mid is smaller, the slot is strictly right of mid.

int searchInsert(int* nums, int n, int target) {
  int lo = 0, hi = n - 1, ans = n;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (nums[mid] >= target) { ans = mid; hi = mid - 1; }
    else lo = mid + 1;
  }
  return ans;
}


// Method 3: More optimal
// Time: O(log n) | Space: O(1)
// Half-open [lo, hi) with hi = n. No extra ans variable: when the loop ends, lo is the first index >= target. Overflow-safe mid.

int searchInsert(int* nums, int n, int target) {
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (nums[mid] < target) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}
