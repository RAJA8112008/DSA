# Method 1: Brute
# Time: O(n! · e) | Space: O(n)
# Generate every permutation of courses and test the prereq edges. Correct for tiny n, unusable at interview sizes. Shows you know 'order' means a permutation that respects edges.

def findOrder(numCourses, prerequisites):
  edges = prerequisites
  def ok(order):
    pos = [0] * numCourses
    for i, x in enumerate(order): pos[x] = i
    for a, b in edges:
      if pos[b] > pos[a]: return False
    return True
  used = [False] * numCourses
  path = []
  ans = None
  def dfs():
    nonlocal ans
    if ans is not None: return
    if len(path) == numCourses:
      if ok(path): ans = path[:]
      return
    for i in range(numCourses):
      if used[i]: continue
      used[i] = True
      path.append(i)
      dfs()
      path.pop()
      used[i] = False
  dfs()
  return ans or []


# Method 2: Optimal
# Time: O(n + e) | Space: O(n + e)
# DFS 3-color. After all outgoing edges are done, push the course. Reverse of that list is a topo order. Empty array if a cycle is found.

def findOrder(numCourses, prerequisites):
  g = [[] for _ in range(numCourses)]
  for a, b in prerequisites:
    g[b].append(a)
  state = [0] * numCourses
  out = []
  cycle = False
  def dfs(u):
    nonlocal cycle
    if state[u] == 1: cycle = True; return
    if state[u] == 2: return
    state[u] = 1
    for v in g[u]: dfs(v)
    state[u] = 2
    out.append(u)
  for i in range(numCourses): dfs(i)
  if cycle: return []
  out.reverse()
  return out


# Method 3: More optimal
# Time: O(n + e) | Space: O(n + e)
# Kahn's BFS builds the order directly: indegree 0 first. If the order is shorter than n, a cycle blocked some courses. No reverse step, no recursion.

from collections import deque
def findOrder(numCourses, prerequisites):
  g = [[] for _ in range(numCourses)]
  indeg = [0] * numCourses
  for a, b in prerequisites:
    g[b].append(a); indeg[a] += 1
  q = deque([i for i in range(numCourses) if indeg[i] == 0])
  order = []
  while q:
    u = q.popleft(); order.append(u)
    for v in g[u]:
      indeg[v] -= 1
      if indeg[v] == 0: q.append(v)
  return order if len(order) == numCourses else []
