// Method 1: Brute
// Time: O(n^4) | Space: O(1) extra
// Four nested indexes. Sort each hit so a set of strings can drop duplicates. Correct and too slow.

/* four nested loops; store unique sorted quadruplets in a small table */


// Method 2: Optimal
// Time: O(n^3) | Space: O(n)
// Fix i, j, k. Look up target - (a+b+c) in a set of values after k. Still cubic, extra set, duplicates need care. A stepping stone to two pointers.

/* three loops plus a linear scan for the partner; skip duplicate quads */


// Method 3: More optimal
// Time: O(n^3) | Space: O(1) extra
// Sort. Fix i and j. Two pointers on the rest. Skip duplicate i, j, left, and right. Use 64-bit sums if the language overflows. This is the expected answer.

void fourSum(int* nums, int n, int target, int out[][4], int* on) {
  /* assume nums already sorted */
  int i, j, L, R;
  *on = 0;
  for (i = 0; i < n; i++) {
    if (i && nums[i] == nums[i - 1]) continue;
    for (j = i + 1; j < n; j++) {
      if (j > i + 1 && nums[j] == nums[j - 1]) continue;
      L = j + 1; R = n - 1;
      while (L < R) {
        int sum = nums[i] + nums[j] + nums[L] + nums[R];
        if (sum == target) {
          out[*on][0] = nums[i]; out[*on][1] = nums[j];
          out[*on][2] = nums[L]; out[*on][3] = nums[R];
          (*on)++; L++; R--;
          while (L < R && nums[L] == nums[L - 1]) L++;
          while (L < R && nums[R] == nums[R + 1]) R--;
        } else if (sum < target) L++;
        else R--;
      }
    }
  }
}
