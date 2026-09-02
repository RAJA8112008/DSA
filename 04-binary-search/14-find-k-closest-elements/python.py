# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# Pair each value with its distance, sort by distance then by value, take k items, sort those k again so the answer is ascending. Heavy, but matches the tie rule clearly.

def findClosestElements(arr, k, x):
  idx = list(range(len(arr)))
  idx.sort(key=lambda i: (abs(arr[i] - x), arr[i]))
  pick = sorted(arr[i] for i in idx[:k])
  return pick


# Method 2: Optimal
# Time: O(n - k) | Space: O(k)
# The answer is a contiguous window of length k (the array is sorted). Shrink from both ends until the window is size k. Drop the farther end; on a tie drop the right (larger) value.

def findClosestElements(arr, k, x):
  lo, hi = 0, len(arr) - 1
  while hi - lo + 1 > k:
    if abs(arr[lo] - x) > abs(arr[hi] - x):
      lo += 1
    else:
      hi -= 1
  return arr[lo:hi + 1]


# Method 3: More optimal
# Time: O(log(n - k) + k) | Space: O(k)
# Binary search the left index of the k-window in [0, n-k]. If x is closer to arr[mid+k] than to arr[mid], the window should start further right. Overflow-safe mid. Copy k values at the end.

def findClosestElements(arr, k, x):
  lo, hi = 0, len(arr) - k
  while lo < hi:
    mid = lo + ((hi - lo) >> 1)
    if x - arr[mid] > arr[mid + k] - x:
      lo = mid + 1
    else:
      hi = mid
  return arr[lo:lo + k]
