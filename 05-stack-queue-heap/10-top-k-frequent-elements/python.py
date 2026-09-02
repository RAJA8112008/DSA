# Method 1: Brute
# Time: O(n + u · k) | Space: O(u)
# Count in a map. Then k times scan all unique keys for the remaining max count and remove it. u is the number of unique values.

def topKFrequent(nums, k):
  count = {}
  for x in nums:
    count[x] = count.get(x, 0) + 1
  ans = []
  for t in range(k):
    bestKey, best = None, -1
    for key in list(count.keys()):
      if count[key] > best:
        best = count[key]; bestKey = key
    ans.append(bestKey)
    del count[bestKey]
  return ans


# Method 2: Optimal
# Time: O(n + u log u) | Space: O(u)
# Count, then sort unique keys by frequency descending, take k. Clear and fast enough for interview n.

def topKFrequent(nums, k):
  count = {}
  for x in nums:
    count[x] = count.get(x, 0) + 1
  keys = list(count.keys())
  keys.sort(key=lambda a: -count[a])
  return keys[:k]


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Bucket sort: buckets[i] holds numbers that appear i times. Walk i from n down and collect k numbers. Linear because counts are at most n. A size-k min-heap is O(n log k) if they want a heap instead.

def topKFrequent(nums, k):
  count = {}
  for x in nums:
    count[x] = count.get(x, 0) + 1
  buckets = [[] for _ in range(len(nums) + 1)]
  for num, c in count.items():
    buckets[c].append(num)
  ans = []
  f = len(buckets) - 1
  while f >= 0 and len(ans) < k:
    for x in buckets[f]:
      if len(ans) >= k: break
      ans.append(x)
    f -= 1
  return ans
