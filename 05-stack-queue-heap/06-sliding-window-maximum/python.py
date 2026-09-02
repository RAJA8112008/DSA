# Method 1: Brute
# Time: O(n · k) | Space: O(1)
# For each window start, scan k items for the max. Simple and too slow when k is n/2.

def maxSlidingWindow(nums, k):
  out = []
  for i in range(len(nums) - k + 1):
    m = nums[i]
    for j in range(i + 1, i + k):
      if nums[j] > m: m = nums[j]
    out.append(m)
  return out


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Max-heap of [value, index] (store negated value in a min-heap). Pop the top while its index left the window. Lazy delete keeps the heap honest. Better than n*k, worse than a deque.

def maxSlidingWindow(nums, k):
  h = []
  def key(x): return x[0]
  def up(i):
    while i > 0:
      p = (i - 1) >> 1
      if key(h[i]) >= key(h[p]): break
      h[i], h[p] = h[p], h[i]
      i = p
  def down(i):
    n = len(h)
    while True:
      s = i
      l = i * 2 + 1
      r = l + 1
      if l < n and key(h[l]) < key(h[s]): s = l
      if r < n and key(h[r]) < key(h[s]): s = r
      if s == i: break
      h[i], h[s] = h[s], h[i]
      i = s
  def push(x):
    h.append(x); up(len(h) - 1)
  def pop():
    top = h[0]
    last = h.pop()
    if h:
      h[0] = last; down(0)
    return top
  def peek():
    return h[0]
  out = []
  for i, x in enumerate(nums):
    push((-x, i))
    if i < k - 1: continue
    while peek()[1] <= i - k: pop()
    out.append(-peek()[0])
  return out


# Method 3: More optimal
# Time: O(n) | Space: O(k)
# Decreasing deque of indices. Pop back while nums[i] is larger. Pop front if it left the window. Front is the max. Each index enters and leaves once.

from collections import deque
def maxSlidingWindow(nums, k):
  dq = deque()
  out = []
  for i in range(len(nums)):
    while dq and nums[dq[-1]] <= nums[i]:
      dq.pop()
    dq.append(i)
    if dq[0] <= i - k:
      dq.popleft()
    if i >= k - 1:
      out.append(nums[dq[0]])
  return out
