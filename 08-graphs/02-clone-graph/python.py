# Method 1: Brute
# Time: O(n + e) | Space: O(n)
# One shared old-to-new map is required so a node is cloned once. The extra Set copy on every call is wasted; it does not change correctness. Drop the copies and you get Optimal.

class Node:
  def __init__(self, val=0, neighbors=None):
    self.val = val
    self.neighbors = neighbors if neighbors is not None else []
def cloneGraph(node):
  if not node: return None
  mp = {}
  def dfs(cur, seen_copy):
    if cur in mp: return mp[cur]
    copy = Node(cur.val, [])
    mp[cur] = copy
    next_seen = set(seen_copy)
    next_seen.add(cur)
    for nei in cur.neighbors:
      copy.neighbors.append(dfs(nei, next_seen))
    return copy
  return dfs(node, set())


# Method 2: Optimal
# Time: O(n + e) | Space: O(n)
# One Map from old node to new node. DFS creates the clone, then fills neighbors. Each node and edge is processed once.

class Node:
  def __init__(self, val=0, neighbors=None):
    self.val = val
    self.neighbors = neighbors if neighbors is not None else []
def cloneGraph(node):
  if not node: return None
  mp = {}
  def dfs(cur):
    if cur in mp: return mp[cur]
    copy = Node(cur.val, [])
    mp[cur] = copy
    for nei in cur.neighbors:
      copy.neighbors.append(dfs(nei))
    return copy
  return dfs(node)


# Method 3: More optimal
# Time: O(n + e) | Space: O(n)
# BFS with the same map avoids deep recursion on a long chain. Complexity matches DFS. Prefer this when the graph can be a long path.

from collections import deque
class Node:
  def __init__(self, val=0, neighbors=None):
    self.val = val
    self.neighbors = neighbors if neighbors is not None else []
def cloneGraph(node):
  if not node: return None
  mp = {node: Node(node.val, [])}
  q = deque([node])
  while q:
    cur = q.popleft()
    copy = mp[cur]
    for nei in cur.neighbors:
      if nei not in mp:
        mp[nei] = Node(nei.val, [])
        q.append(nei)
      copy.neighbors.append(mp[nei])
  return mp[node]
