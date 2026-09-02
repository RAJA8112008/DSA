// Method 1: Brute
// Time: O(S^n) | Space: O(amount)
// At every remaining amount you branch on every coin. The tree is huge and repeats the same remain. Depth is at most amount (all 1s). S is amount, n is number of coins.

class Solution {
    public int coinChange(int[] coins, int amount) {
        int ans = go(coins, amount);
        return ans >= 1000000000 ? -1 : ans;
    }
    private int go(int[] coins, int remain) {
        if (remain == 0) return 0;
        if (remain < 0) return 1000000000;
        int best = 1000000000;
        for (int i = 0; i < coins.length; i++) {
            int used = go(coins, remain - coins[i]);
            if (used < 1000000000) best = Math.min(best, used + 1);
        }
        return best;
    }
}


// Method 2: Optimal
// Time: O(n * amount) | Space: O(amount)
// Each remaining amount is solved once. Work per state is a loop over n coins. Memo array is size amount+1. Same recurrence as brute, overlapping calls collapsed.

class Solution {
    public int coinChange(int[] coins, int amount) {
        Integer[] memo = new Integer[amount + 1];
        int ans = go(coins, amount, memo);
        return ans >= 1000000000 ? -1 : ans;
    }
    private int go(int[] coins, int remain, Integer[] memo) {
        if (remain == 0) return 0;
        if (remain < 0) return 1000000000;
        if (memo[remain] != null) return memo[remain];
        int best = 1000000000;
        for (int i = 0; i < coins.length; i++) {
            int used = go(coins, remain - coins[i], memo);
            if (used < 1000000000) best = Math.min(best, used + 1);
        }
        memo[remain] = best;
        return best;
    }
}


// Method 3: More optimal
// Time: O(n * amount) | Space: O(amount)
// Bottom-up 1D unbounded knapsack. best[s] is fewest coins for sum s. Filling left to right allows reuse. No recursion. Same asymptotics as memo, cleaner order, no stack.

class Solution {
    public int coinChange(int[] coins, int amount) {
        int INF = 1000000000;
        int[] best = new int[amount + 1];
        java.util.Arrays.fill(best, INF);
        best[0] = 0;
        for (int s = 1; s <= amount; s++) {
            for (int i = 0; i < coins.length; i++) {
                int coin = coins[i];
                if (coin <= s) best[s] = Math.min(best[s], best[s - coin] + 1);
            }
        }
        return best[amount] == INF ? -1 : best[amount];
    }
}
