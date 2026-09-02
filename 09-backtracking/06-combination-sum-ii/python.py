# Method 1: Brute
# Time: O(n * 2^n) | Space: O(n * 2^n)
# Every index is take or skip with extra path copies. Keep combinations whose sum is target, unique them with a sorted-tuple Set. Duplicate indexes still explore the full 2^n tree.

def combinationSum2(cands, target):
  seen = set()
  ans = []
  def go(i, sm, path):
    if sm == target:
      key = tuple(sorted(path))
      if key not in seen:
        seen.add(key)
        ans.append(path[:])
      return
    if i == len(cands) or sm > target:
      return
    go(i + 1, sm, path[:])
    go(i + 1, sm + cands[i], path + [cands[i]])
  go(0, 0, [])
  return ans


# Method 2: Optimal
# Time: O(n * 2^n) | Space: O(n)
# Sort. Skip nums[i] == nums[i-1] at the same start so identical values do not start the same role twice. Each index is used at most once (go(i+1)).

def combinationSum2(cands, target):
  cands = sorted(cands)
  ans = []
  def go(start, remain, path):
    if remain == 0:
      ans.append(path[:])
      return
    for i in range(start, len(cands)):
      if i > start and cands[i] == cands[i - 1]:
        continue
      if cands[i] > remain:
        continue
      path.append(cands[i])
      go(i + 1, remain - cands[i], path)
      path.pop()
  go(0, target, [])
  return ans


# Method 3: More optimal
# Time: O(n * 2^n) | Space: O(n)
# After sort, break when cands[i] > remain. Later values are larger, so they cannot help. Same unique combinations, fewer recursive calls.

def combinationSum2(cands, target):
  cands = sorted(cands)
  ans = []
  def go(start, remain, path):
    if remain == 0:
      ans.append(path[:])
      return
    for i in range(start, len(cands)):
      if cands[i] > remain:
        break
      if i > start and cands[i] == cands[i - 1]:
        continue
      path.append(cands[i])
      go(i + 1, remain - cands[i], path)
      path.pop()
  go(0, target, [])
  return ans
