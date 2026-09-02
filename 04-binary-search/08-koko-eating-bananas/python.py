# Method 1: Brute
# Time: O(max(piles) * n) | Space: O(1)
# Try k = 1, 2, ... max pile. First k that finishes in h hours is the answer. Correct, but max pile can be 10^9 so this times out.

def minEatingSpeed(piles, h):
  def hours(k):
    return sum((p + k - 1) // k for p in piles)
  cap = max(piles)
  for k in range(1, cap + 1):
    if hours(k) <= h:
      return k
  return cap


# Method 2: Optimal
# Time: O(n log max(piles)) | Space: O(1)
# Binary search the first speed that finishes on time. If mid works, try slower (hi = mid). If not, need faster (lo = mid + 1). Each check walks all piles.

def minEatingSpeed(piles, h):
  def hours(k):
    return sum((p + k - 1) // k for p in piles)
  lo, hi = 1, max(piles)
  while lo < hi:
    mid = (lo + hi) >> 1
    if hours(mid) <= h:
      hi = mid
    else:
      lo = mid + 1
  return lo


# Method 3: More optimal
# Time: O(n log max(piles)) | Space: O(1)
# Overflow-safe mid. Integer ceil only (no float). Early exit in the hour count when the running total already exceeds h, so a failing speed can fail before the last pile.

def minEatingSpeed(piles, h):
  def ok(k):
    t = 0
    for p in piles:
      t += (p + k - 1) // k
      if t > h:
        return False
    return True
  lo, hi = 1, max(piles)
  while lo < hi:
    mid = lo + ((hi - lo) >> 1)
    if ok(mid):
      hi = mid
    else:
      lo = mid + 1
  return lo
