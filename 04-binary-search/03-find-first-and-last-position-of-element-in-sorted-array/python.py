# Method 1: Brute
# Time: O(n) | Space: O(1)
# One left-to-right pass. First time you see target, store i. Every time you see it, update last. Missing target leaves both at -1.

def searchRange(nums, target):
  first = last = -1
  for i, v in enumerate(nums):
    if v == target:
      if first < 0:
        first = i
      last = i
  return [first, last]


# Method 2: Optimal
# Time: O(log n) | Space: O(1)
# Two binary searches. When mid equals target, first-occurrence keeps searching left (hi = mid - 1) and last-occurrence keeps searching right (lo = mid + 1). Each is O(log n).

def searchRange(nums, target):
  def find(first):
    lo, hi, ans = 0, len(nums) - 1, -1
    while lo <= hi:
      mid = (lo + hi) >> 1
      if nums[mid] == target:
        ans = mid
        if first:
          hi = mid - 1
        else:
          lo = mid + 1
      elif nums[mid] < target:
        lo = mid + 1
      else:
        hi = mid - 1
    return ans
  return [find(True), find(False)]


# Method 3: More optimal
# Time: O(log n) | Space: O(1)
# Lower bound (first >= target) and upper bound (first > target). Last index is upper - 1. Overflow-safe mid. One helper, two flags, no extra ans in the loop.

def searchRange(nums, target):
  def bound(gt):
    lo, hi = 0, len(nums)
    while lo < hi:
      mid = lo + ((hi - lo) >> 1)
      if nums[mid] < target or (gt and nums[mid] == target):
        lo = mid + 1
      else:
        hi = mid
    return lo
  L = bound(False)
  if L == len(nums) or nums[L] != target:
    return [-1, -1]
  return [L, bound(True) - 1]
