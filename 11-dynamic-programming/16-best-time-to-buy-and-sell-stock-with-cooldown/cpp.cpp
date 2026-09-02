// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// State is (day, holding, cooldown). Branches are buy/skip/sell. No cache. Exponential in n. Correct, too slow on long price lists.

int cdGo(vector<int>& prices, int i, int holding, int cooldown) {
    if (i == (int)prices.size()) return 0;
    if (holding) {
        int sell = prices[i] + cdGo(prices, i + 1, 0, 1);
        int keep = cdGo(prices, i + 1, 1, 0);
        return max(sell, keep);
    }
    int skip = cdGo(prices, i + 1, 0, 0);
    if (cooldown) return skip;
    int buy = -prices[i] + cdGo(prices, i + 1, 1, 0);
    return max(skip, buy);
}
int maxProfit(vector<int>& prices) {
    return cdGo(prices, 0, 0, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// hold[i], sold[i], rest[i] are the three states after day i. Each is O(1) from yesterday. n days times 3 cells. This is the table that matches the cooldown rule one-to-one.

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<int> hold(n, 0), sold(n, 0), rest(n, 0);
    hold[0] = -prices[0];
    sold[0] = 0;
    rest[0] = 0;
    for (int i = 1; i < n; i++) {
        hold[i] = max(hold[i - 1], rest[i - 1] - prices[i]);
        sold[i] = hold[i - 1] + prices[i];
        rest[i] = max(rest[i - 1], sold[i - 1]);
    }
    return max(sold[n - 1], rest[n - 1]);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only yesterday’s three numbers are live. Copy them into nextHold, nextSold, nextRest, then slide. Same linear scan, constant extra memory.

int maxProfit(vector<int>& prices) {
    int hold = -1000000000;
    int sold = 0;
    int rest = 0;
    for (int i = 0; i < (int)prices.size(); i++) {
        int price = prices[i];
        int nextHold = max(hold, rest - price);
        int nextSold = hold + price;
        int nextRest = max(rest, sold);
        hold = nextHold;
        sold = nextSold;
        rest = nextRest;
    }
    return max(sold, rest);
}
