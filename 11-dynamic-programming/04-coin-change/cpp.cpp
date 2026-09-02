// Method 1: Brute
// Time: O(S^n) | Space: O(amount)
// At every remaining amount you branch on every coin. The tree is huge and repeats the same remain. Depth is at most amount (all 1s). S is amount, n is number of coins.

int coinGo(vector<int>& coins, int remain) {
    const int INF = 1000000000;
    if (remain == 0) return 0;
    if (remain < 0) return INF;
    int best = INF;
    for (int i = 0; i < (int)coins.size(); i++) {
        int used = coinGo(coins, remain - coins[i]);
        if (used != INF) best = min(best, used + 1);
    }
    return best;
}
int coinChange(vector<int>& coins, int amount) {
    int ans = coinGo(coins, amount);
    return ans == 1000000000 ? -1 : ans;
}


// Method 2: Optimal
// Time: O(n * amount) | Space: O(amount)
// Each remaining amount is solved once. Work per state is a loop over n coins. Memo array is size amount+1. Same recurrence as brute, overlapping calls collapsed.

int coinGo(vector<int>& coins, int remain, vector<int>& memo) {
    const int INF = 1000000000;
    if (remain == 0) return 0;
    if (remain < 0) return INF;
    if (memo[remain] != -2) return memo[remain];
    int best = INF;
    for (int i = 0; i < (int)coins.size(); i++) {
        int used = coinGo(coins, remain - coins[i], memo);
        if (used != INF) best = min(best, used + 1);
    }
    memo[remain] = best;
    return best;
}
int coinChange(vector<int>& coins, int amount) {
    vector<int> memo(amount + 1, -2);
    int ans = coinGo(coins, amount, memo);
    return ans == 1000000000 ? -1 : ans;
}


// Method 3: More optimal
// Time: O(n * amount) | Space: O(amount)
// Bottom-up 1D unbounded knapsack. best[s] is fewest coins for sum s. Filling left to right allows reuse. No recursion. Same asymptotics as memo, cleaner order, no stack.

int coinChange(vector<int>& coins, int amount) {
    const int INF = 1000000000;
    vector<int> best(amount + 1, INF);
    best[0] = 0;
    for (int s = 1; s <= amount; s++) {
        for (int i = 0; i < (int)coins.size(); i++) {
            int coin = coins[i];
            if (coin <= s) best[s] = min(best[s], best[s - coin] + 1);
        }
    }
    return best[amount] == INF ? -1 : best[amount];
}
