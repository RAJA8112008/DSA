# Method 1: Brute
# Time: O(n²) | Space: O(1)
# Each zero may be swapped toward the end across many cells. Worst case quadratic.
# How it works: when you see a zero, swap it right until a non-zero neighbor is found or you hit the end. Slow, but in place.

def move_zeroes(nums):
    n = len(nums)
    for i in range(n):

        if nums[i] != 0: continue
        j = i + 1
        while j < n and nums[j] == 0: j += 1
        if j == n: break
        t = nums[i]
        nums[i] = nums[j]
        nums[j] = t

    return nums


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Extra array holds the compacted values, then you copy back.
# How it works: collect non-zeros, append zeros until length n, copy into nums.

def move_zeroes(nums):
    extra = []
    for i in range(len(nums)):

        if nums[i] != 0: extra.append(nums[i])

    while len(extra) < len(nums): extra.append(0)
    for i in range(len(nums)):
        nums[i] = extra[i]
    return nums


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# One write index, two linear passes, no extra list.
# How it works: copy each non-zero to write and increment write. Then fill nums[write..] with 0.

def move_zeroes(nums):
    write = 0
    for read in range(len(nums)):

        if nums[read] != 0:
            nums[write] = nums[read]
            write += 1

    while write < len(nums):
        nums[write] = 0
        write += 1
    return nums
