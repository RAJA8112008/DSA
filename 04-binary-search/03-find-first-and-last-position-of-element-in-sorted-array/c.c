// Method 1: Brute
// Time: O(n) | Space: O(1)
// One left-to-right pass. First time you see target, store i. Every time you see it, update last. Missing target leaves both at -1.

void searchRange(int* nums, int n, int target, int* first, int* last) {
  *first = *last = -1;
  for (int i = 0; i < n; i++) if (nums[i] == target) {
    if (*first < 0) *first = i;
    *last = i;
  }
}


// Method 2: Optimal
// Time: O(log n) | Space: O(1)
// Two binary searches. When mid equals target, first-occurrence keeps searching left (hi = mid - 1) and last-occurrence keeps searching right (lo = mid + 1). Each is O(log n).

int findOcc(int* nums, int n, int target, int first) {
  int lo = 0, hi = n - 1, ans = -1;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (nums[mid] == target) {
      ans = mid;
      if (first) hi = mid - 1;
      else lo = mid + 1;
    } else if (nums[mid] < target) lo = mid + 1;
    else hi = mid - 1;
  }
  return ans;
}
void searchRange(int* nums, int n, int target, int* first, int* last) {
  *first = findOcc(nums, n, target, 1);
  *last = findOcc(nums, n, target, 0);
}


// Method 3: More optimal
// Time: O(log n) | Space: O(1)
// Lower bound (first >= target) and upper bound (first > target). Last index is upper - 1. Overflow-safe mid. One helper, two flags, no extra ans in the loop.

int bound(int* nums, int n, int target, int gt) {
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (nums[mid] < target || (gt && nums[mid] == target)) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}
void searchRange(int* nums, int n, int target, int* first, int* last) {
  int L = bound(nums, n, target, 0);
  if (L == n || nums[L] != target) { *first = *last = -1; return; }
  *first = L;
  *last = bound(nums, n, target, 1) - 1;
}
