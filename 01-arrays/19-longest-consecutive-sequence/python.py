# Method 1: Brute
# Time: O(n²) | Space: O(n)
# From each unique start you may scan the set repeatedly. In the worst case this is quadratic.
# How it works: put numbers in a Set. For each start, count start, start+1, start+2 while those values exist. Keep the longest streak.

def longest_consecutive(nums):
    set = set(nums)
    best = 0
    for x in set:
        length = 1
        cur = x
        while cur + 1 in set:
            cur += 1
            length += 1
        if length > best: best = length
    return best


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Unique copy plus sort, then a linear neighbor walk. Sorting is the bottleneck.
# How it works: skip duplicates while scanning the sorted unique list. A gap of 1 grows the streak; a larger gap resets it.

def longest_consecutive(nums):
    if len(nums) == 0: return 0
    list = list(set(nums))
    list.sort()
    best = 1
    streak = 1
    for i in range(1, len(list)):

        if list[i] == list[i - 1] + 1:
            streak += 1
            if streak > best: best = streak
        else:
            streak = 1

    return best


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Each number is inserted once and then used in at most one forward walk.
# How it works: only start a streak when x-1 is missing. Then count x, x+1, ... while present. That visits each run from its true beginning.

def longest_consecutive(nums):
    set = set(nums)
    best = 0
    for x in set:
        if x - 1 in set: continue
        length = 1
        cur = x
        while cur + 1 in set:
            cur += 1
            length += 1
        if length > best: best = length
    return best
