# Method 1: Brute
# Time: O(n L) | Space: O(n L)
# An array of words. equalTo counts exact matches. startingWith counts prefix matches. erase removes the first copy.

class Trie:
  def __init__(self):
    self.words = []
  def insert(self, word):
    self.words.append(word)
  def countWordsEqualTo(self, word):
    return sum(1 for w in self.words if w == word)
  def countWordsStartingWith(self, prefix):
    n = len(prefix)
    return sum(1 for w in self.words if len(w) >= n and w[:n] == prefix)
  def erase(self, word):
    if word in self.words:
      self.words.remove(word)


# Method 2: Optimal
# Time: O(L) | Space: O(n L)
# wordCount map and prefixCount map. insert / erase add or subtract 1 along every prefix. Queries are hash lookups. Watch erase: never go below zero.

class Trie:
  def __init__(self):
    self.wordCount = {}
    self.prefCount = {}
  def insert(self, word):
    self.wordCount[word] = self.wordCount.get(word, 0) + 1
    p = ""
    for ch in word:
      p += ch
      self.prefCount[p] = self.prefCount.get(p, 0) + 1
  def countWordsEqualTo(self, word):
    return self.wordCount.get(word, 0)
  def countWordsStartingWith(self, prefix):
    return self.prefCount.get(prefix, 0)
  def erase(self, word):
    if not self.wordCount.get(word, 0):
      return
    self.wordCount[word] -= 1
    p = ""
    for ch in word:
      p += ch
      self.prefCount[p] -= 1


# Method 3: More optimal
# Time: O(L) | Space: O(total chars) shared
# Trie node has words (how many end here) and pref (how many pass through). insert increments. erase decrements and unlinks a child whose pref hits 0.

class Node:
  def __init__(self):
    self.ch = [None] * 26
    self.words = 0
    self.pref = 0
class Trie:
  def __init__(self):
    self.root = Node()
  def insert(self, word):
    cur = self.root
    for c in word:
      idx = ord(c) - 97
      if cur.ch[idx] is None:
        cur.ch[idx] = Node()
      cur = cur.ch[idx]
      cur.pref += 1
    cur.words += 1
  def countWordsEqualTo(self, word):
    cur = self.root
    for c in word:
      idx = ord(c) - 97
      if cur.ch[idx] is None:
        return 0
      cur = cur.ch[idx]
    return cur.words
  def countWordsStartingWith(self, prefix):
    cur = self.root
    for c in prefix:
      idx = ord(c) - 97
      if cur.ch[idx] is None:
        return 0
      cur = cur.ch[idx]
    return cur.pref
  def erase(self, word):
    if self.countWordsEqualTo(word) == 0:
      return
    cur = self.root
    for c in word:
      idx = ord(c) - 97
      nxt = cur.ch[idx]
      nxt.pref -= 1
      if nxt.pref == 0:
        cur.ch[idx] = None
        return
      cur = nxt
    cur.words -= 1
