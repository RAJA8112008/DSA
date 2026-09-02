# Method 1: Brute
# Time: O(n^{k-1}) | Space: O(n)
# Recurse on the start index and how many pieces are left. Try every next cut. Exponential in k. Good for explaining the search tree, not for n = 1000.

def splitArray(nums, k):
  n = len(nums)
  inf = 10 ** 18
  def go(i, left):
    if left == 1:
      return sum(nums[i:])
    best, run = inf, 0
    for j in range(i, n - left + 1):
      run += nums[j]
      rest = go(j + 1, left - 1)
      cost = run if run > rest else rest
      if cost < best:
        best = cost
    return best
  return go(0, k)


# Method 2: Optimal
# Time: O(n^2 k) | Space: O(n k)
# dp[i][p] = min largest-sum using the first i numbers and p subarrays. Transition: last piece is nums[j..i-1], cost = max(dp[j][p-1], prefix[i]-prefix[j]). Polynomial, still slower than binary search for interview n.

def splitArray(nums, k):
  n = len(nums)
  prefix = [0] * (n + 1)
  for i, v in enumerate(nums):
    prefix[i + 1] = prefix[i] + v
  inf = 10 ** 18
  dp = [[inf] * (k + 1) for _ in range(n + 1)]
  dp[0][0] = 0
  for i in range(1, n + 1):
    for p in range(1, min(k, i) + 1):
      for j in range(p - 1, i):
        piece = prefix[i] - prefix[j]
        cost = dp[j][p - 1] if dp[j][p - 1] > piece else piece
        if cost < dp[i][p]:
          dp[i][p] = cost
  return dp[n][k]


# Method 3: More optimal
# Time: O(n log sum) | Space: O(1)
# Binary search the largest allowed piece sum. Greedy: grow a run until the next number would exceed mid, then start a new piece. If you need more than k pieces, mid is too small. This is the usual interview solution.

def splitArray(nums, k):
  def ok(lim):
    pieces, run = 1, 0
    for v in nums:
      if v > lim:
        return False
      if run + v > lim:
        pieces += 1
        run = 0
        if pieces > k:
          return False
      run += v
    return True
  lo, hi = max(nums), sum(nums)
  while lo < hi:
    mid = lo + ((hi - lo) >> 1)
    if ok(mid):
      hi = mid
    else:
      lo = mid + 1
  return lo
