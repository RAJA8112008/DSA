# Method 1: Brute
# Time: O((max-min) * n) | Space: O(1)
# Sort, then try every distance from (max-min) down to 1. First distance that can place m balls is the answer. Distance range can be 10^9, so this times out.

def maxDistance(position, m):
  position = sorted(position)
  def can(dist):
    count, last = 1, position[0]
    for p in position[1:]:
      if p - last >= dist:
        count += 1
        last = p
    return count >= m
  span = position[-1] - position[0]
  for d in range(span, 0, -1):
    if can(d):
      return d
  return 0


# Method 2: Optimal
# Time: O(n log(max-min)) | Space: O(1)
# Sort once. Binary search the gap. Greedy: place the next ball at the first basket that is at least mid away from the last placed ball. If you place m, try a larger gap (lo = mid + 1).

def maxDistance(position, m):
  position = sorted(position)
  def can(dist):
    count, last = 1, position[0]
    for p in position[1:]:
      if p - last >= dist:
        count += 1
        last = p
        if count >= m:
          return True
    return False
  lo, hi, ans = 1, position[-1] - position[0], 0
  while lo <= hi:
    mid = (lo + hi) >> 1
    if can(mid):
      ans = mid
      lo = mid + 1
    else:
      hi = mid - 1
  return ans


# Method 3: More optimal
# Time: O(n log(max-min)) | Space: O(1)
# Overflow-safe mid. Half-open last-true: if mid works, lo = mid + 1, else hi = mid, then return lo - 1. No separate ans. Early stop once m balls are placed.

def maxDistance(position, m):
  position = sorted(position)
  def can(dist):
    count, last = 1, position[0]
    for p in position[1:]:
      if p - last >= dist:
        count += 1
        last = p
        if count >= m:
          return True
    return False
  lo, hi = 1, position[-1] - position[0] + 1
  while lo < hi:
    mid = lo + ((hi - lo) >> 1)
    if can(mid):
      lo = mid + 1
    else:
      hi = mid
  return lo - 1
