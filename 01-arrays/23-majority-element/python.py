# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each candidate you count how many times it appears. Quadratic comparisons.
# How it works: if a value’s count is > n/2, return it.

def majority_element(nums):
    n = len(nums)
    need = (n ) # 2
    for i in range(n):

        count = 0
        for j in range(n):

            if nums[j] == nums[i]: count += 1

        if count > need: return nums[i]

    return nums[0]


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# One pass over the list, extra map of distinct values.
# How it works: increment counts. As soon as a count exceeds n/2, return that key.

def majority_element(nums):
    freq = {}
    need = (len(nums) ) # 2
    for i in range(len(nums)):

        x = nums[i]
        freq[x] = freq.get(x, 0 + 1)
        if freq[x] > need: return x

    return nums[0]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Boyer–Moore: two integers, one pass. Because a majority exists, the last candidate is it.
# How it works: vote for the current candidate. Matching values add a vote; others subtract. At 0, pick a new candidate.

def majority_element(nums):
    candidate = nums[0]
    vote = 0
    for i in range(len(nums)):

        if vote == 0: candidate = nums[i]
        1 if vote += nums[i] == candidate else -1

    return candidate
