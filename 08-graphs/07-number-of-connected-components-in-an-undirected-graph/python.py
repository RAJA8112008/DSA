# Method 1: Brute
# Time: O(n·(n + e)) | Space: O(n + e)
# For every unvisited node we DFS with a copied seen array. We still need a global mark so we do not recount. The copies add work without changing the answer.

def countComponents(n, edges):
  g = [[] for _ in range(n)]
  for u, v in edges:
    g[u].append(v); g[v].append(u)
  globalv = [False]*n
  count = 0
  for i in range(n):
    if globalv[i]: continue
    count += 1
    seen = globalv[:]
    stack = [i]; seen[i]=True
    while stack:
      u = stack.pop(); globalv[u]=True
      for v in g[u]:
        if seen[v]: continue
        seen[v]=True; stack.append(v)
  return count


# Method 2: Optimal
# Time: O(n + e) | Space: O(n + e)
# Standard connected-component walk. Each start of a DFS on an unseen node is one component. Linear in nodes and edges.

def countComponents(n, edges):
  g = [[] for _ in range(n)]
  for u, v in edges:
    g[u].append(v); g[v].append(u)
  seen = [False]*n
  def dfs(u):
    seen[u]=True
    for v in g[u]:
      if not seen[v]: dfs(v)
  count=0
  for i in range(n):
    if seen[i]: continue
    count += 1
    dfs(i)
  return count


# Method 3: More optimal
# Time: O(n + e) | Space: O(n)
# Union-Find with no adjacency list. comps starts at n. Each successful union glues two pieces, so comps drops by 1. Path compression keeps finds cheap.

def countComponents(n, edges):
  parent = list(range(n))
  def find(x):
    while parent[x] != x:
      parent[x] = parent[parent[x]]
      x = parent[x]
    return x
  comps = n
  for u, v in edges:
    a, b = find(u), find(v)
    if a == b: continue
    parent[b] = a
    comps -= 1
  return comps
