# Method 1: Brute
# Time: O(n^2 L) | Space: O(n)
# Put words in a set. For each word, test that every prefix is in the set. Keep the longest, breaking ties lexicographically.

def longestWord(words):
  s = set(words)
  best = ""
  for w in words:
    ok = True
    for L in range(1, len(w)):
      if w[:L] not in s:
        ok = False
        break
    if not ok:
      continue
    if len(w) > len(best) or (len(w) == len(best) and w < best):
      best = w
  return best


# Method 2: Optimal
# Time: O(n L log n) | Space: O(n)
# Sort by length then lex. A word is valid if the set already holds word without its last letter (or the word has length 1). Insert only valid words. The last survivor is the answer if you also keep the lex-smallest of that length.

def longestWord(words):
  words = sorted(words, key=lambda w: (len(w), w))
  good = set([""])
  best = ""
  for w in words:
    if w[:-1] in good:
      good.add(w)
      if len(w) > len(best):
        best = w
  return best


# Method 3: More optimal
# Time: O(total chars) | Space: O(total chars)
# Insert every word into a trie with an end flag. DFS only through end nodes. The deepest (then lex-smallest) path is the answer.

def longestWord(words):
  def node():
    return {"ch": [None] * 26, "end": False}
  root = node()
  root["end"] = True
  for w in words:
    cur = root
    for ch in w:
      idx = ord(ch) - 97
      if cur["ch"][idx] is None:
        cur["ch"][idx] = node()
      cur = cur["ch"][idx]
    cur["end"] = True
  best = [""]
  def dfs(cur, path):
    if not cur["end"]:
      return
    if len(path) > len(best[0]) or (len(path) == len(best[0]) and path < best[0]):
      best[0] = path
    for i in range(26):
      if cur["ch"][i] is None:
        continue
      dfs(cur["ch"][i], path + chr(97 + i))
  dfs(root, "")
  return best[0]
