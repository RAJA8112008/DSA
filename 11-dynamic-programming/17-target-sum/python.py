# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# Each number branches into plus or minus. 2^n signed assignments. Stack is n. Fine as a correctness check on tiny n.

def findTargetSumWays(nums, target):
    def go(i, total):
        if i == len(nums):
            return 1 if total == target else 0
        return go(i + 1, total + nums[i]) + go(i + 1, total - nums[i])
    return go(0, 0)


# Method 2: Optimal
# Time: O(n * sum) | Space: O(n * sum)
# Memo keys are (index, running sum). Running sum ranges about [-total, total], so unique states are O(n * total). Each state does two branches once.

def findTargetSumWays(nums, target):
    memo = {}
    def go(i, total):
        key = (i, total)
        if key in memo:
            return memo[key]
        if i == len(nums):
            ans = 1 if total == target else 0
            memo[key] = ans
            return ans
        ways = go(i + 1, total + nums[i]) + go(i + 1, total - nums[i])
        memo[key] = ways
        return ways
    return go(0, 0)


# Method 3: More optimal
# Time: O(n * sum) | Space: O(sum)
# Map onto 0/1 subset-sum ways for need = (total + target) / 2. One ways[] row, inner loop backwards so each number is used once. Cleaner bottom-up, same polynomial, smaller constant memory.

def findTargetSumWays(nums, target):
    total = sum(nums)
    if abs(target) > total or (total + target) % 2 != 0:
        return 0
    need = (total + target) // 2
    ways = [0] * (need + 1)
    ways[0] = 1
    for num in nums:
        for s in range(need, num - 1, -1):
            ways[s] += ways[s - num]
    return ways[need]
