# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each index you scan the rest of the list looking for the same value.
# How it works: if nums[j] === nums[i] for j > i, that value is the duplicate.

def find_duplicate(nums):
    n = len(nums)
    for i in range(n):

        for j in range(i + 1, n):

            if nums[i] == nums[j]: return nums[i]

    return -1


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Copy and sort, then scan neighbors. Sorting dominates. Extra memory is the copy (input stays unchanged).
# How it works: after sort, the repeated number sits next to itself.

def find_duplicate(nums):
    copy = sorted(nums)
    for i in range(1, len(copy)):

        if copy[i] == copy[i - 1]: return copy[i]

    return -1


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Floyd cycle detection. Values in 1..n act as next pointers, so a duplicate creates a cycle. No extra array, input not written.
# How it works: slow moves one hop, fast moves two, until they meet. Reset slow to the start; the next meeting is the cycle entrance, which is the duplicate.

def find_duplicate(nums):
    slow = nums[0]
    fast = nums[0]
    while True:

        slow = nums[slow]
        fast = nums[nums[fast]]

        if not (slow != fast): break
    slow = nums[0]
    while slow != fast:
        slow = nums[slow]
        fast = nums[fast]
    return slow
