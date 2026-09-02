// Method 1: Brute
// Time: O(n^{k-1}) | Space: O(n)
// Recurse on the start index and how many pieces are left. Try every next cut. Exponential in k. Good for explaining the search tree, not for n = 1000.

class Solution {
  long go(int[] nums, int i, int left) {
    int n = nums.length;
    if (left == 1) {
      long s = 0;
      for (int t = i; t < n; t++) s += nums[t];
      return s;
    }
    long best = Long.MAX_VALUE / 4, run = 0;
    for (int j = i; j <= n - left; j++) {
      run += nums[j];
      long rest = go(nums, j + 1, left - 1);
      long cost = Math.max(run, rest);
      if (cost < best) best = cost;
    }
    return best;
  }
  public int splitArray(int[] nums, int k) {
    return (int) go(nums, 0, k);
  }
}


// Method 2: Optimal
// Time: O(n^2 k) | Space: O(n k)
// dp[i][p] = min largest-sum using the first i numbers and p subarrays. Transition: last piece is nums[j..i-1], cost = max(dp[j][p-1], prefix[i]-prefix[j]). Polynomial, still slower than binary search for interview n.

class Solution {
  public int splitArray(int[] nums, int k) {
    int n = nums.length;
    long[] prefix = new long[n + 1];
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
    long inf = Long.MAX_VALUE / 4;
    long[][] dp = new long[n + 1][k + 1];
    for (int i = 0; i <= n; i++) java.util.Arrays.fill(dp[i], inf);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int p = 1; p <= k && p <= i; p++) {
        for (int j = p - 1; j < i; j++) {
          long piece = prefix[i] - prefix[j];
          long cost = Math.max(dp[j][p - 1], piece);
          if (cost < dp[i][p]) dp[i][p] = cost;
        }
      }
    }
    return (int) dp[n][k];
  }
}


// Method 3: More optimal
// Time: O(n log sum) | Space: O(1)
// Binary search the largest allowed piece sum. Greedy: grow a run until the next number would exceed mid, then start a new piece. If you need more than k pieces, mid is too small. This is the usual interview solution.

class Solution {
  boolean ok(int[] nums, int k, int lim) {
    int pieces = 1, run = 0;
    for (int v : nums) {
      if (v > lim) return false;
      if (run + v > lim) {
        pieces++;
        run = 0;
        if (pieces > k) return false;
      }
      run += v;
    }
    return true;
  }
  public int splitArray(int[] nums, int k) {
    int lo = 0, hi = 0;
    for (int v : nums) { if (v > lo) lo = v; hi += v; }
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (ok(nums, k, mid)) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }
}
