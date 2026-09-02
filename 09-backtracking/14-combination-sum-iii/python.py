# Method 1: Brute
# Time: O(C(9, k) * k) | Space: O(k)
# Generate every k-subset with path copies, then filter by sum. C(9,k) is tiny, but you still build losers and copy arrays on every call.

def combinationSum3(k, n):
  ans = []
  def go(start, path):
    if len(path) == k:
      if sum(path) == n:
        ans.append(path)
      return
    for x in range(start, 10):
      go(x + 1, path + [x])
  go(1, [])
  return ans


# Method 2: Optimal
# Time: O(C(9, k) * k) | Space: O(k)
# One path. Push x, remain -= x, recurse x+1, pop. Snapshot when k numbers are chosen and remain is 0. No extra copies on internal nodes.

def combinationSum3(k, n):
  ans = []
  def go(start, left, remain, path):
    if left == 0:
      if remain == 0:
        ans.append(path[:])
      return
    for x in range(start, 10):
      path.append(x)
      go(x + 1, left - 1, remain - x, path)
      path.pop()
  go(1, k, n, [])
  return ans


# Method 3: More optimal
# Time: O(C(9, k) * k) | Space: O(k)
# Prune: remain < 0, or remain bigger than the largest left numbers, or remain smaller than the smallest left numbers. Stop the loop when x itself is already too big.

def combinationSum3(k, n):
  ans = []
  def go(start, left, remain, path):
    if left == 0:
      if remain == 0:
        ans.append(path[:])
      return
    min_sum = left * (2 * start + left - 1) // 2
    max_sum = left * (2 * 9 - left + 1) // 2
    if remain < min_sum or remain > max_sum:
      return
    for x in range(start, 10):
      if x > remain:
        break
      path.append(x)
      go(x + 1, left - 1, remain - x, path)
      path.pop()
  go(1, k, n, [])
  return ans
