# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# State is (day, holding, cooldown). Branches are buy/skip/sell. No cache. Exponential in n. Correct, too slow on long price lists.

def maxProfit(prices):
    def go(i, holding, cooldown):
        if i == len(prices):
            return 0
        if holding:
            sell = prices[i] + go(i + 1, 0, True)
            keep = go(i + 1, 1, False)
            return max(sell, keep)
        skip = go(i + 1, 0, False)
        if cooldown:
            return skip
        buy = -prices[i] + go(i + 1, 1, False)
        return max(skip, buy)
    return go(0, 0, False)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# hold[i], sold[i], rest[i] are the three states after day i. Each is O(1) from yesterday. n days times 3 cells. This is the table that matches the cooldown rule one-to-one.

def maxProfit(prices):
    n = len(prices)
    if n == 0:
        return 0
    hold = [0] * n
    sold = [0] * n
    rest = [0] * n
    hold[0] = -prices[0]
    sold[0] = 0
    rest[0] = 0
    for i in range(1, n):
        hold[i] = max(hold[i - 1], rest[i - 1] - prices[i])
        sold[i] = hold[i - 1] + prices[i]
        rest[i] = max(rest[i - 1], sold[i - 1])
    return max(sold[n - 1], rest[n - 1])


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Only yesterday’s three numbers are live. Copy them into nextHold, nextSold, nextRest, then slide. Same linear scan, constant extra memory.

def maxProfit(prices):
    hold = float("-inf")
    sold = 0
    rest = 0
    for price in prices:
        nextHold = max(hold, rest - price)
        nextSold = hold + price
        nextRest = max(rest, sold)
        hold = nextHold
        sold = nextSold
        rest = nextRest
    return max(sold, rest)
