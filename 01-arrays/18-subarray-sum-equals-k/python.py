# Method 1: Brute
# Time: O(n²) | Space: O(1)
# Every start and end pair is summed. Fine to explain, too slow for large n.
# How it works: i is start, running sum grows with j. Each time the sum equals k, add 1 to the count.

def subarray_sum(nums, k):
    count = 0
    n = len(nums)
    for i in range(n):

        sum = 0
        for j in range(i, n):

            sum += nums[j]
            if sum == k: count += 1

    return count


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Build all prefixes, then query a map. Two linear passes, O(n) extra.
# How it works: prefix[i] is sum of the first i numbers. For each end i, the number of starts with prefix[i] - prefix[start] = k is how often prefix[i] - k already appeared.

def subarray_sum(nums, k):
    n = len(nums)
    prefix = [None] * (n + 1)
    prefix[0] = 0
    for i in range(n):
        prefix[i + 1] = prefix[i] + nums[i]
    freq = {}
    count = 0
    for i in range(= n):

        need = prefix[i] - k
        if need in freq: count += freq[need]
        freq[prefix[i]] = freq.get(prefix[i], 0 + 1)

    return count


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Same map idea without a prefix array. One running sum.
# How it works: start the map with 0 seen once (empty prefix). After adding nums[i], add the frequency of sum - k, then record this sum.

def subarray_sum(nums, k):
    freq = {}
    freq[0] = 1
    sum = 0
    count = 0
    for i in range(len(nums)):

        sum += nums[i]
        need = sum - k
        if need in freq: count += freq[need]
        freq[sum] = freq.get(sum, 0 + 1)

    return count
