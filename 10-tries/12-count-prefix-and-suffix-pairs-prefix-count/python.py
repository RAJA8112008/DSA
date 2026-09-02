# Method 1: Brute
# Time: O(n L) | Space: O(1)
# For each word, compare pref character by character. Count a hit when the whole pref matches.

def prefixCount(words, pref):
  c = 0
  n = len(pref)
  for w in words:
    if len(w) < n:
      continue
    ok = True
    for j in range(n):
      if w[j] != pref[j]:
        ok = False
        break
    if ok:
      c += 1
  return c


# Method 2: Optimal
# Time: O(n^2 L) | Space: O(1)
# For the related prefix-and-suffix-pairs problem: try every i < j and test both prefix and suffix. Still brute pairs, but the check is the right idea before a trie of (char, char) pairs.

def countPrefixSuffixPairs(words):
  def isPrefixAndSuffix(a, b):
    n, m = len(a), len(b)
    if n > m:
      return False
    return b.startswith(a) and b.endswith(a)
  c = 0
  for i in range(len(words)):
    for j in range(i + 1, len(words)):
      if isPrefixAndSuffix(words[i], words[j]):
        c += 1
  return c


# Method 3: More optimal
# Time: O(total chars) | Space: O(total chars)
# Prefix count: insert every word into a trie, increment pref on each node, then walk pref once. For prefix-and-suffix pairs, a twin trie on (first char, last char) pairs is the upgrade when n is large.

def prefixCount(words, pref):
  def node():
    return {"ch": [None] * 26, "pref": 0}
  root = node()
  for w in words:
    cur = root
    for ch in w:
      idx = ord(ch) - 97
      if cur["ch"][idx] is None:
        cur["ch"][idx] = node()
      cur = cur["ch"][idx]
      cur["pref"] += 1
  cur = root
  for ch in pref:
    idx = ord(ch) - 97
    if cur["ch"][idx] is None:
      return 0
    cur = cur["ch"][idx]
  return cur["pref"]
