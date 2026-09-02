# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each value, count how many times it appears. Push it once if the count is 2. Slow, no extra set.

def findDuplicates(nums):
  out = []
  n = len(nums)
  for i in range(n):
    c = sum(1 for j in range(n) if nums[j] == nums[i])
    if c == 2 and nums[i] not in out:
      out.append(nums[i])
  return out


# Method 2: Optimal
# Time: O(n log n) | Space: O(1) extra
# Sort, then walk adjacent pairs. Equal neighbors are a duplicate. Simple, mutates order.

def findDuplicates(nums):
  a = sorted(nums)
  out = []
  for i in range(1, len(a)):
    if a[i] == a[i - 1]:
      out.append(a[i])
  return out


# Method 3: More optimal
# Time: O(n) | Space: O(1) extra
# Value x belongs at index x-1. Negate that slot when you first see x. If it is already negative, x is the duplicate. Restore signs later if you must.

def findDuplicates(nums):
  out = []
  for i in range(len(nums)):
    x = abs(nums[i])
    slot = x - 1
    if nums[slot] < 0:
      out.append(x)
    else:
      nums[slot] = -nums[slot]
  return out
