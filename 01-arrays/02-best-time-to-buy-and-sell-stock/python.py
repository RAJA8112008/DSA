# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each buy day you scan every later sell day. That is quadratic.
# How it works: i is the buy index. j is the sell index. profit is prices[j] - prices[i]. Keep the max, never go below 0.

def max_profit(prices):
    best = 0
    n = len(prices)
    for i in range(n):

        for j in range(i + 1, n):

            profit = prices[j] - prices[i]
            if profit > best: best = profit

    return best


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Linear time, but it stores a min-so-far array of length n.
# How it works: minLeft[i] is the cheapest price on day i or earlier. Profit if you sell on day i is prices[i] - minLeft[i]. Take the max of those profits.

def max_profit(prices):
    n = len(prices)
    if n == 0: return 0
    minLeft = [None] * (n)
    minLeft[0] = prices[0]
    for i in range(1, n):

        minLeft[i] = min(minLeft[i - 1], prices[i])

    best = 0
    for i in range(1, n):

        profit = prices[i] - minLeft[i]
        if profit > best: best = profit

    return best


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Same linear scan, but only two numbers are stored: cheapest so far and best profit.
# How it works: walk once. If today’s price is a new low, update cheapest. Else try selling today against that low.

def max_profit(prices):
    cheapest = float('inf')
    best = 0
    for i in range(len(prices)):

        if prices[i] < cheapest: cheapest = prices[i]
        profit = prices[i] - cheapest
        if profit > best: best = profit

    return best
