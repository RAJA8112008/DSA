// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each buy day you scan every later sell day. That is quadratic.
// How it works: i is the buy index. j is the sell index. profit is prices[j] - prices[i]. Keep the max, never go below 0.

function maxProfit(prices) {
  let best = 0;
  const n = prices.length;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const profit = prices[j] - prices[i];
      if (profit > best) best = profit;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Linear time, but it stores a min-so-far array of length n.
// How it works: minLeft[i] is the cheapest price on day i or earlier. Profit if you sell on day i is prices[i] - minLeft[i]. Take the max of those profits.

function maxProfit(prices) {
  const n = prices.length;
  if (n === 0) return 0;
  const minLeft = new Array(n);
  minLeft[0] = prices[0];
  for (let i = 1; i < n; i++) {
    minLeft[i] = Math.min(minLeft[i - 1], prices[i]);
  }
  let best = 0;
  for (let i = 1; i < n; i++) {
    const profit = prices[i] - minLeft[i];
    if (profit > best) best = profit;
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Same linear scan, but only two numbers are stored: cheapest so far and best profit.
// How it works: walk once. If today’s price is a new low, update cheapest. Else try selling today against that low.

function maxProfit(prices) {
  let cheapest = Infinity;
  let best = 0;
  for (let i = 0; i < prices.length; i++) {
    if (prices[i] < cheapest) cheapest = prices[i];
    const profit = prices[i] - cheapest;
    if (profit > best) best = profit;
  }
  return best;
}
