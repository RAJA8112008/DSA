# Method 1: Brute
# Time: O(n + e) | Space: O(n + e)
# Build the list, then from node 0 DFS with a fresh onPath copy at each step to catch a cycle. Count how many nodes were seen. Extra copies are the brute part; the idea (connected + acyclic) is right.

def validTree(n, edges):
  g = [[] for _ in range(n)]
  for u, v in edges:
    g[u].append(v); g[v].append(u)
  seen = [False] * n
  def dfs(u, parent, onPath):
    if onPath[u]: return False
    copy = onPath[:]
    copy[u] = True
    seen[u] = True
    for v in g[u]:
      if v == parent: continue
      if not dfs(v, u, copy): return False
    return True
  if not dfs(0, -1, [False]*n): return False
  return all(seen)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# A tree must have n-1 edges. Then one BFS/DFS from 0 must reach every node. If it does, there is no extra edge and no missing node, so no cycle.

from collections import deque
def validTree(n, edges):
  if len(edges) != n - 1: return False
  g = [[] for _ in range(n)]
  for u, v in edges:
    g[u].append(v); g[v].append(u)
  seen = [False]*n
  q = deque([0]); seen[0]=True; count=0
  while q:
    u = q.popleft(); count += 1
    for v in g[u]:
      if seen[v]: continue
      seen[v]=True; q.append(v)
  return count == n


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Union-Find. If two ends already share a parent, that edge is a cycle. After n-1 successful unions you have one component. No adjacency list needed.

def validTree(n, edges):
  if len(edges) != n - 1: return False
  parent = list(range(n))
  def find(x):
    while parent[x] != x:
      parent[x] = parent[parent[x]]
      x = parent[x]
    return x
  for u, v in edges:
    a, b = find(u), find(v)
    if a == b: return False
    parent[b] = a
  return True
