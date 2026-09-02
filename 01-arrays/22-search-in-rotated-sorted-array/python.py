# Method 1: Brute
# Time: O(n) | Space: O(1)
# Ignore rotation and scan. Correct, misses the log n goal.
# How it works: return the first index whose value equals target.

def search(nums, target):
    for i in range(len(nums)):

        if nums[i] == target: return i

    return -1


# Method 2: Optimal
# Time: O(log n) | Space: O(1)
# Two binary searches: one finds the rotation pivot, one searches a normal sorted range.
# How it works: pivot is the index of the smallest value. If target is in the left sorted run, search [0, pivot). Else search [pivot, n).

def search(nums, target):
    n = len(nums)
    def find_pivot():
        left = 0
        right = n - 1
        while left < right:
            mid = ((left + right) ) # 2
            if nums[mid] > nums[right]: left = mid + 1
            else: right = mid
        return left
    def bin_search(left, right):
        while left <= right:
            mid = ((left + right) ) # 2
            if nums[mid] == target: return mid
            if nums[mid] < target: left = mid + 1
            else: right = mid - 1
        return -1
    pivot = find_pivot()
    if target >= nums[pivot] and target <= nums[n - 1]: return bin_search(pivot, n - 1)
    return bin_search(0, pivot - 1)


# Method 3: More optimal
# Time: O(log n) | Space: O(1)
# A single loop. Still log n, but one search instead of pivot-then-search.
# How it works: if the left side is sorted and target is in that range, shrink right; otherwise go left. Symmetric for a sorted right side.

def search(nums, target):
    left = 0
    right = len(nums) - 1
    while left <= right:
        mid = ((left + right) ) # 2
        if nums[mid] == target: return mid
        if nums[left] <= nums[mid]:
            if nums[left] <= target and target < nums[mid]: right = mid - 1
            else: left = mid + 1
        else:
            if nums[mid] < target and target <= nums[right]: left = mid + 1
            else: right = mid - 1
    return -1
