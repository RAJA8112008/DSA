# Method 1: Brute
# Time: O(k! · n · L) | Space: O(k)
# Collect unique letters, try every permutation, test it against consecutive word pairs. Fine for 3 letters, dead at 20. Proves you know the constraints.

def alienOrder(words):
  letters = []
  seen = {}
  for w in words:
    for ch in w:
      if ch not in seen:
        seen[ch]=True; letters.append(ch)
  def valid(order):
    rank = {ch:i for i,ch in enumerate(order)}
    for i in range(len(words)-1):
      a, b = words[i], words[i+1]
      n = min(len(a), len(b))
      diff = False
      for j in range(n):
        if a[j]!=b[j]:
          if rank[a[j]] > rank[b[j]]: return False
          diff=True; break
      if not diff and len(a)>len(b): return False
    return True
  ans = ""
  def dfs(used, path):
    nonlocal ans
    if ans: return
    if len(path)==len(letters):
      s="".join(path)
      if valid(s): ans=s
      return
    for i in range(len(letters)):
      if used[i]: continue
      used[i]=True; path.append(letters[i]); dfs(used, path); path.pop(); used[i]=False
  dfs([False]*len(letters), [])
  return ans


# Method 2: Optimal
# Time: O(n·L + k) | Space: O(k²)
# Build a letter graph from the first mismatch of each consecutive pair. Reject prefix violations. DFS 3-color topo, then reverse the postorder.

def alienOrder(words):
  g = {}
  state = {}
  for w in words:
    for ch in w:
      if ch not in g: g[ch]=set(); state[ch]=0
  for i in range(len(words)-1):
    a, b = words[i], words[i+1]
    n = min(len(a), len(b)); found=False
    for j in range(n):
      if a[j]!=b[j]:
        g[a[j]].add(b[j]); found=True; break
    if not found and len(a)>len(b): return ""
  out=[]; cycle=False
  def dfs(u):
    nonlocal cycle
    if state[u]==1: cycle=True; return
    if state[u]==2: return
    state[u]=1
    for v in list(g[u]): dfs(v)
    state[u]=2; out.append(u)
  for k in list(g.keys()): dfs(k)
  if cycle: return ""
  return "".join(reversed(out))


# Method 3: More optimal
# Time: O(n·L + k) | Space: O(k²)
# Same graph, Kahn's BFS. Letters with indegree 0 come first. If you cannot emit every unique letter, there is a cycle. Iterative and easy to explain.

from collections import deque
def alienOrder(words):
  g = {}; indeg = {}
  for w in words:
    for ch in w:
      if ch not in g: g[ch]=set(); indeg[ch]=0
  for i in range(len(words)-1):
    a, b = words[i], words[i+1]
    n = min(len(a), len(b)); found=False
    for j in range(n):
      if a[j]!=b[j]:
        if b[j] not in g[a[j]]:
          g[a[j]].add(b[j]); indeg[b[j]] += 1
        found=True; break
    if not found and len(a)>len(b): return ""
  q = deque([k for k in indeg if indeg[k]==0])
  order = ""
  while q:
    u = q.popleft(); order += u
    for v in list(g[u]):
      indeg[v]-=1
      if indeg[v]==0: q.append(v)
  return order if len(order)==len(indeg) else ""
