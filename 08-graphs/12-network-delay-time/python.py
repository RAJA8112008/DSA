# Method 1: Brute
# Time: O(n^e) | Space: O(n + e)
# DFS every simple path, copying the visiting array so cycles stop. Keep the best arrival time per node. Exponential on dense graphs.

def networkDelayTime(times, n, k):
  g = [[] for _ in range(n+1)]
  for u,v,w in times:
    g[u].append((v,w))
  dist = [float("inf")]*(n+1)
  def dfs(u, d, visiting):
    if d >= dist[u]: return
    dist[u] = d
    copy = visiting[:]
    copy[u] = True
    for v,w in g[u]:
      if copy[v]: continue
      dfs(v, d+w, copy)
  dfs(k, 0, [False]*(n+1))
  ans = 0
  for i in range(1, n+1): ans = max(ans, dist[i])
  return -1 if ans==float("inf") else ans


# Method 2: Optimal
# Time: O(n² + e) | Space: O(n + e)
# Dijkstra without a heap: each round scan all nodes for the unvisited one with smallest dist. Fine when n is a few hundred. Classic O(n²) Dijkstra.

def networkDelayTime(times, n, k):
  g = [[] for _ in range(n+1)]
  for u,v,w in times:
    g[u].append((v,w))
  dist = [float("inf")]*(n+1)
  used = [False]*(n+1)
  dist[k]=0
  for round in range(n):
    u = -1
    for i in range(1, n+1):
      if used[i]: continue
      if u==-1 or dist[i]<dist[u]: u=i
    if u==-1 or dist[u]==float("inf"): break
    used[u]=True
    for v,w in g[u]:
      if dist[u]+w < dist[v]: dist[v]=dist[u]+w
  ans=0
  for i in range(1,n+1): ans=max(ans, dist[i])
  return -1 if ans==float("inf") else ans


# Method 3: More optimal
# Time: O((n + e) log n) | Space: O(n + e)
# Dijkstra with a binary min-heap of [distance, node]. Skip stale pops. This is the usual interview solution for sparse graphs.

def networkDelayTime(times, n, k):
  g = [[] for _ in range(n+1)]
  for u,v,w in times:
    g[u].append((v,w))
  dist = [float("inf")]*(n+1)
  dist[k]=0
  heap=[]
  def push(item):
    heap.append(item)
    i=len(heap)-1
    while i>0:
      p=(i-1)>>1
      if heap[i][0]>=heap[p][0]: break
      heap[i],heap[p]=heap[p],heap[i]; i=p
  def pop():
    top=heap[0]; last=heap.pop()
    if not heap: return top
    heap[0]=last; i=0
    while True:
      s=i; l=i*2+1; r=l+1
      if l<len(heap) and heap[l][0]<heap[s][0]: s=l
      if r<len(heap) and heap[r][0]<heap[s][0]: s=r
      if s==i: break
      heap[i],heap[s]=heap[s],heap[i]; i=s
    return top
  push((0,k))
  while heap:
    d,u=pop()
    if d>dist[u]: continue
    for v,w in g[u]:
      if d+w < dist[v]:
        dist[v]=d+w; push((dist[v], v))
  ans=0
  for i in range(1,n+1): ans=max(ans, dist[i])
  return -1 if ans==float("inf") else ans
