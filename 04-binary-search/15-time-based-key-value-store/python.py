# Method 1: Brute
# Time: set O(1), get O(n) | Space: O(n)
# Append every set. On get, scan the whole list for that key and keep the latest time that is still <= timestamp. Fine until a key has many versions.

class TimeMap:
  def __init__(self):
    self.map = {}
  def set(self, key, value, timestamp):
    self.map.setdefault(key, []).append((timestamp, value))
  def get(self, key, timestamp):
    arr = self.map.get(key, [])
    ans = ""
    for t, v in arr:
      if t <= timestamp:
        ans = v
    return ans


# Method 2: Optimal
# Time: set O(1), get O(log n) | Space: O(n)
# Sets for one key arrive in increasing time, so the list is sorted. Binary search the last index whose time is <= timestamp. That is last-true on the time axis.

class TimeMap:
  def __init__(self):
    self.map = {}
  def set(self, key, value, timestamp):
    self.map.setdefault(key, []).append((timestamp, value))
  def get(self, key, timestamp):
    arr = self.map.get(key, [])
    lo, hi, ans = 0, len(arr) - 1, ""
    while lo <= hi:
      mid = (lo + hi) >> 1
      if arr[mid][0] <= timestamp:
        ans = arr[mid][1]
        lo = mid + 1
      else:
        hi = mid - 1
    return ans


# Method 3: More optimal
# Time: set O(1), get O(log n) | Space: O(n)
# Overflow-safe mid. Half-open search for the first time > timestamp; the answer is the previous slot. No extra ans string in the loop. Same log probes, slightly cleaner bound.

class TimeMap:
  def __init__(self):
    self.map = {}
  def set(self, key, value, timestamp):
    self.map.setdefault(key, []).append((timestamp, value))
  def get(self, key, timestamp):
    arr = self.map.get(key, [])
    lo, hi = 0, len(arr)
    while lo < hi:
      mid = lo + ((hi - lo) >> 1)
      if arr[mid][0] <= timestamp:
        lo = mid + 1
      else:
        hi = mid
    return "" if lo == 0 else arr[lo - 1][1]
