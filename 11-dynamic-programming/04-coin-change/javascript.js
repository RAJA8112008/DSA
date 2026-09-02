// Method 1: Brute
// Time: O(S^n) | Space: O(amount)
// At every remaining amount you branch on every coin. The tree is huge and repeats the same remain. Depth is at most amount (all 1s). S is amount, n is number of coins.

function coinChange(coins, amount) {
  function go(remain) {
    if (remain === 0) return 0;
    if (remain < 0) return Infinity;
    let best = Infinity;
    for (let i = 0; i < coins.length; i++) {
      const used = go(remain - coins[i]);
      if (used !== Infinity) best = Math.min(best, used + 1);
    }
    return best;
  }
  const ans = go(amount);
  return ans === Infinity ? -1 : ans;
}


// Method 2: Optimal
// Time: O(n * amount) | Space: O(amount)
// Each remaining amount is solved once. Work per state is a loop over n coins. Memo array is size amount+1. Same recurrence as brute, overlapping calls collapsed.

function coinChange(coins, amount) {
  const memo = [];
  function go(remain) {
    if (remain === 0) return 0;
    if (remain < 0) return Infinity;
    if (memo[remain] !== undefined) return memo[remain];
    let best = Infinity;
    for (let i = 0; i < coins.length; i++) {
      const used = go(remain - coins[i]);
      if (used !== Infinity) best = Math.min(best, used + 1);
    }
    memo[remain] = best;
    return best;
  }
  const ans = go(amount);
  return ans === Infinity ? -1 : ans;
}


// Method 3: More optimal
// Time: O(n * amount) | Space: O(amount)
// Bottom-up 1D unbounded knapsack. best[s] is fewest coins for sum s. Filling left to right allows reuse. No recursion. Same asymptotics as memo, cleaner order, no stack.

function coinChange(coins, amount) {
  const best = Array(amount + 1).fill(Infinity);
  best[0] = 0;
  for (let s = 1; s <= amount; s++) {
    for (let i = 0; i < coins.length; i++) {
      const coin = coins[i];
      if (coin <= s) best[s] = Math.min(best[s], best[s - coin] + 1);
    }
  }
  return best[amount] === Infinity ? -1 : best[amount];
}
