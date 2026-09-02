# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each candidate you scan the whole list. n+1 candidates times n looks.
# How it works: if value x is never found in nums, x is missing.

def missing_number(nums):
    n = len(nums)
    for x in range(= n):

        found = False
        for i in range(n):

            if nums[i] == x: { found = True break }

        if not found: return x

    return -1


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Copy and sort, then a linear gap check. Sorting dominates.
# How it works: after sort, index i should hold i. The first mismatch is the missing number. If the list is 0..n-1, n is missing.

def missing_number(nums):
    list = sorted(nums)
    for i in range(len(list)):

        if list[i] != i: return i

    return len(list)


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# XOR cancels pairs. Indexes 0..n XOR all values leaves the missing one. No overflow the way a large sum might in other languages (JS numbers are fine here too).
# How it works: start missing = n. XOR i and nums[i] for every i. The leftover is the missing number.

def missing_number(nums):
    n = len(nums)
    missing = n
    for i in range(n):

        missing = missing ^ i ^ nums[i]

    return missing
