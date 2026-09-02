# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# At each day you skip, buy, or sell depending on holding. Two branches most days, no cache. Exponential in the number of days.

def maxProfit(prices):
    def go(i, holding):
        if i == len(prices):
            return 0
        if holding:
            sell = prices[i] + go(i + 1, 0)
            keep = go(i + 1, 1)
            return max(sell, keep)
        buy = -prices[i] + go(i + 1, 1)
        skip = go(i + 1, 0)
        return max(buy, skip)
    return go(0, 0)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# cash[i] is best profit ending day i with no share. hold[i] is best ending day i with a share. Transitions are skip vs sell, and skip vs buy. n days, two arrays.

def maxProfit(prices):
    n = len(prices)
    if n == 0:
        return 0
    cash = [0] * n
    hold = [0] * n
    hold[0] = -prices[0]
    for i in range(1, n):
        cash[i] = max(cash[i - 1], hold[i - 1] + prices[i])
        hold[i] = max(hold[i - 1], cash[i - 1] - prices[i])
    return cash[n - 1]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Every profitable adjacent difference can be taken. That sum equals the DP. One pass, no extra arrays. Mention this is the space-cut of the two-state DP, not a different problem.

def maxProfit(prices):
    profit = 0
    for i in range(1, len(prices)):
        if prices[i] > prices[i - 1]:
            profit += prices[i] - prices[i - 1]
    return profit
