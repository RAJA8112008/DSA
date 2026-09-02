# Method 1: Brute
# Time: O(n·(n + e)) | Space: O(n + e)
# From every course we DFS with a brand-new onPath array. We redo walks that a single 3-color pass would cache. Fine on tiny n, wasteful on large n.

def canFinish(numCourses, prerequisites):
  g = [[] for _ in range(numCourses)]
  for a, b in prerequisites:
    g[b].append(a)
  def dfs(u, onPath):
    if onPath[u]: return False
    copy = onPath[:]
    copy[u] = True
    for v in g[u]:
      if not dfs(v, copy): return False
    return True
  for i in range(numCourses):
    if not dfs(i, [False] * numCourses): return False
  return True


# Method 2: Optimal
# Time: O(n + e) | Space: O(n + e)
# Three colors: 0 unseen, 1 on the current path, 2 done. Hitting a 1 is a cycle. Finished nodes are skipped, so each edge is walked once.

def canFinish(numCourses, prerequisites):
  g = [[] for _ in range(numCourses)]
  for a, b in prerequisites:
    g[b].append(a)
  state = [0] * numCourses
  def dfs(u):
    if state[u] == 1: return False
    if state[u] == 2: return True
    state[u] = 1
    for v in g[u]:
      if not dfs(v): return False
    state[u] = 2
    return True
  for i in range(numCourses):
    if not dfs(i): return False
  return True


# Method 3: More optimal
# Time: O(n + e) | Space: O(n + e)
# Kahn's algorithm: peel indegree-0 courses. If you cannot peel all n courses, a cycle remains. Iterative, no recursion, same linear bound.

from collections import deque
def canFinish(numCourses, prerequisites):
  g = [[] for _ in range(numCourses)]
  indeg = [0] * numCourses
  for a, b in prerequisites:
    g[b].append(a)
    indeg[a] += 1
  q = deque([i for i in range(numCourses) if indeg[i] == 0])
  taken = 0
  while q:
    u = q.popleft()
    taken += 1
    for v in g[u]:
      indeg[v] -= 1
      if indeg[v] == 0: q.append(v)
  return taken == numCourses
