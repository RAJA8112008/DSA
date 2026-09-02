# Method 1: Brute
# Time: O(n) | Space: O(1)
# Check each index against its neighbors. First (or any) success is a peak. Ends only need one comparison. Simple, not log n.

def findPeakElement(nums):
  n = len(nums)
  for i in range(n):
    leftOk = i == 0 or nums[i] > nums[i - 1]
    rightOk = i == n - 1 or nums[i] > nums[i + 1]
    if leftOk and rightOk:
      return i
  return 0


# Method 2: Optimal
# Time: O(log n) | Space: O(1)
# Slope test: if mid is less than mid + 1, drop the left (including mid). Else drop the right. The remaining range always contains a peak because the ends behave like -infinity.

def findPeakElement(nums):
  lo, hi = 0, len(nums) - 1
  while lo < hi:
    mid = (lo + hi) >> 1
    if nums[mid] < nums[mid + 1]:
      lo = mid + 1
    else:
      hi = mid
  return lo


# Method 3: More optimal
# Time: O(log n) | Space: O(log n)
# Same slope rule as a recursive function. Overflow-safe mid. The extra space is the call stack of log n frames. Iterative is usually preferred; this is the form you write if they ask for recursion.

def findPeakElement(nums):
  def go(lo, hi):
    if lo == hi:
      return lo
    mid = lo + ((hi - lo) >> 1)
    if nums[mid] < nums[mid + 1]:
      return go(mid + 1, hi)
    return go(lo, mid)
  return go(0, len(nums) - 1)
