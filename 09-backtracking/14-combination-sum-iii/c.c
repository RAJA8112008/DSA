// Method 1: Brute
// Time: O(C(9, k) * k) | Space: O(k)
// Generate every k-subset with path copies, then filter by sum. C(9,k) is tiny, but you still build losers and copy arrays on every call.

void go(int start, int k, int n, int* path, int len) {
  int x, i, sum;
  if (len == k) {
    sum = 0; for (i = 0; i < len; i++) sum += path[i];
    if (sum == n) { for (i = 0; i < len; i++) printf("%d ", path[i]); printf("\n"); }
    return;
  }
  for (x = start; x <= 9; x++) { path[len] = x; go(x + 1, k, n, path, len + 1); }
}


// Method 2: Optimal
// Time: O(C(9, k) * k) | Space: O(k)
// One path. Push x, remain -= x, recurse x+1, pop. Snapshot when k numbers are chosen and remain is 0. No extra copies on internal nodes.

void go(int start, int left, int remain, int* path, int len) {
  int x, i;
  if (left == 0) {
    if (remain == 0) { for (i = 0; i < len; i++) printf("%d ", path[i]); printf("\n"); }
    return;
  }
  for (x = start; x <= 9; x++) { path[len] = x; go(x + 1, left - 1, remain - x, path, len + 1); }
}


// Method 3: More optimal
// Time: O(C(9, k) * k) | Space: O(k)
// Prune: remain < 0, or remain bigger than the largest left numbers, or remain smaller than the smallest left numbers. Stop the loop when x itself is already too big.

void go(int start, int left, int remain, int* path, int len) {
  int x, i, minSum, maxSum;
  if (left == 0) {
    if (remain == 0) { for (i = 0; i < len; i++) printf("%d ", path[i]); printf("\n"); }
    return;
  }
  minSum = left * (2 * start + left - 1) / 2;
  maxSum = left * (2 * 9 - left + 1) / 2;
  if (remain < minSum || remain > maxSum) return;
  for (x = start; x <= 9; x++) {
    if (x > remain) break;
    path[len] = x;
    go(x + 1, left - 1, remain - x, path, len + 1);
  }
}
