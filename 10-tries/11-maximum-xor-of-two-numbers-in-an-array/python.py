# Method 1: Brute
# Time: O(n^2) | Space: O(1)
# XOR every pair, keep the max. Correct, too slow for n = 2e5.

def findMaximumXOR(nums):
  best = 0
  n = len(nums)
  for i in range(n):
    for j in range(i + 1, n):
      x = nums[i] ^ nums[j]
      if x > best:
        best = x
  return best


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Build the answer from bit 31 down. Assume the next bit can be 1. If some prefix ^ candidate exists in the set of current prefixes, keep that bit. Hash set of prefixes is the usual O(n) per bit trick.

def findMaximumXOR(nums):
  best = 0
  mask = 0
  for b in range(31, -1, -1):
    mask |= (1 << b)
    seen = set(x & mask for x in nums)
    cand = best | (1 << b)
    for p in seen:
      if (p ^ cand) in seen:
        best = cand
        break
  return best


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Insert every number into a binary trie (high bit first). For each number, walk the opposite bit when it exists. That walk is the max XOR against the set. Same O(32 n), clearer as a trie.

def findMaximumXOR(nums):
  def bitNode():
    return {"ch": [None, None]}
  root = bitNode()
  def insert(x):
    cur = root
    for b in range(31, -1, -1):
      bit = (x >> b) & 1
      if cur["ch"][bit] is None:
        cur["ch"][bit] = bitNode()
      cur = cur["ch"][bit]
  def best(x):
    cur = root
    ans = 0
    for b in range(31, -1, -1):
      bit = (x >> b) & 1
      want = 1 - bit
      if cur["ch"][want] is not None:
        ans |= (1 << b)
        cur = cur["ch"][want]
      else:
        cur = cur["ch"][bit]
    return ans
  for x in nums:
    insert(x)
  out = 0
  for x in nums:
    v = best(x)
    if v > out:
      out = v
  return out
