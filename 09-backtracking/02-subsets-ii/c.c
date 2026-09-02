// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Build every subset with extra path copies, stringify, and keep a Set. Duplicate work is thrown away after you already built it. Fine for tiny n, not the interview finish.

/* generate all, qsort each subset, skip duplicate prints with a last-key buffer */
void go(int* nums, int n, int i, int* path, int len) {
  int k;
  if (i == n) {
    /* classroom: print; a real unique filter needs a set of sorted tuples */
    printf("[");
    for (k = 0; k < len; k++) { if (k) printf(","); printf("%d", path[k]); }
    printf("]\n");
    return;
  }
  go(nums, n, i + 1, path, len);
  path[len] = nums[i];
  go(nums, n, i + 1, path, len + 1);
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// Sort, then at each start skip nums[i] when it equals nums[i-1]. Those two 2s cannot start the same role twice, so [1,2] appears once. One path, push/pop.

void go(int* nums, int n, int start, int* path, int len) {
  int i, k;
  printf("[");
  for (k = 0; k < len; k++) { if (k) printf(","); printf("%d", path[k]); }
  printf("]\n");
  for (i = start; i < n; i++) {
    if (i > start && nums[i] == nums[i - 1]) continue;
    path[len] = nums[i];
    go(nums, n, i + 1, path, len + 1);
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// Same sort-and-skip, plus you can count how many copies of this value exist and take 0..count in one shot. That collapses a chain of duplicate-index decisions into one loop.

void go(int* nums, int n, int start, int* path, int len) {
  int i, j, t, k, count;
  printf("[");
  for (k = 0; k < len; k++) { if (k) printf(","); printf("%d", path[k]); }
  printf("]\n");
  i = start;
  while (i < n) {
    j = i;
    while (j < n && nums[j] == nums[i]) j++;
    count = j - i;
    for (t = 1; t <= count; t++) {
      path[len + t - 1] = nums[i];
      go(nums, n, j, path, len + t);
    }
    i = j;
  }
}
