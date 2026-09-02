// Method 1: Brute
// Time: O(n^{target/min}) | Space: O(target/min)
// Every call copies path.concat. You keep going while the sum is not past target, with no sort prune. Extra arrays at every node. Correct but heavy.

void go(int* cands, int n, int start, int sum, int target, int* path, int len) {
  int i, k;
  if (sum == target) {
    for (k = 0; k < len; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  if (sum > target) return;
  for (i = start; i < n; i++) {
    path[len] = cands[i];
    go(cands, n, i, sum + cands[i], target, path, len + 1);
  }
}


// Method 2: Optimal
// Time: O(n^{target/min}) | Space: O(target/min)
// One path, push/pop. remain shrinks. Call go(i, remain - cands[i]) to reuse this value, or move to i+1 to skip. Copy only at remain == 0.

void go(int* cands, int n, int i, int remain, int* path, int len) {
  int k;
  if (remain == 0) {
    for (k = 0; k < len; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  if (i == n || remain < 0) return;
  go(cands, n, i + 1, remain, path, len);
  path[len] = cands[i];
  go(cands, n, i, remain - cands[i], path, len + 1);
}


// Method 3: More optimal
// Time: O(n^{target/min}) | Space: O(target/min)
// Sort first. In the for-loop, break when cands[i] > remain so larger later values are never tried. Same answers, fewer dead branches.

void go(int* cands, int n, int start, int remain, int* path, int len) {
  int i, k;
  if (remain == 0) {
    for (k = 0; k < len; k++) printf("%d ", path[k]);
    printf("\n");
    return;
  }
  for (i = start; i < n; i++) {
    if (cands[i] > remain) break;
    path[len] = cands[i];
    go(cands, n, i, remain - cands[i], path, len + 1);
  }
}
