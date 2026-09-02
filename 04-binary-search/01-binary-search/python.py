# Method 1: Brute
# Time: O(n) | Space: O(1)
# Walk left to right and compare every value. Correct on any array, sorted or not. Interviews want this only as the baseline before you cut the search in half.

def search(nums, target):
  for i, v in enumerate(nums):
    if v == target:
      return i
  return -1


# Method 2: Optimal
# Time: O(log n) | Space: O(1)
# Closed range [lo, hi]. Equal mid returns. Smaller mid throws away the left half. Larger mid throws away the right half. Each step halves the live indexes.

def search(nums, target):
  lo, hi = 0, len(nums) - 1
  while lo <= hi:
    mid = (lo + hi) >> 1
    if nums[mid] == target:
      return mid
    if nums[mid] < target:
      lo = mid + 1
    else:
      hi = mid - 1
  return -1


# Method 3: More optimal
# Time: O(log n) | Space: O(1)
# Same log n probes, but mid = lo + (hi - lo) / 2 never overflows a 32-bit index sum. Endpoint checks skip a loop when target is outside the remaining values.

def search(nums, target):
  lo, hi = 0, len(nums) - 1
  while lo <= hi:
    if nums[lo] == target:
      return lo
    if nums[hi] == target:
      return hi
    mid = lo + ((hi - lo) >> 1)
    if nums[mid] == target:
      return mid
    if nums[mid] < target:
      lo = mid + 1
    else:
      hi = mid - 1
  return -1
