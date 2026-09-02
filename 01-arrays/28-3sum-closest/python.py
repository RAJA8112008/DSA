# Method 1: Brute
# Time: O(n³) | Space: O(1)
# Every triple, track the sum whose absolute gap to target is smallest.

def threeSumClosest(nums, target):
  n = len(nums)
  best = nums[0] + nums[1] + nums[2]
  for i in range(n):
    for j in range(i + 1, n):
      for k in range(j + 1, n):
        s = nums[i] + nums[j] + nums[k]
        if abs(s - target) < abs(best - target):
          best = s
  return best


# Method 2: Optimal
# Time: O(n² log n) | Space: O(n)
# Sort. Fix two indexes, binary search the value closest to the leftover. Extra log n on each pair.

def threeSumClosest(nums, target):
  a = sorted(nums)
  n = len(a)
  best = a[0] + a[1] + a[2]
  for i in range(n):
    for j in range(i + 1, n):
      need = target - a[i] - a[j]
      lo, hi, pick = j + 1, n - 1, j + 1
      if lo > hi:
        continue
      while lo <= hi:
        mid = (lo + hi) // 2
        if a[mid] == need:
          return target
        pick = mid
        if a[mid] < need:
          lo = mid + 1
        else:
          hi = mid - 1
      for k in (pick, pick - 1, pick + 1):
        if k <= j or k >= n:
          continue
        s = a[i] + a[j] + a[k]
        if abs(s - target) < abs(best - target):
          best = s
  return best


# Method 3: More optimal
# Time: O(n²) | Space: O(1) extra
# Sort. Fix i. Two pointers on the rest. Move the side that improves the sum. Track the closest. Stop early on an exact hit.

def threeSumClosest(nums, target):
  a = sorted(nums)
  n = len(a)
  best = a[0] + a[1] + a[2]
  for i in range(n):
    L, R = i + 1, n - 1
    while L < R:
      s = a[i] + a[L] + a[R]
      if abs(s - target) < abs(best - target):
        best = s
      if s == target:
        return s
      if s < target:
        L += 1
      else:
        R -= 1
  return best
