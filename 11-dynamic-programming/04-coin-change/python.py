# Method 1: Brute
# Time: O(S^n) | Space: O(amount)
# At every remaining amount you branch on every coin. The tree is huge and repeats the same remain. Depth is at most amount (all 1s). S is amount, n is number of coins.

def coinChange(coins, amount):
    INF = 10 ** 9
    def go(remain):
        if remain == 0:
            return 0
        if remain < 0:
            return INF
        best = INF
        for coin in coins:
            used = go(remain - coin)
            if used != INF:
                best = min(best, used + 1)
        return best
    ans = go(amount)
    return -1 if ans == INF else ans


# Method 2: Optimal
# Time: O(n * amount) | Space: O(amount)
# Each remaining amount is solved once. Work per state is a loop over n coins. Memo array is size amount+1. Same recurrence as brute, overlapping calls collapsed.

def coinChange(coins, amount):
    INF = 10 ** 9
    memo = {}
    def go(remain):
        if remain == 0:
            return 0
        if remain < 0:
            return INF
        if remain in memo:
            return memo[remain]
        best = INF
        for coin in coins:
            used = go(remain - coin)
            if used != INF:
                best = min(best, used + 1)
        memo[remain] = best
        return best
    ans = go(amount)
    return -1 if ans == INF else ans


# Method 3: More optimal
# Time: O(n * amount) | Space: O(amount)
# Bottom-up 1D unbounded knapsack. best[s] is fewest coins for sum s. Filling left to right allows reuse. No recursion. Same asymptotics as memo, cleaner order, no stack.

def coinChange(coins, amount):
    INF = 10 ** 9
    best = [INF] * (amount + 1)
    best[0] = 0
    for s in range(1, amount + 1):
        for coin in coins:
            if coin <= s:
                best[s] = min(best[s], best[s - coin] + 1)
    return -1 if best[amount] == INF else best[amount]
