# Method 1: Brute
# Time: O(m + n) | Space: O(m + n)
# Merge the two sorted lists into one, then pick the middle one or two values. Easy to code, extra memory, and not the log bound they asked for.

def findMedianSortedArrays(a, b):
  m, n = len(a), len(b)
  merged, i, j = [], 0, 0
  while i < m and j < n:
    if a[i] <= b[j]:
      merged.append(a[i]); i += 1
    else:
      merged.append(b[j]); j += 1
  merged.extend(a[i:])
  merged.extend(b[j:])
  mid = (m + n) // 2
  if (m + n) % 2:
    return float(merged[mid])
  return (merged[mid - 1] + merged[mid]) / 2.0


# Method 2: Optimal
# Time: O(m + n) | Space: O(1)
# Walk two pointers until you have seen the median index (and the one before it for even length). No merged array. Linear time, constant extra memory. Still not log.

def findMedianSortedArrays(a, b):
  m, n = len(a), len(b)
  last = (m + n) // 2
  i = j = prev = cur = 0
  for _ in range(last + 1):
    prev = cur
    if i < m and (j >= n or a[i] <= b[j]):
      cur = a[i]; i += 1
    else:
      cur = b[j]; j += 1
  if (m + n) % 2:
    return float(cur)
  return (prev + cur) / 2.0


# Method 3: More optimal
# Time: O(log(min(m, n))) | Space: O(1)
# Binary search a cut on the shorter array. Left parts together hold half the items. If aLeft > bRight, cut is too far right. If bLeft > aRight, cut is too far left. When both sides cross correctly, the median is max(lefts) or the average with min(rights).

def findMedianSortedArrays(a, b):
  if len(a) > len(b):
    return findMedianSortedArrays(b, a)
  m, n = len(a), len(b)
  lo, hi = 0, m
  half = (m + n + 1) // 2
  INF = 10 ** 15
  while lo <= hi:
    i = lo + ((hi - lo) >> 1)
    j = half - i
    aL = -INF if i == 0 else a[i - 1]
    aR = INF if i == m else a[i]
    bL = -INF if j == 0 else b[j - 1]
    bR = INF if j == n else b[j]
    if aL <= bR and bL <= aR:
      if (m + n) % 2:
        return float(aL if aL > bL else bL)
      left = aL if aL > bL else bL
      right = aR if aR < bR else bR
      return (left + right) / 2.0
    if aL > bR:
      hi = i - 1
    else:
      lo = i + 1
  return 0.0
