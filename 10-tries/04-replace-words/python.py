# Method 1: Brute
# Time: O(words * roots * L) | Space: O(1) extra
# For each sentence word, scan every root and keep the shortest one that is a prefix. Easy to write, quadratic in dictionary size.

def replaceWords(dictionary, sentence):
  words = sentence.split(" ")
  for i, w in enumerate(words):
    best = w
    for r in dictionary:
      if len(w) >= len(r) and w[:len(r)] == r and len(r) < len(best):
        best = r
    words[i] = best
  return " ".join(words)


# Method 2: Optimal
# Time: O(total chars) | Space: O(roots)
# Put roots in a set. For each word, try prefixes from length 1 up and take the first hit. That is the shortest root. Faster when few prefixes match.

def replaceWords(dictionary, sentence):
  s = set(dictionary)
  words = sentence.split(" ")
  for i, w in enumerate(words):
    for L in range(1, len(w) + 1):
      p = w[:L]
      if p in s:
        words[i] = p
        break
  return " ".join(words)


# Method 3: More optimal
# Time: O(total chars) | Space: O(roots)
# Trie of roots. Walk each sentence word until you hit an end flag, then stop. Shared prefixes make this the usual interview answer.

def replaceWords(dictionary, sentence):
  def node():
    return {"ch": [None] * 26, "end": False}
  root = node()
  for r in dictionary:
    cur = root
    for ch in r:
      idx = ord(ch) - 97
      if cur["ch"][idx] is None:
        cur["ch"][idx] = node()
      cur = cur["ch"][idx]
    cur["end"] = True
  words = sentence.split(" ")
  for i, w in enumerate(words):
    cur = root
    built = ""
    for ch in w:
      idx = ord(ch) - 97
      if cur["ch"][idx] is None:
        break
      cur = cur["ch"][idx]
      built += ch
      if cur["end"]:
        words[i] = built
        break
  return " ".join(words)
