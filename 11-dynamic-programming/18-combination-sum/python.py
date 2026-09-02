# Method 1: Brute
# Time: O(n^{target/min}) | Space: O(target / min)
# From start you may reuse candidates[i] (call go(i, remain - value)) or move on. Order is frozen by the index, so combinations are unique. No cache; the tree size tracks how you can pile the smallest coin. Depth is about target / min(candidates).

def combinationSum(candidates, target):
    def go(start, remain):
        if remain == 0:
            return 1
        if remain < 0:
            return 0
        ways = 0
        for i in range(start, len(candidates)):
            ways += go(i, remain - candidates[i])
        return ways
    return go(0, target)


# Method 2: Optimal
# Time: O(n * target) | Space: O(n * target)
# Each pair (start index, remaining target) is solved once. Work per state is a loop over the leftover candidates. Map size is O(n * target). Same combination semantics as the backtrack.

def combinationSum(candidates, target):
    memo = {}
    def go(start, remain):
        key = (start, remain)
        if key in memo:
            return memo[key]
        if remain == 0:
            memo[key] = 1
            return 1
        if remain < 0:
            return 0
        ways = 0
        for i in range(start, len(candidates)):
            ways += go(i, remain - candidates[i])
        memo[key] = ways
        return ways
    return go(0, target)


# Method 3: More optimal
# Time: O(n * target) | Space: O(target)
# Unbounded knapsack ways. Outer loop is the coin, inner loop walks sums upward so that coin may be reused. That order counts combinations, not permutations. One row of size target+1. If you swapped the loops, you would count ordered sequences instead.

def combinationSum(candidates, target):
    ways = [0] * (target + 1)
    ways[0] = 1
    for coin in candidates:
        for s in range(coin, target + 1):
            ways[s] += ways[s - coin]
    return ways[target]
