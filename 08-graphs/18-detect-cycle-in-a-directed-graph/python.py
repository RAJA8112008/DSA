# Method 1: Brute
# Time: O(n·(n + e)) | Space: O(n + e)
# From each start, DFS with a copied onPath array. You repeat walks that 3-color would cache as 'finished'. Extra copies are the brute cost.

def hasCycle(n, edges):
  g = [[] for _ in range(n)]
  for u,v in edges:
    g[u].append(v)
  def dfs(u, onPath):
    if onPath[u]: return True
    copy = onPath[:]
    copy[u] = True
    for v in g[u]:
      if dfs(v, copy): return True
    return False
  for i in range(n):
    if dfs(i, [False]*n): return True
  return False


# Method 2: Optimal
# Time: O(n + e) | Space: O(n + e)
# Colors 0/1/2. A neighbor that is still 1 is a back edge, so a cycle. Nodes marked 2 are skipped. Each edge once.

def hasCycle(n, edges):
  g = [[] for _ in range(n)]
  for u,v in edges:
    g[u].append(v)
  state = [0]*n
  def dfs(u):
    if state[u]==1: return True
    if state[u]==2: return False
    state[u]=1
    for v in g[u]:
      if dfs(v): return True
    state[u]=2
    return False
  for i in range(n):
    if state[i]==0 and dfs(i): return True
  return False


# Method 3: More optimal
# Time: O(n + e) | Space: O(n + e)
# Kahn's algorithm. Peel indegree 0. If the number of peeled nodes is less than n, leftover nodes sit in a cycle. Iterative, same linear time.

from collections import deque
def hasCycle(n, edges):
  g = [[] for _ in range(n)]
  indeg = [0]*n
  for u,v in edges:
    g[u].append(v); indeg[v]+=1
  q = deque([i for i in range(n) if indeg[i]==0])
  peeled=0
  while q:
    u=q.popleft(); peeled+=1
    for v in g[u]:
      indeg[v]-=1
      if indeg[v]==0: q.append(v)
  return peeled != n
