# Method 1: Brute
# Time: O(n^{target/min}) | Space: O(target/min)
# Every call copies path.concat. You keep going while the sum is not past target, with no sort prune. Extra arrays at every node. Correct but heavy.

def combinationSum(cands, target):
  ans = []
  def go(start, sm, path):
    if sm == target:
      ans.append(path)
      return
    if sm > target:
      return
    for i in range(start, len(cands)):
      go(i, sm + cands[i], path + [cands[i]])
  go(0, 0, [])
  return ans


# Method 2: Optimal
# Time: O(n^{target/min}) | Space: O(target/min)
# One path, push/pop. remain shrinks. Call go(i, remain - cands[i]) to reuse this value, or move to i+1 to skip. Copy only at remain == 0.

def combinationSum(cands, target):
  ans = []
  def go(i, remain, path):
    if remain == 0:
      ans.append(path[:])
      return
    if i == len(cands) or remain < 0:
      return
    go(i + 1, remain, path)
    path.append(cands[i])
    go(i, remain - cands[i], path)
    path.pop()
  go(0, target, [])
  return ans


# Method 3: More optimal
# Time: O(n^{target/min}) | Space: O(target/min)
# Sort first. In the for-loop, break when cands[i] > remain so larger later values are never tried. Same answers, fewer dead branches.

def combinationSum(cands, target):
  cands = sorted(cands)
  ans = []
  def go(start, remain, path):
    if remain == 0:
      ans.append(path[:])
      return
    for i in range(start, len(cands)):
      if cands[i] > remain:
        break
      path.append(cands[i])
      go(i, remain - cands[i], path)
      path.pop()
  go(0, target, [])
  return ans
