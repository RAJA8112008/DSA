# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each candidate v in 1..n, scan the array. If it never appears, it is missing.

def findDisappearedNumbers(nums):
  n = len(nums)
  out = []
  for v in range(1, n + 1):
    if v not in nums:
      out.append(v)
  return out


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# A boolean array (or a set) of seen values. Then walk 1..n and collect the false slots.

def findDisappearedNumbers(nums):
  n = len(nums)
  seen = [False] * (n + 1)
  for x in nums:
    seen[x] = True
  return [v for v in range(1, n + 1) if not seen[v]]


# Method 3: More optimal
# Time: O(n) | Space: O(1) extra
# For each value x, negate nums[abs(x)-1]. Values whose slots stay positive never appeared. Same marking trick as Find All Duplicates.

def findDisappearedNumbers(nums):
  for x in nums:
    slot = abs(x) - 1
    if nums[slot] > 0:
      nums[slot] = -nums[slot]
  return [i + 1 for i in range(len(nums)) if nums[i] > 0]
