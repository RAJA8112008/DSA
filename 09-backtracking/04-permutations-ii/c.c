// Method 1: Brute
// Time: O(n * n!) | Space: O(n * n!)
// Generate every leftover-copy permutation, stringify, keep a Set. Duplicate 1s still walk the full n! tree. Extra copies plus the Set.

void go(int* left, int nleft, int* path, int len) {
  int i, k, tmp;
  if (nleft == 0) {
    for (k = 0; k < len; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  for (i = 0; i < nleft; i++) {
    path[len] = left[i];
    tmp = left[i];
    for (k = i; k < nleft - 1; k++) left[k] = left[k + 1];
    go(left, nleft - 1, path, len + 1);
    for (k = nleft - 1; k > i; k--) left[k] = left[k - 1];
    left[i] = tmp;
  }
}


// Method 2: Optimal
// Time: O(n * n!) | Space: O(n)
// Sort so equal values are adjacent. Skip nums[j] when it equals nums[j-1] and used[j-1] is false. That forces a fixed order on identical numbers. One path, used[].

void go(int* nums, int n, int* used, int* path, int len) {
  int j, k;
  if (len == n) {
    for (k = 0; k < n; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  for (j = 0; j < n; j++) {
    if (used[j]) continue;
    if (j > 0 && nums[j] == nums[j - 1] && !used[j - 1]) continue;
    used[j] = 1; path[len] = nums[j];
    go(nums, n, used, path, len + 1);
    used[j] = 0;
  }
}


// Method 3: More optimal
// Time: O(n * n!) | Space: O(n)
// In-place swap. A tiny set of values already swapped into start this round stops identical branches. No sort required. Same unique output, less leftover copying.

void go(int* nums, int n, int start) {
  int i, k, t, ok, p;
  if (start == n) {
    for (k = 0; k < n; k++) printf("%d ", nums[k]);
    printf("\n");
    return;
  }
  for (i = start; i < n; i++) {
    ok = 1;
    for (p = start; p < i; p++) if (nums[p] == nums[i]) { ok = 0; break; }
    if (!ok) continue;
    t = nums[start]; nums[start] = nums[i]; nums[i] = t;
    go(nums, n, start + 1);
    t = nums[start]; nums[start] = nums[i]; nums[i] = t;
  }
}
