# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# Each range is still a take/skip tree with no memo. Two ranges do not change the exponential shape. Stack depth is O(n).

def rob(nums):
    n = len(nums)
    if n == 1:
        return nums[0]
    def go(i, end):
        if i > end:
            return 0
        take = nums[i] + go(i + 2, end)
        skip = go(i + 1, end)
        return max(take, skip)
    return max(go(0, n - 2), go(1, n - 1))


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Each linear street is the house-robber table. Two passes, each O(n) states. You still store a best[] array per pass. Handles n = 1 before splitting.

def rob(nums):
    n = len(nums)
    if n == 1:
        return nums[0]
    def robLine(start, end):
        length = end - start + 1
        best = [0] * length
        for i in range(start, end + 1):
            j = i - start
            take = nums[i] + (best[j - 2] if j >= 2 else 0)
            skip = best[j - 1] if j >= 1 else 0
            best[j] = max(take, skip)
        return best[length - 1]
    return max(robLine(0, n - 2), robLine(1, n - 1))


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# The same two ranges, each robbed with two rolling numbers. Extra memory no longer depends on n. Time is still two linear scans.

def rob(nums):
    n = len(nums)
    if n == 1:
        return nums[0]
    def robLine(start, end):
        skip = 0
        take = 0
        for i in range(start, end + 1):
            nextTake = skip + nums[i]
            skip = max(skip, take)
            take = nextTake
        return max(skip, take)
    return max(robLine(0, n - 2), robLine(1, n - 1))
