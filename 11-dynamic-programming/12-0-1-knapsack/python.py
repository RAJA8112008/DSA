# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# Each item is taken or skipped. No cache. Exponential in the number of items. Depth is n.

def knapsack(values, weights, capacity):
    def go(i, remain):
        if i == len(values):
            return 0
        skip = go(i + 1, remain)
        take = 0
        if weights[i] <= remain:
            take = values[i] + go(i + 1, remain - weights[i])
        return max(skip, take)
    return go(0, capacity)


# Method 2: Optimal
# Time: O(n * W) | Space: O(n * W)
# Full table: n+1 rows, W+1 columns. Each cell is a max of skip and take. W is capacity. This is the picture you should be able to fill by hand.

def knapsack(values, weights, capacity):
    n = len(values)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        for w in range(0, capacity + 1):
            dp[i][w] = dp[i - 1][w]
            if weights[i - 1] <= w:
                take = dp[i - 1][w - weights[i - 1]] + values[i - 1]
                dp[i][w] = max(dp[i][w], take)
    return dp[n][capacity]


# Method 3: More optimal
# Time: O(n * W) | Space: O(W)
# One row of size W+1. Inner loop walks capacity from high to low so best[w - weight] is still the previous item’s row. Forward would reuse the same item (unbounded).

def knapsack(values, weights, capacity):
    best = [0] * (capacity + 1)
    for i in range(len(values)):
        for w in range(capacity, weights[i] - 1, -1):
            best[w] = max(best[w], best[w - weights[i]] + values[i])
    return best[capacity]
