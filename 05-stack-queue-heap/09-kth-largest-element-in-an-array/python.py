# Method 1: Brute
# Time: O(n · k) | Space: O(n)
# Copy the array. k times, find and remove the current max. Fine for tiny k, slow for k near n.

def findKthLargest(nums, k):
  a = nums[:]
  ans = 0
  for t in range(k):
    best = 0
    for i in range(1, len(a)):
      if a[i] > a[best]: best = i
    ans = a[best]
    a.pop(best)
  return ans


# Method 2: Optimal
# Time: O(n log n) | Space: O(n)
# Sort descending (or ascending and index). Honest and short. Use this first in an interview, then offer a heap.

def findKthLargest(nums, k):
  a = sorted(nums, reverse=True)
  return a[k - 1]


# Method 3: More optimal
# Time: O(n log k) | Space: O(k)
# Min-heap of size k. If the heap is full and x is bigger than the peek, replace the peek. The peek is the k-th largest. Tiny binary heap inlined. Quickselect is expected O(n) if they want that next.

def findKthLargest(nums, k):
  h = []
  def up(i):
    while i > 0:
      p = (i - 1) >> 1
      if h[i] >= h[p]: break
      h[i], h[p] = h[p], h[i]
      i = p
  def down(i):
    while True:
      s = i
      l = i * 2 + 1
      r = l + 1
      if l < len(h) and h[l] < h[s]: s = l
      if r < len(h) and h[r] < h[s]: s = r
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
  for x in nums:
    if len(h) < k: push(x)
    elif x > h[0]:
      pop(); push(x)
  return h[0]
