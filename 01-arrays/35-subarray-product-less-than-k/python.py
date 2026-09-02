# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each L, grow R, multiply. Count when prod < k. Watch overflow in fixed-width ints; JS numbers are fine for the usual constraints.

def numSubarrayProductLessThanK(nums, k):
  n = len(nums)
  c = 0
  for i in range(n):
    p = 1
    for j in range(i, n):
      p *= nums[j]
      if p < k:
        c += 1
      else:
        break
  return c


# Method 2: Optimal
# Time: O(n²) | Space: O(1)
# Same nested loops, but this is already the best brute because products only grow (nums >= 1) so you can break. Still quadratic worst case when k is huge.

def numSubarrayProductLessThanK(nums, k):
  if k <= 1:
    return 0
  c = 0
  n = len(nums)
  for i in range(n):
    p = 1
    j = i
    while j < n and p * nums[j] < k:
      p *= nums[j]
      c += 1
      j += 1
  return c


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Window [left, right]. Multiply nums[right]. While product >= k, divide nums[left] and left++. Every new right adds (right-left+1) subarrays that end at right. If k <= 1 the answer is 0.

def numSubarrayProductLessThanK(nums, k):
  if k <= 1:
    return 0
  prod = 1
  left = 0
  c = 0
  for right, x in enumerate(nums):
    prod *= x
    while prod >= k:
      prod //= nums[left]
      left += 1
    c += right - left + 1
  return c
