# Method 1: Brute
# Time: O(n^K) | Space: O(n + e)
# DFS every path with a copied visiting array and a remaining-stop budget. Exponential in K. Easy to write, too slow when K is 20 and the graph is dense.

def findCheapestPrice(n, flights, src, dst, k):
  g = [[] for _ in range(n)]
  for u,v,w in flights:
    g[u].append((v,w))
  best = float("inf")
  def dfs(u, cost, stops, visiting):
    nonlocal best
    if cost >= best: return
    if u == dst: best = cost; return
    if stops < 0: return
    copy = visiting[:]
    copy[u] = True
    for v,w in g[u]:
      if copy[v]: continue
      dfs(v, cost+w, stops-1, copy)
  dfs(src, 0, k, [False]*n)
  return -1 if best==float("inf") else best


# Method 2: Optimal
# Time: O(K · e) | Space: O(n)
# Bellman-Ford: relax every flight K+1 times. Copy dist each round so you only use paths with one more flight. Classic for 'at most K edges'.

def findCheapestPrice(n, flights, src, dst, k):
  dist = [float("inf")]*n
  dist[src]=0
  for round in range(k+1):
    nxt = dist[:]
    for u,v,w in flights:
      if dist[u]==float("inf"): continue
      if dist[u]+w < nxt[v]: nxt[v]=dist[u]+w
    dist = nxt
  return -1 if dist[dst]==float("inf") else dist[dst]


# Method 3: More optimal
# Time: O(K · e log (K n)) | Space: O(n · K + e)
# Dijkstra on state (city, stops used). A min-heap pops cheapest cost first. best[city][stops] prunes worse repeats. Faster on sparse graphs when K is small.

def findCheapestPrice(n, flights, src, dst, k):
  g = [[] for _ in range(n)]
  for u,v,w in flights:
    g[u].append((v,w))
  best = [[float("inf")]*(k+2) for _ in range(n)]
  heap=[]
  def push(x):
    heap.append(x); i=len(heap)-1
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
  best[src][0]=0; push((0,src,0))
  while heap:
    cost,u,used=pop()
    if u==dst: return cost
    if used>k: continue
    for v,w in g[u]:
      nc=cost+w
      if nc>=best[v][used+1]: continue
      best[v][used+1]=nc; push((nc,v,used+1))
  return -1
