# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# Generic sort does not use the fact there are only three values. Engine sort also uses extra memory.
# How it works: nums.sort with a numeric comparator. Correct, but not the point of the problem.

def sort_colors(nums):
    nums.sort()
    return nums


# Method 2: Optimal
# Time: O(n) | Space: O(1)
# Two linear passes and three counters. Extra memory is three integers.
# How it works: count zeros, ones, and twos. Write that many 0s, then 1s, then 2s into nums.

def sort_colors(nums):
    zeros = 0
    ones = 0
    twos = 0
    for i in range(len(nums)):

        if nums[i] == 0: zeros += 1
        elif nums[i] == 1: ones += 1
        else: twos += 1

    i = 0
    while zeros > 0: { zeros -= 1 nums[i] = 0 i += 1 }
    while ones > 0: { ones -= 1 nums[i] = 1 i += 1 }
    while twos > 0: { twos -= 1 nums[i] = 2 i += 1 }
    return nums


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# One pass, constant extra memory. Each index is visited a constant number of times.
# How it works: low writes 0s, high writes 2s, mid walks. After a swap with high, mid stays so the swapped-in value is classified.

def sort_colors(nums):
    low = 0
    mid = 0
    high = len(nums) - 1
    while mid <= high:
        if nums[mid] == 0:
            t = nums[low]
            nums[low] = nums[mid]
            nums[mid] = t
            low += 1
            mid += 1
        elif nums[mid] == 2:
            t = nums[high]
            nums[high] = nums[mid]
            nums[mid] = t
            high -= 1
        else:
            mid += 1
    return nums
