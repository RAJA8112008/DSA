# Method 1: Brute
# Time: O(n! · n) | Space: O(n! · n)
# All unique permutations are generated and stored. n! grows immediately out of interview time limits.
# How it works: backtracking builds every perm. Sort the bag lexicographically. Find the current sequence and copy the next one (or the first) back into nums.

def next_permutation(nums):
    n = len(nums)
    start = nums[:]
    bag = []

    def permute(arr, start):
        if start == n:
            bag.append(arr[:])
            return
        used = set()
        for i in range(start, n):

            if arr[i] in used: continue
            used.add(arr[i])
            t = arr[start]
            arr[start] = arr[i]
            arr[i] = t
            permute(arr, start + 1)
            arr[i] = arr[start]
            arr[start] = t

    permute(nums[:], 0)
    bag.sort()

    idx = 0
    for i in range(len(bag)):

        same = True
        for j in range(n):

            if bag[i][j] != start[j]:
                same = False
                break

        if same:
            idx = i
            break

    next = bag[(idx + 1) % len(bag)]
    for i in range(n):
        nums[i] = next[i]
    return nums


# Method 2: Optimal
# Time: O(n log n) | Space: O(1)
# One reverse scan for the pivot, then a sort of the suffix. Sort of n items is the extra log factor.
# How it works: find the rightmost i with nums[i] < nums[i+1]. Find the smallest value to the right that is still larger than nums[i], swap, then sort the suffix ascending.

def next_permutation(nums):
    n = len(nums)
    i = n - 2
    while i >= 0 and nums[i] >= nums[i + 1]: i -= 1
    if i >= 0:
        j = n - 1
        while nums[j] <= nums[i]: j -= 1
        t = nums[i]
        nums[i] = nums[j]
        nums[j] = t
    suffix = nums[i + 1:].sort()
    for k in range(len(suffix)):
        nums[i + 1 + k] = suffix[k]
    return nums


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# The suffix is already non-increasing, so reverse is enough instead of sort.
# How it works: same pivot and swap. Reverse nums[i+1 .. end] in place.

def next_permutation(nums):
    n = len(nums)
    i = n - 2
    while i >= 0 and nums[i] >= nums[i + 1]: i -= 1

    def reverse(left, right):
        while left < right:
            t = nums[left]
            nums[left] = nums[right]
            nums[right] = t
            left += 1
            right -= 1

    if i >= 0:
        j = n - 1
        while nums[j] <= nums[i]: j -= 1
        t = nums[i]
        nums[i] = nums[j]
        nums[j] = t
    reverse(i + 1, n - 1)
    return nums
