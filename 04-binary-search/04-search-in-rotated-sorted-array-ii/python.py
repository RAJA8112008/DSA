# Method 1: Brute
# Time: O(n) | Space: O(1)
# Duplicates already force O(n) in the worst case, so a linear scan is honest. Still too weak as the only answer: they want the rotated-half logic.

def search(nums, target):
  return target in nums


# Method 2: Optimal
# Time: O(log n) avg, O(n) worst | Space: O(1)
# If lo, mid, and hi are equal, shrink both ends. Otherwise one half is sorted; keep the half that can contain target. Worst case is all duplicates, which is linear.

def search(nums, target):
  lo, hi = 0, len(nums) - 1
  while lo <= hi:
    mid = lo + ((hi - lo) >> 1)
    if nums[mid] == target:
      return True
    if nums[lo] == nums[mid] == nums[hi]:
      lo += 1
      hi -= 1
      continue
    if nums[lo] <= nums[mid]:
      if nums[lo] <= target < nums[mid]:
        hi = mid - 1
      else:
        lo = mid + 1
    else:
      if nums[mid] < target <= nums[hi]:
        lo = mid + 1
      else:
        hi = mid - 1
  return False


# Method 3: More optimal
# Time: O(log n) avg, O(n) worst | Space: O(1)
# Skip a whole equal-run on each end instead of one index at a time when lo/mid/hi match. Fewer iterations on long duplicate prefixes and suffixes. Worst case is still linear.

def search(nums, target):
  lo, hi = 0, len(nums) - 1
  while lo <= hi:
    mid = lo + ((hi - lo) >> 1)
    if nums[mid] == target or nums[lo] == target or nums[hi] == target:
      return True
    if nums[lo] == nums[mid] == nums[hi]:
      while lo <= hi and nums[lo] == nums[mid]:
        lo += 1
      while lo <= hi and nums[hi] == nums[mid]:
        hi -= 1
      continue
    if nums[lo] <= nums[mid]:
      if nums[lo] < target < nums[mid]:
        hi = mid - 1
      else:
        lo = mid + 1
    else:
      if nums[mid] < target < nums[hi]:
        lo = mid + 1
      else:
        hi = mid - 1
  return False
