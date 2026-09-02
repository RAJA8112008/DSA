# Method 1: Brute
# Time: O(n²) | Space: O(1)
# Each pair is compared. Fine for tiny lists, too slow for large n.
# How it works: if nums[i] equals nums[j] for j > i, a duplicate exists.

def contains_duplicate(nums):
    n = len(nums)
    for i in range(n):

        for j in range(i + 1, n):

            if nums[i] == nums[j]: return True

    return False


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Copy then sort, then a linear neighbor check. Sorting dominates.
# How it works: equals become neighbors after sort. If two neighbors match, return true.

def contains_duplicate(nums):
    copy = nums[:]
    copy.sort()
    for i in range(1, len(copy)):

        if copy[i] == copy[i - 1]: return True

    return False


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# One pass. Set.has is average O(1).
# How it works: if the set already has the number, it is a duplicate. Otherwise add it.

def contains_duplicate(nums):
    seen = set()
    for i in range(len(nums)):

        if nums[i] in seen: return True
        seen.add(nums[i])

    return False
