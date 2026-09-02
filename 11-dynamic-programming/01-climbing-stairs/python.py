# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# Each stair branches into two calls. The same k is solved again and again, so the tree is exponential. Space is the recursion depth n.

def climbStairs(n):
    if n <= 2:
        return n
    return climbStairs(n - 1) + climbStairs(n - 2)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Memo stores each k once. After the first fill, go(k) is a lookup. You still use O(n) stack plus O(n) memo cells. Same recurrence, no repeated subtrees.

def climbStairs(n):
    memo = {}
    def go(k):
        if k <= 2:
            return k
        if k in memo:
            return memo[k]
        memo[k] = go(k - 1) + go(k - 2)
        return memo[k]
    return go(n)


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Only the previous two answers are live. a is ways(i-2), b is ways(i-1). Slide them forward n-2 times. Time stays linear; extra memory is two numbers.

def climbStairs(n):
    if n <= 2:
        return n
    a, b = 1, 2
    for i in range(3, n + 1):
        nxt = a + b
        a = b
        b = nxt
    return b
