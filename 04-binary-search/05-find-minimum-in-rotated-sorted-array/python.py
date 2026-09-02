# Method 1: Brute
# Time: O(n) | Space: O(1)
# Track the smallest value while walking. Rotation does not matter. This is the check you mention, then you switch to log n.

def findMin(nums):
  best = nums[0]
  for v in nums:
    if v < best:
      best = v
  return best


# Method 2: Optimal
# Time: O(log n) | Space: O(1)
# Compare mid with the right end. A drop after mid means the pivot is to the right. No drop means the pivot is mid or left. Unique values keep this strictly log n.

def findMin(nums):
  lo, hi = 0, len(nums) - 1
  while lo < hi:
    mid = (lo + hi) >> 1
    if nums[mid] > nums[hi]:
      lo = mid + 1
    else:
      hi = mid
  return nums[lo]


# Method 3: More optimal
# Time: O(log n) | Space: O(1)
# Overflow-safe mid. If nums[lo] <= nums[hi], the remaining slice is already sorted, so nums[lo] is the min and you can stop. Helps the no-rotation case in one check.

def findMin(nums):
  lo, hi = 0, len(nums) - 1
  while lo < hi:
    if nums[lo] <= nums[hi]:
      return nums[lo]
    mid = lo + ((hi - lo) >> 1)
    if nums[mid] > nums[hi]:
      lo = mid + 1
    else:
      hi = mid
  return nums[lo]
