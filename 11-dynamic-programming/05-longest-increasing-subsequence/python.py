# Method 1: Brute
# Time: O(2^n) | Space: O(n)
# At each index you take (if it is larger than prev) or skip. No cache, so every subset of positions is explored. Depth is n.

def lengthOfLIS(nums):
    def go(i, prev):
        if i == len(nums):
            return 0
        skip = go(i + 1, prev)
        take = 0
        if prev == -1 or nums[i] > nums[prev]:
            take = 1 + go(i + 1, i)
        return max(skip, take)
    return go(0, -1)


# Method 2: Optimal
# Time: O(n^2) | Space: O(n)
# len[i] is the longest increasing subsequence that ends at i. Each pair (j, i) with j < i is checked once. n^2 states of work, one array of n cells. Standard interview DP.

def lengthOfLIS(nums):
    n = len(nums)
    if n == 0:
        return 0
    length = [1] * n
    best = 1
    for i in range(n):
        for j in range(i):
            if nums[j] < nums[i]:
                length[i] = max(length[i], length[j] + 1)
        best = max(best, length[i])
    return best


# Method 3: More optimal
# Time: O(n log n) | Space: O(n)
# tails[k] is the smallest tail of all increasing subsequences of length k+1. For each number, binary search the first tail that is >= num and replace it (or append). Length of tails is the LIS length. Tails is not the LIS itself.

def lengthOfLIS(nums):
    tails = []
    for num in nums:
        left, right = 0, len(tails)
        while left < right:
            mid = (left + right) // 2
            if tails[mid] < num:
                left = mid + 1
            else:
                right = mid
        if left == len(tails):
            tails.append(num)
        else:
            tails[left] = num
    return len(tails)
