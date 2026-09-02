// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// At each day you skip, buy, or sell depending on holding. Two branches most days, no cache. Exponential in the number of days.

int profitGo(vector<int>& prices, int i, int holding) {
    if (i == (int)prices.size()) return 0;
    if (holding) {
        int sell = prices[i] + profitGo(prices, i + 1, 0);
        int keep = profitGo(prices, i + 1, 1);
        return max(sell, keep);
    }
    int buy = -prices[i] + profitGo(prices, i + 1, 1);
    int skip = profitGo(prices, i + 1, 0);
    return max(buy, skip);
}
int maxProfit(vector<int>& prices) {
    return profitGo(prices, 0, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// cash[i] is best profit ending day i with no share. hold[i] is best ending day i with a share. Transitions are skip vs sell, and skip vs buy. n days, two arrays.

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<int> cash(n, 0), hold(n, 0);
    hold[0] = -prices[0];
    for (int i = 1; i < n; i++) {
        cash[i] = max(cash[i - 1], hold[i - 1] + prices[i]);
        hold[i] = max(hold[i - 1], cash[i - 1] - prices[i]);
    }
    return cash[n - 1];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Every profitable adjacent difference can be taken. That sum equals the DP. One pass, no extra arrays. Mention this is the space-cut of the two-state DP, not a different problem.

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < (int)prices.size(); i++) {
        if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
    }
    return profit;
}
