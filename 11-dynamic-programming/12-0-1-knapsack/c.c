// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each item is taken or skipped. No cache. Exponential in the number of items. Depth is n.

int knapGo(int *values, int *weights, int n, int i, int remain) {
    int skip, take = 0;
    if (i == n) return 0;
    skip = knapGo(values, weights, n, i + 1, remain);
    if (weights[i] <= remain) {
        take = values[i] + knapGo(values, weights, n, i + 1, remain - weights[i]);
    }
    return skip > take ? skip : take;
}
int knapsack(int *values, int *weights, int n, int capacity) {
    return knapGo(values, weights, n, 0, capacity);
}


// Method 2: Optimal
// Time: O(n * W) | Space: O(n * W)
// Full table: n+1 rows, W+1 columns. Each cell is a max of skip and take. W is capacity. This is the picture you should be able to fill by hand.

int knapsack(int *values, int *weights, int n, int capacity) {
    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    int i, w, ans;
    for (i = 0; i <= n; i++) dp[i] = (int *)calloc(capacity + 1, sizeof(int));
    for (i = 1; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w) {
                int take = dp[i - 1][w - weights[i - 1]] + values[i - 1];
                if (take > dp[i][w]) dp[i][w] = take;
            }
        }
    }
    ans = dp[n][capacity];
    for (i = 0; i <= n; i++) free(dp[i]);
    free(dp);
    return ans;
}


// Method 3: More optimal
// Time: O(n * W) | Space: O(W)
// One row of size W+1. Inner loop walks capacity from high to low so best[w - weight] is still the previous item’s row. Forward would reuse the same item (unbounded).

int knapsack(int *values, int *weights, int n, int capacity) {
    int *best = (int *)calloc(capacity + 1, sizeof(int));
    int i, w, ans;
    for (i = 0; i < n; i++) {
        for (w = capacity; w >= weights[i]; w--) {
            int take = best[w - weights[i]] + values[i];
            if (take > best[w]) best[w] = take;
        }
    }
    ans = best[capacity];
    free(best);
    return ans;
}
