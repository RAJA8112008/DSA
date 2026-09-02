# Method 1: Brute
# Time: O(n²) | Space: O(1)
# Every pair is checked. For n numbers that is about n*(n-1)/2 additions.
# How it works: the outer loop picks the first index. The inner loop picks a later index. The first pair whose sum equals target is returned.

def two_sum(nums, target):
    n = len(nums)
    for i in range(n):

        for j in range(i + 1, n):

            if nums[i] + nums[j] == target: return [i, j]

    return []


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Sorting is the extra cost. After that, two pointers only walk the copied list once.
# How it works: store {value, index} so sorting does not lose positions. Move left up when the sum is too small, right down when it is too big.

def two_sum(nums, target):
    pairs = []
    for i in range(len(nums)):

        pairs.append([nums[i], i ])

    pairs.sort(key=lambda z: z[0])

    left = 0
    right = len(pairs) - 1
    while left < right:
        sum = pairs[left].value + pairs[right].value
        if sum == target: return [pairs[left].index, pairs[right].index]
        if sum < target: left += 1
        else: right -= 1
    return []


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# One pass. Each lookup in the map is average O(1), so the whole walk is O(n).
# How it works: for x, look up target - x. If it was stored, return those indexes. If not, store x and its index, then continue.

def two_sum(nums, target):
    seen = {}
    for i in range(len(nums)):

        need = target - nums[i]
        if need in seen: return [seen[need], i]
        seen[nums[i]] = i

    return []
