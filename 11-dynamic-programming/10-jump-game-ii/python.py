# Method 1: Brute
# Time: O(n^n) | Space: O(n)
# From i you try every legal step. No cache, so overlapping positions explode. Depth is at most n. Fine only as a correctness sketch.

def jump(nums):
    INF = 10 ** 9
    def go(i):
        if i >= len(nums) - 1:
            return 0
        best = INF
        for step in range(1, nums[i] + 1):
            best = min(best, 1 + go(i + step))
        return best
    return go(0)


# Method 2: Optimal
# Time: O(n^2) | Space: O(n)
# best[j] is min jumps to index j. From each i you relax the range i+1 .. i+nums[i]. Up to n updates per i. This is the basic DP table for min jumps.

def jump(nums):
    n = len(nums)
    INF = 10 ** 9
    best = [INF] * n
    best[0] = 0
    for i in range(n):
        step = 1
        while step <= nums[i] and i + step < n:
            best[i + step] = min(best[i + step], best[i] + 1)
            step += 1
    return best[n - 1]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Greedy BFS on the line. end is the close of the current jump’s window. farthest is the furthest index a jump from this window can reach. When i hits end, you spend one jump and open the next window. One pass, no array.

def jump(nums):
    jumps = 0
    end = 0
    farthest = 0
    for i in range(len(nums) - 1):
        farthest = max(farthest, i + nums[i])
        if i == end:
            jumps += 1
            end = farthest
    return jumps
