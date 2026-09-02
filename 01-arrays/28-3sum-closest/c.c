// Method 1: Brute
// Time: O(n³) | Space: O(1)
// Every triple, track the sum whose absolute gap to target is smallest.

int threeSumClosest(int* nums, int n, int target) {
  int i, j, k, best = nums[0] + nums[1] + nums[2];
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      for (k = j + 1; k < n; k++) {
        int s = nums[i] + nums[j] + nums[k];
        int d1 = s - target; if (d1 < 0) d1 = -d1;
        int d2 = best - target; if (d2 < 0) d2 = -d2;
        if (d1 < d2) best = s;
      }
  return best;
}


// Method 2: Optimal
// Time: O(n² log n) | Space: O(n)
// Sort. Fix two indexes, binary search the value closest to the leftover. Extra log n on each pair.

/* sort, then two loops plus binary search for the third value */


// Method 3: More optimal
// Time: O(n²) | Space: O(1) extra
// Sort. Fix i. Two pointers on the rest. Move the side that improves the sum. Track the closest. Stop early on an exact hit.

int cmpInt(const void* a, const void* b) { return *(const int*)a - *(const int*)b; }
int threeSumClosest(int* nums, int n, int target) {
  int i, L, R, best;
  qsort(nums, n, sizeof(int), cmpInt);
  best = nums[0] + nums[1] + nums[2];
  for (i = 0; i < n; i++) {
    L = i + 1; R = n - 1;
    while (L < R) {
      int s = nums[i] + nums[L] + nums[R];
      int d1 = s - target; if (d1 < 0) d1 = -d1;
      int d2 = best - target; if (d2 < 0) d2 = -d2;
      if (d1 < d2) best = s;
      if (s == target) return s;
      if (s < target) L++;
      else R--;
    }
  }
  return best;
}
