// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each item is taken or skipped. No cache. Exponential in the number of items. Depth is n.

function knapsack(values, weights, capacity) {
  function go(i, remain) {
    if (i === values.length) return 0;
    const skip = go(i + 1, remain);
    let take = 0;
    if (weights[i] <= remain) {
      take = values[i] + go(i + 1, remain - weights[i]);
    }
    return Math.max(skip, take);
  }
  return go(0, capacity);
}


// Method 2: Optimal
// Time: O(n * W) | Space: O(n * W)
// Full table: n+1 rows, W+1 columns. Each cell is a max of skip and take. W is capacity. This is the picture you should be able to fill by hand.

function knapsack(values, weights, capacity) {
  const n = values.length;
  const dp = Array.from({ length: n + 1 }, function () {
    return Array(capacity + 1).fill(0);
  });
  for (let i = 1; i <= n; i++) {
    for (let w = 0; w <= capacity; w++) {
      dp[i][w] = dp[i - 1][w];
      if (weights[i - 1] <= w) {
        const take = dp[i - 1][w - weights[i - 1]] + values[i - 1];
        dp[i][w] = Math.max(dp[i][w], take);
      }
    }
  }
  return dp[n][capacity];
}


// Method 3: More optimal
// Time: O(n * W) | Space: O(W)
// One row of size W+1. Inner loop walks capacity from high to low so best[w - weight] is still the previous item’s row. Forward would reuse the same item (unbounded).

function knapsack(values, weights, capacity) {
  const best = Array(capacity + 1).fill(0);
  for (let i = 0; i < values.length; i++) {
    for (let w = capacity; w >= weights[i]; w--) {
      best[w] = Math.max(best[w], best[w - weights[i]] + values[i]);
    }
  }
  return best[capacity];
}
