# Method 1: Brute
# Time: O(n * 2^n) | Space: O(n * 2^n)
# Build every subset with extra path copies, stringify, and keep a Set. Duplicate work is thrown away after you already built it. Fine for tiny n, not the interview finish.

def subsetsWithDup(nums):
  seen = set()
  ans = []
  def go(i, path):
    if i == len(nums):
      key = tuple(sorted(path))
      if key not in seen:
        seen.add(key)
        ans.append(path[:])
      return
    go(i + 1, path[:])
    take = path[:]
    take.append(nums[i])
    go(i + 1, take)
  go(0, [])
  return ans


# Method 2: Optimal
# Time: O(n * 2^n) | Space: O(n)
# Sort, then at each start skip nums[i] when it equals nums[i-1]. Those two 2s cannot start the same role twice, so [1,2] appears once. One path, push/pop.

def subsetsWithDup(nums):
  nums = sorted(nums)
  ans = []
  def go(start, path):
    ans.append(path[:])
    for i in range(start, len(nums)):
      if i > start and nums[i] == nums[i - 1]:
        continue
      path.append(nums[i])
      go(i + 1, path)
      path.pop()
  go(0, [])
  return ans


# Method 3: More optimal
# Time: O(n * 2^n) | Space: O(n)
# Same sort-and-skip, plus you can count how many copies of this value exist and take 0..count in one shot. That collapses a chain of duplicate-index decisions into one loop.

def subsetsWithDup(nums):
  nums = sorted(nums)
  ans = []
  def go(start, path):
    ans.append(path[:])
    i = start
    while i < len(nums):
      j = i
      while j < len(nums) and nums[j] == nums[i]:
        j += 1
      count = j - i
      for take in range(1, count + 1):
        path.append(nums[i])
        go(j, path)
      for take in range(count):
        path.pop()
      i = j
  go(0, [])
  return ans
