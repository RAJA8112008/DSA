# Method 1: Brute
# Time: O(n^4) | Space: O(1) extra
# Four nested indexes. Sort each hit so a set of strings can drop duplicates. Correct and too slow.

def fourSum(nums, target):
  n = len(nums)
  seen = set()
  out = []
  for i in range(n):
    for j in range(i + 1, n):
      for k in range(j + 1, n):
        for p in range(k + 1, n):
          if nums[i] + nums[j] + nums[k] + nums[p] != target:
            continue
          quad = tuple(sorted([nums[i], nums[j], nums[k], nums[p]]))
          if quad in seen:
            continue
          seen.add(quad)
          out.append(list(quad))
  return out


# Method 2: Optimal
# Time: O(n^3) | Space: O(n)
# Fix i, j, k. Look up target - (a+b+c) in a set of values after k. Still cubic, extra set, duplicates need care. A stepping stone to two pointers.

def fourSum(nums, target):
  n = len(nums)
  seenQ = set()
  out = []
  for i in range(n):
    for j in range(i + 1, n):
      seen = set()
      for k in range(j + 1, n):
        need = target - nums[i] - nums[j] - nums[k]
        if need in seen:
          quad = tuple(sorted([nums[i], nums[j], nums[k], need]))
          if quad not in seenQ:
            seenQ.add(quad)
            out.append(list(quad))
        seen.add(nums[k])
  return out


# Method 3: More optimal
# Time: O(n^3) | Space: O(1) extra
# Sort. Fix i and j. Two pointers on the rest. Skip duplicate i, j, left, and right. Use 64-bit sums if the language overflows. This is the expected answer.

def fourSum(nums, target):
  nums = sorted(nums)
  n = len(nums)
  out = []
  for i in range(n):
    if i > 0 and nums[i] == nums[i - 1]:
      continue
    for j in range(i + 1, n):
      if j > i + 1 and nums[j] == nums[j - 1]:
        continue
      L, R = j + 1, n - 1
      while L < R:
        s = nums[i] + nums[j] + nums[L] + nums[R]
        if s == target:
          out.append([nums[i], nums[j], nums[L], nums[R]])
          L += 1
          R -= 1
          while L < R and nums[L] == nums[L - 1]:
            L += 1
          while L < R and nums[R] == nums[R + 1]:
            R -= 1
        elif s < target:
          L += 1
        else:
          R -= 1
  return out
