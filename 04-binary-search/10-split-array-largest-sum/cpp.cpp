// Method 1: Brute
// Time: O(n^{k-1}) | Space: O(n)
// Recurse on the start index and how many pieces are left. Try every next cut. Exponential in k. Good for explaining the search tree, not for n = 1000.

class Solution {
  long long go(vector<int>& nums, int i, int left) {
    int n = (int)nums.size();
    if (left == 1) {
      long long s = 0;
      for (int t = i; t < n; t++) s += nums[t];
      return s;
    }
    long long best = (1LL << 60), run = 0;
    for (int j = i; j <= n - left; j++) {
      run += nums[j];
      long long rest = go(nums, j + 1, left - 1);
      long long cost = run > rest ? run : rest;
      if (cost < best) best = cost;
    }
    return best;
  }
public:
  int splitArray(vector<int>& nums, int k) {
    return (int)go(nums, 0, k);
  }
};


// Method 2: Optimal
// Time: O(n^2 k) | Space: O(n k)
// dp[i][p] = min largest-sum using the first i numbers and p subarrays. Transition: last piece is nums[j..i-1], cost = max(dp[j][p-1], prefix[i]-prefix[j]). Polynomial, still slower than binary search for interview n.

class Solution {
public:
  int splitArray(vector<int>& nums, int k) {
    int n = (int)nums.size();
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
    const long long inf = (1LL << 60);
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int p = 1; p <= k && p <= i; p++) {
        for (int j = p - 1; j < i; j++) {
          long long piece = prefix[i] - prefix[j];
          long long cost = dp[j][p - 1] > piece ? dp[j][p - 1] : piece;
          if (cost < dp[i][p]) dp[i][p] = cost;
        }
      }
    }
    return (int)dp[n][k];
  }
};


// Method 3: More optimal
// Time: O(n log sum) | Space: O(1)
// Binary search the largest allowed piece sum. Greedy: grow a run until the next number would exceed mid, then start a new piece. If you need more than k pieces, mid is too small. This is the usual interview solution.

class Solution {
  bool ok(vector<int>& nums, int k, int lim) {
    int pieces = 1, run = 0;
    for (int v : nums) {
      if (v > lim) return false;
      if (run + v > lim) {
        pieces++; run = 0;
        if (pieces > k) return false;
      }
      run += v;
    }
    return true;
  }
public:
  int splitArray(vector<int>& nums, int k) {
    int lo = 0, hi = 0;
    for (int v : nums) { if (v > lo) lo = v; hi += v; }
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (ok(nums, k, mid)) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }
};
