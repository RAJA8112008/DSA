# Method 1: Brute
# Time: O(n L) search | Space: O(n L)
# Keep a list. For each stored word of the same length, compare char by char and treat '.' as a free pass. Simple and slow when the dictionary is large.

class WordDictionary:
  def __init__(self):
    self.words = []
  def addWord(self, word):
    self.words.append(word)
  def search(self, word):
    n = len(word)
    for w in self.words:
      if len(w) != n:
        continue
      ok = True
      for j in range(n):
        if word[j] != "." and word[j] != w[j]:
          ok = False
          break
      if ok:
        return True
    return False


# Method 2: Optimal
# Time: O(k L) | Space: O(n L)
# Bucket words by length so a pattern of length L only scans that bucket. Still linear in the bucket size, but you skip obviously impossible words.

class WordDictionary:
  def __init__(self):
    self.byLen = {}
  def addWord(self, word):
    n = len(word)
    self.byLen.setdefault(n, []).append(word)
  def search(self, word):
    n = len(word)
    for w in self.byLen.get(n, []):
      ok = True
      for j in range(n):
        if word[j] != "." and word[j] != w[j]:
          ok = False
          break
      if ok:
        return True
    return False


# Method 3: More optimal
# Time: O(26^d L) | Space: O(n L)
# Trie DFS. A letter follows one child. A '.' tries every living child. d is the number of dots. This is the expected design.

class Node:
  def __init__(self):
    self.ch = [None] * 26
    self.end = False
class WordDictionary:
  def __init__(self):
    self.root = Node()
  def addWord(self, word):
    cur = self.root
    for c in word:
      idx = ord(c) - 97
      if cur.ch[idx] is None:
        cur.ch[idx] = Node()
      cur = cur.ch[idx]
    cur.end = True
  def search(self, word):
    def dfs(node, i):
      if node is None:
        return False
      if i == len(word):
        return node.end
      c = word[i]
      if c == ".":
        for k in range(26):
          if dfs(node.ch[k], i + 1):
            return True
        return False
      return dfs(node.ch[ord(c) - 97], i + 1)
    return dfs(self.root, 0)
