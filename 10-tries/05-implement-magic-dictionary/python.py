# Method 1: Brute
# Time: O(n L) | Space: O(n L)
# Store the list. For each stored word of the same length, count mismatches. Return true on a count of exactly 1.

class MagicDictionary:
  def __init__(self):
    self.words = []
  def buildDict(self, dictionary):
    self.words = list(dictionary)
  def search(self, searchWord):
    n = len(searchWord)
    for w in self.words:
      if len(w) != n:
        continue
      diff = 0
      for j in range(n):
        if w[j] != searchWord[j]:
          diff += 1
      if diff == 1:
        return True
    return False


# Method 2: Optimal
# Time: O(L * 26) | Space: O(n L^2)
# For each word, replace each position with '*' and map that pattern to the original letters. On search, look up each starred query and see if another letter is stored. Handles duplicates carefully.

class MagicDictionary:
  def __init__(self):
    self.map = {}
  def buildDict(self, dictionary):
    self.map = {}
    for w in dictionary:
      for j in range(len(w)):
        key = w[:j] + "*" + w[j + 1:]
        self.map.setdefault(key, []).append(w[j])
  def search(self, searchWord):
    for j in range(len(searchWord)):
      key = searchWord[:j] + "*" + searchWord[j + 1:]
      for letter in self.map.get(key, []):
        if letter != searchWord[j]:
          return True
    return False


# Method 3: More optimal
# Time: O(26 L) | Space: O(n L)
# Trie DFS with a leftover mismatch budget of 1. At the end of the query the budget must be 0 (exactly one change). Compact and matches the 'magic' story.

class Node:
  def __init__(self):
    self.ch = [None] * 26
    self.end = False
class MagicDictionary:
  def __init__(self):
    self.root = Node()
  def buildDict(self, dictionary):
    self.root = Node()
    for w in dictionary:
      cur = self.root
      for c in w:
        idx = ord(c) - 97
        if cur.ch[idx] is None:
          cur.ch[idx] = Node()
        cur = cur.ch[idx]
      cur.end = True
  def search(self, searchWord):
    def dfs(node, i, left):
      if node is None:
        return False
      if i == len(searchWord):
        return node.end and left == 0
      idx = ord(searchWord[i]) - 97
      for k in range(26):
        cost = 0 if k == idx else 1
        if left - cost < 0:
          continue
        if dfs(node.ch[k], i + 1, left - cost):
          return True
      return False
    return dfs(self.root, 0, 1)
