// Method 1: Brute
// Time: O(n) | Space: O(1)
// Track the smallest value while walking. Rotation does not matter. This is the check you mention, then you switch to log n.

int findMin(int* nums, int n) {
  int best = nums[0];
  for (int i = 1; i < n; i++) if (nums[i] < best) best = nums[i];
  return best;
}


// Method 2: Optimal
// Time: O(log n) | Space: O(1)
// Compare mid with the right end. A drop after mid means the pivot is to the right. No drop means the pivot is mid or left. Unique values keep this strictly log n.

int findMin(int* nums, int n) {
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (nums[mid] > nums[hi]) lo = mid + 1;
    else hi = mid;
  }
  return nums[lo];
}


// Method 3: More optimal
// Time: O(log n) | Space: O(1)
// Overflow-safe mid. If nums[lo] <= nums[hi], the remaining slice is already sorted, so nums[lo] is the min and you can stop. Helps the no-rotation case in one check.

int findMin(int* nums, int n) {
  int lo = 0, hi = n - 1;
  while (lo < hi) {
    if (nums[lo] <= nums[hi]) return nums[lo];
    int mid = lo + ((hi - lo) >> 1);
    if (nums[mid] > nums[hi]) lo = mid + 1;
    else hi = mid;
  }
  return nums[lo];
}
