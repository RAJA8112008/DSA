# Method 1: Brute
# Time: O(4^n / n^{3/2}) | Space: O(n)
# Naive recursion: try each root and multiply left-count * right-count. Exponential overlapping subproblems.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def num_trees(n):
    def count(length):
        if length <= 1:
            return 1
        total = 0
        for left in range(length):
            total += count(left) * count(length - 1 - left)
        return total
    return count(n)


# Method 2: Optimal
# Time: O(n²) | Space: O(n)
# dp[k] = number of BSTs on k keys. dp[0]=1. Each k sums dp[left]*dp[k-1-left]. Standard Catalan DP.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def num_trees(n):
    dp = [0] * (n + 1)
    dp[0] = 1
    for k in range(1, n + 1):
        for left in range(k):
            dp[k] += dp[left] * dp[k - 1 - left]
    return dp[n]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# C(n) = C(n-1) * 2(2n-1)/(n+1). Multiply carefully with integer arithmetic. One pass, constant extra memory.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def num_trees(n):
    c = 1
    for i in range(2, n + 1):
        c = c * 2 * (2 * i - 1) // (i + 1)
    return c
