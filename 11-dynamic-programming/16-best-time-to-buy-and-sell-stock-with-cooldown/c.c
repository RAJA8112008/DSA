// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// State is (day, holding, cooldown). Branches are buy/skip/sell. No cache. Exponential in n. Correct, too slow on long price lists.

int cdGo(int *prices, int n, int i, int holding, int cooldown) {
    int sell, keep, skip, buy;
    if (i == n) return 0;
    if (holding) {
        sell = prices[i] + cdGo(prices, n, i + 1, 0, 1);
        keep = cdGo(prices, n, i + 1, 1, 0);
        return sell > keep ? sell : keep;
    }
    skip = cdGo(prices, n, i + 1, 0, 0);
    if (cooldown) return skip;
    buy = -prices[i] + cdGo(prices, n, i + 1, 1, 0);
    return skip > buy ? skip : buy;
}
int maxProfit(int *prices, int n) {
    return cdGo(prices, n, 0, 0, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// hold[i], sold[i], rest[i] are the three states after day i. Each is O(1) from yesterday. n days times 3 cells. This is the table that matches the cooldown rule one-to-one.

int maxProfit(int *prices, int n) {
    int *hold, *sold, *rest, i, ans, a, b;
    if (n == 0) return 0;
    hold = (int *)calloc(n, sizeof(int));
    sold = (int *)calloc(n, sizeof(int));
    rest = (int *)calloc(n, sizeof(int));
    hold[0] = -prices[0];
    for (i = 1; i < n; i++) {
        a = hold[i - 1];
        b = rest[i - 1] - prices[i];
        hold[i] = a > b ? a : b;
        sold[i] = hold[i - 1] + prices[i];
        a = rest[i - 1];
        b = sold[i - 1];
        rest[i] = a > b ? a : b;
    }
    ans = sold[n - 1] > rest[n - 1] ? sold[n - 1] : rest[n - 1];
    free(hold);
    free(sold);
    free(rest);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only yesterday’s three numbers are live. Copy them into nextHold, nextSold, nextRest, then slide. Same linear scan, constant extra memory.

int maxProfit(int *prices, int n) {
    int hold = -1000000000;
    int sold = 0;
    int rest = 0;
    int i;
    for (i = 0; i < n; i++) {
        int price = prices[i];
        int nextHold = hold > rest - price ? hold : rest - price;
        int nextSold = hold + price;
        int nextRest = rest > sold ? rest : sold;
        hold = nextHold;
        sold = nextSold;
        rest = nextRest;
    }
    return sold > rest ? sold : rest;
}
