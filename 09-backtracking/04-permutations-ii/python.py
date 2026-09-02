# Method 1: Brute
# Time: O(n * n!) | Space: O(n * n!)
# Generate every leftover-copy permutation, stringify, keep a Set. Duplicate 1s still walk the full n! tree. Extra copies plus the Set.

def permuteUnique(nums):
  seen = set()
  ans = []
  def go(left, path):
    if not left:
      key = tuple(path)
      if key not in seen:
        seen.add(key)
        ans.append(path)
      return
    for i in range(len(left)):
      go(left[:i] + left[i+1:], path + [left[i]])
  go(list(nums), [])
  return ans


# Method 2: Optimal
# Time: O(n * n!) | Space: O(n)
# Sort so equal values are adjacent. Skip nums[j] when it equals nums[j-1] and used[j-1] is false. That forces a fixed order on identical numbers. One path, used[].

def permuteUnique(nums):
  nums = sorted(nums)
  ans = []
  used = [False] * len(nums)
  def go(path):
    if len(path) == len(nums):
      ans.append(path[:])
      return
    for j in range(len(nums)):
      if used[j]:
        continue
      if j > 0 and nums[j] == nums[j - 1] and not used[j - 1]:
        continue
      used[j] = True
      path.append(nums[j])
      go(path)
      path.pop()
      used[j] = False
  go([])
  return ans


# Method 3: More optimal
# Time: O(n * n!) | Space: O(n)
# In-place swap. A tiny set of values already swapped into start this round stops identical branches. No sort required. Same unique output, less leftover copying.

def permuteUnique(nums):
  ans = []
  def go(start):
    if start == len(nums):
      ans.append(nums[:])
      return
    seen = set()
    for i in range(start, len(nums)):
      if nums[i] in seen:
        continue
      seen.add(nums[i])
      nums[start], nums[i] = nums[i], nums[start]
      go(start + 1)
      nums[start], nums[i] = nums[i], nums[start]
  go(0)
  return ans
