// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// State is (day, holding, cooldown). Branches are buy/skip/sell. No cache. Exponential in n. Correct, too slow on long price lists.

class Solution {
    public int maxProfit(int[] prices) {
        return go(prices, 0, 0, false);
    }
    private int go(int[] prices, int i, int holding, boolean cooldown) {
        if (i == prices.length) return 0;
        if (holding == 1) {
            int sell = prices[i] + go(prices, i + 1, 0, true);
            int keep = go(prices, i + 1, 1, false);
            return Math.max(sell, keep);
        }
        int skip = go(prices, i + 1, 0, false);
        if (cooldown) return skip;
        int buy = -prices[i] + go(prices, i + 1, 1, false);
        return Math.max(skip, buy);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// hold[i], sold[i], rest[i] are the three states after day i. Each is O(1) from yesterday. n days times 3 cells. This is the table that matches the cooldown rule one-to-one.

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n == 0) return 0;
        int[] hold = new int[n];
        int[] sold = new int[n];
        int[] rest = new int[n];
        hold[0] = -prices[0];
        sold[0] = 0;
        rest[0] = 0;
        for (int i = 1; i < n; i++) {
            hold[i] = Math.max(hold[i - 1], rest[i - 1] - prices[i]);
            sold[i] = hold[i - 1] + prices[i];
            rest[i] = Math.max(rest[i - 1], sold[i - 1]);
        }
        return Math.max(sold[n - 1], rest[n - 1]);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only yesterday’s three numbers are live. Copy them into nextHold, nextSold, nextRest, then slide. Same linear scan, constant extra memory.

class Solution {
    public int maxProfit(int[] prices) {
        int hold = -1000000000;
        int sold = 0;
        int rest = 0;
        for (int i = 0; i < prices.length; i++) {
            int price = prices[i];
            int nextHold = Math.max(hold, rest - price);
            int nextSold = hold + price;
            int nextRest = Math.max(rest, sold);
            hold = nextHold;
            sold = nextSold;
            rest = nextRest;
        }
        return Math.max(sold, rest);
    }
}
