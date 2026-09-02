# Method 1: Brute
# Time: O(n·k) | Space: O(1)
# Each single rotate copies n items. Doing that k times (after k %= n, still up to n-1 times) is O(n²) in the worst case.
# How it works: save the last item, shift everyone right by one, put the saved item at index 0. Repeat k times.

def rotate(nums, k):
    n = len(nums)
    if n == 0: return nums
    k = k % n
    for step in range(k):

        last = nums[n - 1]
        for i in range(n - 1, 0, -1):
            nums[i] = nums[i - 1]
        nums[0] = last

    return nums


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# One extra array of length n, two linear copies.
# How it works: extra[(i + k) % n] = nums[i], then copy extra back into nums.

def rotate(nums, k):
    n = len(nums)
    if n == 0: return nums
    k = k % n
    extra = [None] * (n)
    for i in range(n):
        extra[(i + k) % n] = nums[i]
    for i in range(n):
        nums[i] = extra[i]
    return nums


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Each item is swapped a constant number of times. No extra list.
# How it works: reverse the whole array, reverse the first k items, reverse the rest. That is the right rotation.

def rotate(nums, k):
    n = len(nums)
    if n == 0: return nums
    k = k % n

    def reverse(left, right):
        while left < right:
            t = nums[left]
            nums[left] = nums[right]
            nums[right] = t
            left += 1
            right -= 1

    reverse(0, n - 1)
    reverse(0, k - 1)
    reverse(k, n - 1)
    return nums
