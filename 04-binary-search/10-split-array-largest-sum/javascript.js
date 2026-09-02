// Method 1: Brute
// Time: O(n^{k-1}) | Space: O(n)
// Recurse on the start index and how many pieces are left. Try every next cut. Exponential in k. Good for explaining the search tree, not for n = 1000.

function splitArray(nums, k) {
  const n = nums.length;
  const inf = 1e15;
  function go(i, left) {
    if (left === 1) {
      let s = 0;
      for (let t = i; t < n; t++) s += nums[t];
      return s;
    }
    let best = inf, run = 0;
    for (let j = i; j <= n - left; j++) {
      run += nums[j];
      const rest = go(j + 1, left - 1);
      const cost = run > rest ? run : rest;
      if (cost < best) best = cost;
    }
    return best;
  }
  return go(0, k);
}


// Method 2: Optimal
// Time: O(n^2 k) | Space: O(n k)
// dp[i][p] = min largest-sum using the first i numbers and p subarrays. Transition: last piece is nums[j..i-1], cost = max(dp[j][p-1], prefix[i]-prefix[j]). Polynomial, still slower than binary search for interview n.

function splitArray(nums, k) {
  const n = nums.length;
  const prefix = Array(n + 1).fill(0);
  for (let i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
  const inf = 1e15;
  const dp = Array.from({ length: n + 1 }, function () {
    return Array(k + 1).fill(inf);
  });
  dp[0][0] = 0;
  for (let i = 1; i <= n; i++) {
    for (let p = 1; p <= k && p <= i; p++) {
      for (let j = p - 1; j < i; j++) {
        const piece = prefix[i] - prefix[j];
        const cost = dp[j][p - 1] > piece ? dp[j][p - 1] : piece;
        if (cost < dp[i][p]) dp[i][p] = cost;
      }
    }
  }
  return dp[n][k];
}


// Method 3: More optimal
// Time: O(n log sum) | Space: O(1)
// Binary search the largest allowed piece sum. Greedy: grow a run until the next number would exceed mid, then start a new piece. If you need more than k pieces, mid is too small. This is the usual interview solution.

function splitArray(nums, k) {
  function ok(lim) {
    let pieces = 1, run = 0;
    for (let i = 0; i < nums.length; i++) {
      if (nums[i] > lim) return false;
      if (run + nums[i] > lim) {
        pieces++;
        run = 0;
        if (pieces > k) return false;
      }
      run += nums[i];
    }
    return true;
  }
  let lo = 0, hi = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > lo) lo = nums[i];
    hi += nums[i];
  }
  while (lo < hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
