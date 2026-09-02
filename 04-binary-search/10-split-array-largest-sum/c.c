// Method 1: Brute
// Time: O(n^{k-1}) | Space: O(n)
// Recurse on the start index and how many pieces are left. Try every next cut. Exponential in k. Good for explaining the search tree, not for n = 1000.

long long goSplit(int* nums, int n, int i, int left) {
  if (left == 1) {
    long long s = 0;
    for (int t = i; t < n; t++) s += nums[t];
    return s;
  }
  long long best = 1000000000000000LL, run = 0;
  for (int j = i; j <= n - left; j++) {
    run += nums[j];
    long long rest = goSplit(nums, n, j + 1, left - 1);
    long long cost = run > rest ? run : rest;
    if (cost < best) best = cost;
  }
  return best;
}
int splitArray(int* nums, int n, int k) {
  return (int)goSplit(nums, n, 0, k);
}


// Method 2: Optimal
// Time: O(n^2 k) | Space: O(n k)
// dp[i][p] = min largest-sum using the first i numbers and p subarrays. Transition: last piece is nums[j..i-1], cost = max(dp[j][p-1], prefix[i]-prefix[j]). Polynomial, still slower than binary search for interview n.

#include <stdlib.h>
int splitArray(int* nums, int n, int k) {
  long long* prefix = (long long*)calloc(n + 1, sizeof(long long));
  for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
  long long inf = 1000000000000000LL;
  int cells = (n + 1) * (k + 1);
  long long* dp = (long long*)malloc(sizeof(long long) * cells);
  for (int i = 0; i < cells; i++) dp[i] = inf;
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int p = 1; p <= k && p <= i; p++) {
      for (int j = p - 1; j < i; j++) {
        long long piece = prefix[i] - prefix[j];
        long long prev = dp[j * (k + 1) + (p - 1)];
        long long cost = prev > piece ? prev : piece;
        int idx = i * (k + 1) + p;
        if (cost < dp[idx]) dp[idx] = cost;
      }
    }
  }
  int ans = (int)dp[n * (k + 1) + k];
  free(prefix); free(dp);
  return ans;
}


// Method 3: More optimal
// Time: O(n log sum) | Space: O(1)
// Binary search the largest allowed piece sum. Greedy: grow a run until the next number would exceed mid, then start a new piece. If you need more than k pieces, mid is too small. This is the usual interview solution.

int okSplit(int* nums, int n, int k, int lim) {
  int pieces = 1, run = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] > lim) return 0;
    if (run + nums[i] > lim) {
      pieces++; run = 0;
      if (pieces > k) return 0;
    }
    run += nums[i];
  }
  return 1;
}
int splitArray(int* nums, int n, int k) {
  int lo = 0, hi = 0;
  for (int i = 0; i < n; i++) { if (nums[i] > lo) lo = nums[i]; hi += nums[i]; }
  while (lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (okSplit(nums, n, k, mid)) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
