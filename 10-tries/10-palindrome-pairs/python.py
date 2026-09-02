# Method 1: Brute
# Time: O(n^2 L) | Space: O(1)
# For every ordered pair, concatenate and test palindrome. Fine for tiny n, not for n = 5000.

def palindromePairs(words):
  def isPal(s):
    i, j = 0, len(s) - 1
    while i < j:
      if s[i] != s[j]:
        return False
      i += 1
      j -= 1
    return True
  out = []
  n = len(words)
  for i in range(n):
    for j in range(n):
      if i == j:
        continue
      if isPal(words[i] + words[j]):
        out.append([i, j])
  return out


# Method 2: Optimal
# Time: O(n L^2) | Space: O(n L)
# Map word -> index. For each word, try every split. If the left half is a palindrome, look up reverse(right). If the right half is a palindrome, look up reverse(left). Handles the empty-word case.

def palindromePairs(words):
  def isPal(s, a, b):
    while a < b:
      if s[a] != s[b]:
        return False
      a += 1
      b -= 1
    return True
  idx = {w: i for i, w in enumerate(words)}
  out = []
  seen = set()
  def add(i, j):
    if i == j or (i, j) in seen:
      return
    seen.add((i, j))
    out.append([i, j])
  for i, w in enumerate(words):
    n = len(w)
    for cut in range(n + 1):
      if isPal(w, cut, n - 1):
        rev = w[:cut][::-1]
        if rev in idx:
          add(i, idx[rev])
      if cut > 0 and isPal(w, 0, cut - 1):
        rev = w[cut:][::-1]
        if rev in idx:
          add(idx[rev], i)
  return out


# Method 3: More optimal
# Time: O(n L^2) | Space: O(n L)
# Insert the reverse of every word into a trie, storing the index at the end. While walking a word, if the remaining suffix is a palindrome and the node is an end, you have a pair. Also collect end indexes whose leftover reverse is a palindrome. Same complexity, trie picture.

def palindromePairs(words):
  def isPal(s, a, b):
    while a < b:
      if s[a] != s[b]:
        return False
      a += 1
      b -= 1
    return True
  def node():
    return {"ch": {}, "idx": -1, "palBelow": []}
  root = node()
  for i, w in enumerate(words):
    cur = root
    for j in range(len(w) - 1, -1, -1):
      if isPal(w, 0, j):
        cur["palBelow"].append(i)
      c = w[j]
      if c not in cur["ch"]:
        cur["ch"][c] = node()
      cur = cur["ch"][c]
    cur["idx"] = i
    cur["palBelow"].append(i)
  out = []
  seen = set()
  def add(i, j):
    if i == j or (i, j) in seen:
      return
    seen.add((i, j))
    out.append([i, j])
  for i, w in enumerate(words):
    cur = root
    k = 0
    fell = False
    while k < len(w):
      if cur["idx"] >= 0 and isPal(w, k, len(w) - 1):
        add(i, cur["idx"])
      if w[k] not in cur["ch"]:
        fell = True
        break
      cur = cur["ch"][w[k]]
      k += 1
    if not fell:
      for j in cur["palBelow"]:
        add(i, j)
  return out
