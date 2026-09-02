# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# Every house branches into take or skip with no cache, so the tree is exponential. The stack is one frame per house along a path.

def rob(nums):
    def go(i):
        if i >= len(nums):
            return 0
        take = nums[i] + go(i + 2)
        skip = go(i + 1)
        return max(take, skip)
    return go(0)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# best[i] is the best total using the first i houses. Each i is filled from i-1 and i-2 in constant time. n states, linear time and linear extra memory.

def rob(nums):
    n = len(nums)
    best = [0] * (n + 1)
    for i in range(1, n + 1):
        take = nums[i - 1] + (best[i - 2] if i >= 2 else 0)
        skip = best[i - 1]
        best[i] = max(take, skip)
    return best[n]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Only skip (best without the previous house as a take-chain) and take (best that used the previous house) are live. One pass updates both. Same linear scan, constant extra memory.

def rob(nums):
    skip = 0
    take = 0
    for x in nums:
        nextTake = skip + x
        skip = max(skip, take)
        take = nextTake
    return max(skip, take)
