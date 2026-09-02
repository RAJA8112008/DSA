# Method 1: Brute
# Time: O(n L) search | Space: O(n L)
# Keep every inserted string in an array. search and startsWith scan the whole list. Correct, and fine for tiny dictionaries, but not the point of the problem.

class Trie:
  def __init__(self):
    self.words = []
  def insert(self, word):
    self.words.append(word)
  def search(self, word):
    for w in self.words:
      if w == word:
        return True
    return False
  def startsWith(self, prefix):
    n = len(prefix)
    for w in self.words:
      if len(w) >= n and w[:n] == prefix:
        return True
    return False


# Method 2: Optimal
# Time: O(L) | Space: O(n L)
# A set of full words plus a set of every prefix. Each call is a hash lookup. Extra memory stores every prefix string, which a trie shares instead.

class Trie:
  def __init__(self):
    self.words = set()
    self.prefs = set()
  def insert(self, word):
    self.words.add(word)
    p = ""
    for ch in word:
      p += ch
      self.prefs.add(p)
  def search(self, word):
    return word in self.words
  def startsWith(self, prefix):
    return prefix in self.prefs


# Method 3: More optimal
# Time: O(L) | Space: O(n L) shared
# Real trie. Shared prefixes share nodes. insert, search, and startsWith each walk L children. This is the expected interview finish.

class Node:
  def __init__(self):
    self.ch = [None] * 26
    self.end = False
class Trie:
  def __init__(self):
    self.root = Node()
  def insert(self, word):
    cur = self.root
    for ch in word:
      idx = ord(ch) - 97
      if cur.ch[idx] is None:
        cur.ch[idx] = Node()
      cur = cur.ch[idx]
    cur.end = True
  def search(self, word):
    cur = self.root
    for ch in word:
      idx = ord(ch) - 97
      if cur.ch[idx] is None:
        return False
      cur = cur.ch[idx]
    return cur.end
  def startsWith(self, prefix):
    cur = self.root
    for ch in prefix:
      idx = ord(ch) - 97
      if cur.ch[idx] is None:
        return False
      cur = cur.ch[idx]
    return True
