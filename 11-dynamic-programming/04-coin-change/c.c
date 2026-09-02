// Method 1: Brute
// Time: O(S^n) | Space: O(amount)
// At every remaining amount you branch on every coin. The tree is huge and repeats the same remain. Depth is at most amount (all 1s). S is amount, n is number of coins.

int coinGo(int *coins, int n, int remain) {
    const int INF = 1000000000;
    int i, best, used;
    if (remain == 0) return 0;
    if (remain < 0) return INF;
    best = INF;
    for (i = 0; i < n; i++) {
        used = coinGo(coins, n, remain - coins[i]);
        if (used != INF && used + 1 < best) best = used + 1;
    }
    return best;
}
int coinChange(int *coins, int n, int amount) {
    int ans = coinGo(coins, n, amount);
    return ans == 1000000000 ? -1 : ans;
}


// Method 2: Optimal
// Time: O(n * amount) | Space: O(amount)
// Each remaining amount is solved once. Work per state is a loop over n coins. Memo array is size amount+1. Same recurrence as brute, overlapping calls collapsed.

int coinGo(int *coins, int n, int remain, int *memo) {
    const int INF = 1000000000;
    int i, best, used;
    if (remain == 0) return 0;
    if (remain < 0) return INF;
    if (memo[remain] != -2) return memo[remain];
    best = INF;
    for (i = 0; i < n; i++) {
        used = coinGo(coins, n, remain - coins[i], memo);
        if (used != INF && used + 1 < best) best = used + 1;
    }
    memo[remain] = best;
    return best;
}
int coinChange(int *coins, int n, int amount) {
    int *memo = (int *)malloc((amount + 1) * sizeof(int));
    int i, ans;
    for (i = 0; i <= amount; i++) memo[i] = -2;
    ans = coinGo(coins, n, amount, memo);
    free(memo);
    return ans == 1000000000 ? -1 : ans;
}


// Method 3: More optimal
// Time: O(n * amount) | Space: O(amount)
// Bottom-up 1D unbounded knapsack. best[s] is fewest coins for sum s. Filling left to right allows reuse. No recursion. Same asymptotics as memo, cleaner order, no stack.

int coinChange(int *coins, int n, int amount) {
    const int INF = 1000000000;
    int *best = (int *)malloc((amount + 1) * sizeof(int));
    int s, i, ans;
    for (s = 0; s <= amount; s++) best[s] = INF;
    best[0] = 0;
    for (s = 1; s <= amount; s++) {
        for (i = 0; i < n; i++) {
            int coin = coins[i];
            if (coin <= s && best[s - coin] + 1 < best[s]) {
                best[s] = best[s - coin] + 1;
            }
        }
    }
    ans = best[amount] == INF ? -1 : best[amount];
    free(best);
    return ans;
}
