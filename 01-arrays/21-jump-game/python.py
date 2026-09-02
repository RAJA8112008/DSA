# Method 1: Brute
# Time: O(2ⁿ) | Space: O(n)
# From each index you may try every jump length. Overlapping paths are recomputed, so the tree is exponential. Stack depth is O(n).
# How it works: dfs(i) is true if i is the last index, or any i + step can reach the end.

def can_jump(nums):
    n = len(nums)
    def dfs(i):
        if i >= n - 1: return True
        maxStep = nums[i]
        for step in range(1, = maxStep):

            if dfs(i + step): return True

        return False
    return dfs(0)


# Method 2: Optimal
# Time: O(n²) | Space: O(n)
# For each index you may look at every previous index. Worst case quadratic. Extra array of n booleans.
# How it works: ok[0] is true. ok[j] becomes true if some earlier ok[i] can jump to j. Return ok[n-1].

def can_jump(nums):
    n = len(nums)
    ok = [False] * n
    ok[0] = True
    for i in range(n):

        if not ok[i]: continue
        last = min(n - 1, i + nums[i])
        for j in range(i + 1, = last):
            ok[j] = True

    return ok[n - 1]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# One left-to-right pass. farthest is the rightmost index you can reach so far.
# How it works: if i > farthest you cannot even stand here. Update farthest with i + nums[i]. If farthest covers the last index, return true.

def can_jump(nums):
    farthest = 0
    n = len(nums)
    for i in range(n):

        if i > farthest: return False
        reach = i + nums[i]
        if reach > farthest: farthest = reach
        if farthest >= n - 1: return True

    return True
