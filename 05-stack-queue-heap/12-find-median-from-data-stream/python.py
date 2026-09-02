# Method 1: Brute
# Time: O(n log n) find | Space: O(n)
# Keep every number. findMedian copies and sorts. addNum is O(1). Queries get slower as the stream grows.

class MedianFinder:
  def __init__(self):
    self.a = []
  def addNum(self, num):
    self.a.append(num)
  def findMedian(self):
    b = sorted(self.a)
    n = len(b)
    if n % 2: return b[(n - 1) // 2]
    return (b[n // 2 - 1] + b[n // 2]) / 2


# Method 2: Optimal
# Time: O(n) add, O(1) find | Space: O(n)
# Keep a sorted array. Binary search the insert index, then splice. findMedian is O(1). Better than sorting everything on each query.

class MedianFinder:
  def __init__(self):
    self.a = []
  def addNum(self, num):
    lo, hi = 0, len(self.a)
    while lo < hi:
      mid = (lo + hi) >> 1
      if self.a[mid] < num: lo = mid + 1
      else: hi = mid
    self.a.insert(lo, num)
  def findMedian(self):
    n = len(self.a)
    if n % 2: return self.a[(n - 1) // 2]
    return (self.a[n // 2 - 1] + self.a[n // 2]) / 2


# Method 3: More optimal
# Time: O(log n) add, O(1) find | Space: O(n)
# low is a max-heap (negated in a min-heap). high is a min-heap. Balance sizes. Median is low's top, or the average of both tops. True stream solution.

class MedianFinder:
  def __init__(self):
    self.low = []   # max-heap via negated values
    self.high = []  # min-heap of the upper half
  def _up(self, h, i, key):
    while i > 0:
      p = (i - 1) >> 1
      if key(h[i]) >= key(h[p]): break
      h[i], h[p] = h[p], h[i]
      i = p
  def _down(self, h, i, key):
    while True:
      s = i
      l, r = i * 2 + 1, i * 2 + 2
      if l < len(h) and key(h[l]) < key(h[s]): s = l
      if r < len(h) and key(h[r]) < key(h[s]): s = r
      if s == i: break
      h[i], h[s] = h[s], h[i]
      i = s
  def _push(self, h, x, key):
    h.append(x); self._up(h, len(h) - 1, key)
  def _pop(self, h, key):
    top = h[0]
    last = h.pop()
    if h:
      h[0] = last; self._down(h, 0, key)
    return top
  def addNum(self, num):
    ident = lambda x: x
    self._push(self.low, -num, ident)
    self._push(self.high, -self._pop(self.low, ident), ident)
    if len(self.high) > len(self.low):
      self._push(self.low, -self._pop(self.high, ident), ident)
  def findMedian(self):
    if len(self.low) > len(self.high): return -self.low[0]
    return (-self.low[0] + self.high[0]) / 2
