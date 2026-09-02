// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// State is (day, holding, cooldown). Branches are buy/skip/sell. No cache. Exponential in n. Correct, too slow on long price lists.

function maxProfit(prices) {
  function go(i, holding, cooldown) {
    if (i === prices.length) return 0;
    if (holding) {
      const sell = prices[i] + go(i + 1, 0, true);
      const keep = go(i + 1, 1, false);
      return Math.max(sell, keep);
    }
    const skip = go(i + 1, 0, false);
    if (cooldown) return skip;
    const buy = -prices[i] + go(i + 1, 1, false);
    return Math.max(skip, buy);
  }
  return go(0, 0, false);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// hold[i], sold[i], rest[i] are the three states after day i. Each is O(1) from yesterday. n days times 3 cells. This is the table that matches the cooldown rule one-to-one.

function maxProfit(prices) {
  const n = prices.length;
  if (n === 0) return 0;
  const hold = Array(n).fill(0);
  const sold = Array(n).fill(0);
  const rest = Array(n).fill(0);
  hold[0] = -prices[0];
  sold[0] = 0;
  rest[0] = 0;
  for (let i = 1; i < n; i++) {
    hold[i] = Math.max(hold[i - 1], rest[i - 1] - prices[i]);
    sold[i] = hold[i - 1] + prices[i];
    rest[i] = Math.max(rest[i - 1], sold[i - 1]);
  }
  return Math.max(sold[n - 1], rest[n - 1]);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only yesterday’s three numbers are live. Copy them into nextHold, nextSold, nextRest, then slide. Same linear scan, constant extra memory.

function maxProfit(prices) {
  let hold = -Infinity;
  let sold = 0;
  let rest = 0;
  for (let i = 0; i < prices.length; i++) {
    const price = prices[i];
    const nextHold = Math.max(hold, rest - price);
    const nextSold = hold + price;
    const nextRest = Math.max(rest, sold);
    hold = nextHold;
    sold = nextSold;
    rest = nextRest;
  }
  return Math.max(sold, rest);
}
