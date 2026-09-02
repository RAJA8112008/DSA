// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Every index is take or skip with extra path copies. Keep combinations whose sum is target, unique them with a sorted-tuple Set. Duplicate indexes still explore the full 2^n tree.

void go(int* cands, int n, int i, int sum, int target, int* path, int len) {
  int k;
  if (sum == target) {
    for (k = 0; k < len; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  if (i == n || sum > target) return;
  go(cands, n, i + 1, sum, target, path, len);
  path[len] = cands[i];
  go(cands, n, i + 1, sum + cands[i], target, path, len + 1);
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// Sort. Skip nums[i] == nums[i-1] at the same start so identical values do not start the same role twice. Each index is used at most once (go(i+1)).

void go(int* cands, int n, int start, int remain, int* path, int len) {
  int i, k;
  if (remain == 0) {
    for (k = 0; k < len; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  for (i = start; i < n; i++) {
    if (i > start && cands[i] == cands[i - 1]) continue;
    if (cands[i] > remain) continue;
    path[len] = cands[i];
    go(cands, n, i + 1, remain - cands[i], path, len + 1);
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// After sort, break when cands[i] > remain. Later values are larger, so they cannot help. Same unique combinations, fewer recursive calls.

void go(int* cands, int n, int start, int remain, int* path, int len) {
  int i, k;
  if (remain == 0) {
    for (k = 0; k < len; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  for (i = start; i < n; i++) {
    if (cands[i] > remain) break;
    if (i > start && cands[i] == cands[i - 1]) continue;
    path[len] = cands[i];
    go(cands, n, i + 1, remain - cands[i], path, len + 1);
  }
}
