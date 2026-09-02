# Method 1: Brute
# Time: O(sum * n) | Space: O(1)
# Try every capacity from the heaviest box up to the total sum. First success is the answer. Sum can be huge, so this is only the idea sketch.

def shipWithinDays(weights, days):
  def need(cap):
    d, load = 1, 0
    for w in weights:
      if load + w > cap:
        d += 1
        load = 0
      load += w
    return d
  lo, hi = max(weights), sum(weights)
  for cap in range(lo, hi + 1):
    if need(cap) <= days:
      return cap
  return hi


# Method 2: Optimal
# Time: O(n log sum) | Space: O(1)
# Binary search capacity. Greedy load until the next package would overflow, then start a new day. If that day count is <= D, try a smaller cap.

def shipWithinDays(weights, days):
  def need(cap):
    d, load = 1, 0
    for w in weights:
      if load + w > cap:
        d += 1
        load = 0
      load += w
    return d
  lo, hi = max(weights), sum(weights)
  while lo < hi:
    mid = (lo + hi) >> 1
    if need(mid) <= days:
      hi = mid
    else:
      lo = mid + 1
  return lo


# Method 3: More optimal
# Time: O(n log sum) | Space: O(1)
# Overflow-safe mid. Stop counting days as soon as d exceeds the limit. Same answer, fewer wasted additions on a capacity that is clearly too small.

def shipWithinDays(weights, days):
  def ok(cap):
    d, load = 1, 0
    for w in weights:
      if w > cap:
        return False
      if load + w > cap:
        d += 1
        load = 0
        if d > days:
          return False
      load += w
    return True
  lo, hi = max(weights), sum(weights)
  while lo < hi:
    mid = lo + ((hi - lo) >> 1)
    if ok(mid):
      hi = mid
    else:
      lo = mid + 1
  return lo
