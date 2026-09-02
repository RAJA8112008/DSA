# Method 1: Brute
# Time: O(n L) sum | Space: O(n L)
# A plain key -> val map. sum walks every key and adds val when the key starts with the prefix.

class MapSum:
  def __init__(self):
    self.map = {}
  def insert(self, key, val):
    self.map[key] = val
  def sum(self, prefix):
    s = 0
    n = len(prefix)
    for k, v in self.map.items():
      if len(k) >= n and k[:n] == prefix:
        s += v
    return s


# Method 2: Optimal
# Time: O(L) insert and sum | Space: O(n L)
# Keep the latest val per key. On insert, delta = newVal - oldVal. Add delta to every prefix string of the key in a second map. sum is then one lookup.

class MapSum:
  def __init__(self):
    self.val = {}
    self.pref = {}
  def insert(self, key, v):
    old = self.val.get(key, 0)
    delta = v - old
    self.val[key] = v
    p = ""
    for ch in key:
      p += ch
      self.pref[p] = self.pref.get(p, 0) + delta
  def sum(self, prefix):
    return self.pref.get(prefix, 0)


# Method 3: More optimal
# Time: O(L) | Space: O(n L) shared
# Trie node holds a running sum of values that pass through it. insert adds the delta along the path. sum walks the prefix and returns that node's sum.

class Node:
  def __init__(self):
    self.ch = [None] * 26
    self.sum = 0
class MapSum:
  def __init__(self):
    self.root = Node()
    self.val = {}
  def insert(self, key, v):
    delta = v - self.val.get(key, 0)
    self.val[key] = v
    cur = self.root
    for c in key:
      idx = ord(c) - 97
      if cur.ch[idx] is None:
        cur.ch[idx] = Node()
      cur = cur.ch[idx]
      cur.sum += delta
  def sum(self, prefix):
    cur = self.root
    for c in prefix:
      idx = ord(c) - 97
      if cur.ch[idx] is None:
        return 0
      cur = cur.ch[idx]
    return cur.sum
