// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each value, count how many times it appears. Push it once if the count is 2. Slow, no extra set.

int findDuplicates(int* nums, int n, int* out) {
  int i, j, on = 0;
  for (i = 0; i < n; i++) {
    int c = 0, seen = 0, k;
    for (j = 0; j < n; j++) if (nums[j] == nums[i]) c++;
    if (c != 2) continue;
    for (k = 0; k < on; k++) if (out[k] == nums[i]) seen = 1;
    if (!seen) out[on++] = nums[i];
  }
  return on;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(1) extra
// Sort, then walk adjacent pairs. Equal neighbors are a duplicate. Simple, mutates order.

int cmpInt(const void* a, const void* b) { return *(const int*)a - *(const int*)b; }
int findDuplicates(int* nums, int n, int* out) {
  int i, on = 0;
  qsort(nums, n, sizeof(int), cmpInt);
  for (i = 1; i < n; i++) if (nums[i] == nums[i - 1]) out[on++] = nums[i];
  return on;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra
// Value x belongs at index x-1. Negate that slot when you first see x. If it is already negative, x is the duplicate. Restore signs later if you must.

int findDuplicatesMark(int* nums, int n, int* out) {
  int i, on = 0;
  for (i = 0; i < n; i++) {
    int x = nums[i] < 0 ? -nums[i] : nums[i];
    int slot = x - 1;
    if (nums[slot] < 0) out[on++] = x;
    else nums[slot] = -nums[slot];
  }
  return on;
}
