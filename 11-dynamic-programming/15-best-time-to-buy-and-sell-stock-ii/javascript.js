// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// At each day you skip, buy, or sell depending on holding. Two branches most days, no cache. Exponential in the number of days.

function maxProfit(prices) {
  function go(i, holding) {
    if (i === prices.length) return 0;
    if (holding) {
      const sell = prices[i] + go(i + 1, 0);
      const keep = go(i + 1, 1);
      return Math.max(sell, keep);
    }
    const buy = -prices[i] + go(i + 1, 1);
    const skip = go(i + 1, 0);
    return Math.max(buy, skip);
  }
  return go(0, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// cash[i] is best profit ending day i with no share. hold[i] is best ending day i with a share. Transitions are skip vs sell, and skip vs buy. n days, two arrays.

function maxProfit(prices) {
  const n = prices.length;
  if (n === 0) return 0;
  const cash = Array(n).fill(0);
  const hold = Array(n).fill(0);
  hold[0] = -prices[0];
  for (let i = 1; i < n; i++) {
    cash[i] = Math.max(cash[i - 1], hold[i - 1] + prices[i]);
    hold[i] = Math.max(hold[i - 1], cash[i - 1] - prices[i]);
  }
  return cash[n - 1];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Every profitable adjacent difference can be taken. That sum equals the DP. One pass, no extra arrays. Mention this is the space-cut of the two-state DP, not a different problem.

function maxProfit(prices) {
  let profit = 0;
  for (let i = 1; i < prices.length; i++) {
    if (prices[i] > prices[i - 1]) {
      profit += prices[i] - prices[i - 1];
    }
  }
  return profit;
}
