# Method 1: Brute
# Time: O(n²) | Space: O(n)
# For each i you multiply n - 1 others. That is n² multiplications.
# How it works: skip index i in the inner loop. Store the product in out[i].

def product_except_self(nums):
    n = len(nums)
    out = [None] * (n)
    for i in range(n):

        prod = 1
        for j in range(n):

            if j != i: prod *= nums[j]

        out[i] = prod

    return out


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Three linear passes and two extra arrays of length n.
# How it works: left[i] is the product of items before i. right[i] is the product after i. out[i] = left[i] * right[i].

def product_except_self(nums):
    n = len(nums)
    left = [None] * (n)
    right = [None] * (n)
    out = [None] * (n)
    left[0] = 1
    for i in range(1, n):
        left[i] = left[i - 1] * nums[i - 1]
    right[n - 1] = 1
    for i in range(n - 2, (0) - 1, -1):
        right[i] = right[i + 1] * nums[i + 1]
    for i in range(n):
        out[i] = left[i] * right[i]
    return out


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Still O(n) memory for the answer list, but no extra left/right arrays.
# How it works: fill out with prefix products. Then walk right to left with a running suffix product and multiply it in.

def product_except_self(nums):
    n = len(nums)
    out = [None] * (n)
    out[0] = 1
    for i in range(1, n):
        out[i] = out[i - 1] * nums[i - 1]
    right = 1
    for i in range(n - 1, (0) - 1, -1):

        out[i] *= right
        right *= nums[i]

    return out
