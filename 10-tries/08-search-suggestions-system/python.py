# Method 1: Brute
# Time: O(|s| n L) | Space: O(n)
# After each extra character, scan every product, keep those with the prefix, sort, take 3. Correct and slow.

def suggestedProducts(products, searchWord):
  out = []
  pref = ""
  for ch in searchWord:
    pref += ch
    hit = [p for p in products if len(p) >= len(pref) and p[:len(pref)] == pref]
    hit.sort()
    out.append(hit[:3])
  return out


# Method 2: Optimal
# Time: O(n L log n + |s| log n) | Space: O(n)
# Sort products once. For each growing prefix, lower-bound the first product >= prefix, then take the next three if they still share the prefix.

import bisect
def suggestedProducts(products, searchWord):
  a = sorted(products)
  out = []
  pref = ""
  for ch in searchWord:
    pref += ch
    k = bisect.bisect_left(a, pref)
    row = []
    t = 0
    while t < 3 and k + t < len(a):
      p = a[k + t]
      if len(p) >= len(pref) and p[:len(pref)] == pref:
        row.append(p)
      t += 1
    out.append(row)
  return out


# Method 3: More optimal
# Time: O(total chars) | Space: O(total chars)
# Trie. At each node keep up to 3 lex-smallest words that pass through it (insert into a sorted short list). Typing searchWord is just walking children and reading that list.

def suggestedProducts(products, searchWord):
  def node():
    return {"ch": [None] * 26, "sug": []}
  def addSug(lst, w):
    lst.append(w)
    lst.sort()
    if len(lst) > 3:
      lst.pop()
  root = node()
  for w in products:
    cur = root
    for ch in w:
      idx = ord(ch) - 97
      if cur["ch"][idx] is None:
        cur["ch"][idx] = node()
      cur = cur["ch"][idx]
      addSug(cur["sug"], w)
  out = []
  cur = root
  for ch in searchWord:
    if cur is not None:
      cur = cur["ch"][ord(ch) - 97]
    out.append(list(cur["sug"]) if cur is not None else [])
  return out
