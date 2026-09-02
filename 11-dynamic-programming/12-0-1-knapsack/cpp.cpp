// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each item is taken or skipped. No cache. Exponential in the number of items. Depth is n.

int knapGo(vector<int>& values, vector<int>& weights, int i, int remain) {
    if (i == (int)values.size()) return 0;
    int skip = knapGo(values, weights, i + 1, remain);
    int take = 0;
    if (weights[i] <= remain) {
        take = values[i] + knapGo(values, weights, i + 1, remain - weights[i]);
    }
    return max(skip, take);
}
int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    return knapGo(values, weights, 0, capacity);
}


// Method 2: Optimal
// Time: O(n * W) | Space: O(n * W)
// Full table: n+1 rows, W+1 columns. Each cell is a max of skip and take. W is capacity. This is the picture you should be able to fill by hand.

int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                int take = dp[i - 1][w - weights[i - 1]] + values[i - 1];
                dp[i][w] = max(dp[i][w], take);
            }
        }
    }
    return dp[n][capacity];
}


// Method 3: More optimal
// Time: O(n * W) | Space: O(W)
// One row of size W+1. Inner loop walks capacity from high to low so best[w - weight] is still the previous item’s row. Forward would reuse the same item (unbounded).

int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
    vector<int> best(capacity + 1, 0);
    for (int i = 0; i < (int)values.size(); i++) {
        for (int w = capacity; w >= weights[i]; w--) {
            best[w] = max(best[w], best[w - weights[i]] + values[i]);
        }
    }
    return best[capacity];
}
