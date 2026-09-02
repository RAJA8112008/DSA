# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# Copy, sort, then walk looking for the next needed positive. Sorting dominates.
# How it works: ignore non-positives and duplicates. need starts at 1. When you see need, bump it. At the end, need is missing.

def first_missing_positive(nums):
    list = sorted(nums)
    need = 1
    for i in range(len(list)):

        if list[i] <= 0: continue
        if list[i] == need: need += 1
        elif list[i] > need: return need

    return need


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# One Set of the input, then at most n+1 membership tests.
# How it works: the answer is in 1..n+1. Probe 1, 2, 3, … until a value is not in the set.

def first_missing_positive(nums):
    set = set(nums)
    need = 1
    while need in set: need += 1
    return need


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Index-as-hash / cyclic placement. Extra memory is a few integers. The input is overwritten.
# How it works: swap nums[i] to index nums[i]-1 while that value is in 1..n and not already home. Then the first i with nums[i] !== i+1 is the missing number; else n+1.

def first_missing_positive(nums):
    n = len(nums)
    for i in range(n):

        while (
        nums[i] >= 1  and
        nums[i] <= n  and
        nums[nums[i] - 1] != nums[i]
        ):
            dest = nums[i] - 1
            t = nums[i]
            nums[i] = nums[dest]
            nums[dest] = t

    for i in range(n):

        if nums[i] != i + 1: return i + 1

    return n + 1
