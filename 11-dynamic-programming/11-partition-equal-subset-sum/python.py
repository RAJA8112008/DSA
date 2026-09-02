# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# Each number is included or skipped. No cache. 2^n subsets. The odd-total check is the only prune. Stack is O(n).

def canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    need = total // 2
    def go(i, remain):
        if remain == 0:
            return True
        if i == len(nums) or remain < 0:
            return False
        return go(i + 1, remain - nums[i]) or go(i + 1, remain)
    return go(0, need)


# Method 2: Optimal
# Time: O(n * sum) | Space: O(n * sum)
# can[i][s] is true if some subset of the first i numbers adds to s. Classic 0/1 knapsack boolean table. n * (sum/2) cells, each O(1).

def canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    need = total // 2
    n = len(nums)
    can = [[False] * (need + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        can[i][0] = True
    for i in range(1, n + 1):
        for s in range(1, need + 1):
            can[i][s] = can[i - 1][s]
            if nums[i - 1] <= s:
                can[i][s] = can[i][s] or can[i - 1][s - nums[i - 1]]
    return can[n][need]


# Method 3: More optimal
# Time: O(n * sum) | Space: O(sum)
# One boolean row. Walk s from need down to num so each number is used at most once. Same 0/1 rule as knapsack space cut. Extra memory is need+1 flags.

def canPartition(nums):
    total = sum(nums)
    if total % 2 != 0:
        return False
    need = total // 2
    can = [False] * (need + 1)
    can[0] = True
    for num in nums:
        for s in range(need, num - 1, -1):
            if can[s - num]:
                can[s] = True
    return can[need]
