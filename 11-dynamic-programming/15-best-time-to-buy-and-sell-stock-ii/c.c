// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// At each day you skip, buy, or sell depending on holding. Two branches most days, no cache. Exponential in the number of days.

int profitGo(int *prices, int n, int i, int holding) {
    int sell, keep, buy, skip;
    if (i == n) return 0;
    if (holding) {
        sell = prices[i] + profitGo(prices, n, i + 1, 0);
        keep = profitGo(prices, n, i + 1, 1);
        return sell > keep ? sell : keep;
    }
    buy = -prices[i] + profitGo(prices, n, i + 1, 1);
    skip = profitGo(prices, n, i + 1, 0);
    return buy > skip ? buy : skip;
}
int maxProfit(int *prices, int n) {
    return profitGo(prices, n, 0, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// cash[i] is best profit ending day i with no share. hold[i] is best ending day i with a share. Transitions are skip vs sell, and skip vs buy. n days, two arrays.

int maxProfit(int *prices, int n) {
    int *cash, *hold, i, ans;
    if (n == 0) return 0;
    cash = (int *)calloc(n, sizeof(int));
    hold = (int *)calloc(n, sizeof(int));
    hold[0] = -prices[0];
    for (i = 1; i < n; i++) {
        int a = cash[i - 1], b = hold[i - 1] + prices[i];
        cash[i] = a > b ? a : b;
        a = hold[i - 1];
        b = cash[i - 1] - prices[i];
        hold[i] = a > b ? a : b;
    }
    ans = cash[n - 1];
    free(cash);
    free(hold);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Every profitable adjacent difference can be taken. That sum equals the DP. One pass, no extra arrays. Mention this is the space-cut of the two-state DP, not a different problem.

int maxProfit(int *prices, int n) {
    int profit = 0, i;
    for (i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
    }
    return profit;
}
