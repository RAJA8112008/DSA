# Method 1: Brute
# Time: O(n²) | Space: O(1)
# Every start index pairs with every end index. Inner additions make this quadratic.
# How it works: i is the start. sum grows as j walks right. best tracks the largest sum seen, including all-negative lists.

def max_sub_array(nums):
    best = float('-inf')
    n = len(nums)
    for i in range(n):

        sum = 0
        for j in range(i, n):

            sum += nums[j]
            if sum > best: best = sum

    return best


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Linear time with a DP array of length n.
# How it works: dp[i] is the best sum among subarrays that end at i. It is either nums[i] alone or dp[i - 1] + nums[i]. The answer is the max of dp.

def max_sub_array(nums):
    n = len(nums)
    dp = [None] * (n)
    dp[0] = nums[0]
    best = dp[0]
    for i in range(1, n):

        dp[i] = max(nums[i], dp[i - 1] + nums[i])
        if dp[i] > best: best = dp[i]

    return best


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Kadane: only the previous ending-sum is needed, so extra memory is constant.
# How it works: endingHere is dp[i] without the array. best is the global max. Start both from nums[0] so all-negative input still works.

def max_sub_array(nums):
    endingHere = nums[0]
    best = nums[0]
    for i in range(1, len(nums)):

        endingHere = max(nums[i], endingHere + nums[i])
        if endingHere > best: best = endingHere

    return best
