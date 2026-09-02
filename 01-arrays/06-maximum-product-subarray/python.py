# Method 1: Brute
# Time: O(n²) | Space: O(1)
# Every subarray product is computed. Zeros and negatives are handled automatically, at quadratic cost.
# How it works: start at i, multiply as j walks right, track the max product.

def max_product(nums):
    best = float('-inf')
    n = len(nums)
    for i in range(n):

        prod = 1
        for j in range(i, n):

            prod *= nums[j]
            if prod > best: best = prod

    return best


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Linear time with min/max DP arrays. A negative number can turn a min into a max.
# How it works: maxEnd[i] and minEnd[i] consider nums[i] alone, or times the previous max, or times the previous min. Answer is the max of maxEnd.

def max_product(nums):
    n = len(nums)
    maxEnd = [None] * (n)
    minEnd = [None] * (n)
    maxEnd[0] = nums[0]
    minEnd[0] = nums[0]
    best = nums[0]
    for i in range(1, n):

        x = nums[i]
        maxEnd[i] = max(x, maxEnd[i - 1] * x, minEnd[i - 1] * x)
        minEnd[i] = min(x, maxEnd[i - 1] * x, minEnd[i - 1] * x)
        if maxEnd[i] > best: best = maxEnd[i]

    return best


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Same recurrence, two scalars instead of two arrays.
# How it works: copy prev max/min into locals before updating, because both formulas need the old values. Then take the global max of maxEnd.

def max_product(nums):
    maxEnd = nums[0]
    minEnd = nums[0]
    best = nums[0]
    for i in range(1, len(nums)):

        x = nums[i]
        prevMax = maxEnd
        prevMin = minEnd
        maxEnd = max(x, prevMax * x, prevMin * x)
        minEnd = min(x, prevMax * x, prevMin * x)
        if maxEnd > best: best = maxEnd

    return best
