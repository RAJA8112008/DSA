# Method 1: Brute
# Time: O(8^{n²}) | Space: O(n²)
# DFS every simple path with a copied visited matrix. Keep the shortest length. Correct on a 2x2, exponential on a 20x20.

def shortestPathBinaryMatrix(grid):
  n=len(grid)
  if grid[0][0] or grid[n-1][n-1]: return -1
  best=float("inf")
  dirs=[]
  for dr in range(-1,2):
    for dc in range(-1,2):
      if dr or dc: dirs.append([dr,dc])
  def dfs(r,c,dist,seen):
    nonlocal best
    if dist>=best: return
    if r==n-1 and c==n-1: best=dist; return
    for i in range(len(dirs)):
      nr,nc=r+dirs[i][0], c+dirs[i][1]
      if nr<0 or nc<0 or nr>=n or nc>=n: continue
      if grid[nr][nc]!=0 or seen[nr][nc]: continue
      copy=[row[:] for row in seen]
      copy[nr][nc]=True
      dfs(nr,nc,dist+1,copy)
  seen=[[False]*n for _ in range(n)]; seen[0][0]=True
  dfs(0,0,1,seen)
  return -1 if best==float("inf") else best


# Method 2: Optimal
# Time: O(n²) | Space: O(n²)
# BFS from (0,0). First time you pop the end cell is the shortest length. Mark cells when you push so the queue stays small. 8 neighbors.

from collections import deque
def shortestPathBinaryMatrix(grid):
  n=len(grid)
  if grid[0][0] or grid[n-1][n-1]: return -1
  q=deque([(0,0,1)])
  grid[0][0]=1
  dirs=[]
  for dr in range(-1,2):
    for dc in range(-1,2):
      if dr or dc: dirs.append([dr,dc])
  while q:
    r,c,d=q.popleft()
    if r==n-1 and c==n-1: return d
    for i in range(len(dirs)):
      nr,nc=r+dirs[i][0], c+dirs[i][1]
      if nr<0 or nc<0 or nr>=n or nc>=n: continue
      if grid[nr][nc]!=0: continue
      grid[nr][nc]=1; q.append((nr,nc,d+1))
  return -1


# Method 3: More optimal
# Time: O(n²) | Space: O(n²)
# Bidirectional BFS from start and end. When a neighbor sits in the other frontier, the two searches met. Fewer cells expanded on large open maps. Same worst-case O(n²).

from collections import deque
def shortestPathBinaryMatrix(grid):
  n=len(grid)
  if grid[0][0] or grid[n-1][n-1]: return -1
  if n==1: return 1
  dirs=[]
  for dr in range(-1,2):
    for dc in range(-1,2):
      if dr or dc: dirs.append([dr,dc])
  def key(r,c): return r*n+c
  q1=[(0,0)]; q2=[(n-1,n-1)]
  d1={key(0,0):1}; d2={key(n-1,n-1):1}
  while q1 and q2:
    if len(q1)>len(q2): q1,q2=q2,q1; d1,d2=d2,d1
    nxt=[]
    for r,c in q1:
      id_=key(r,c)
      for dr,dc in dirs:
        nr,nc=r+dr,c+dc
        if nr<0 or nc<0 or nr>=n or nc>=n: continue
        if grid[nr][nc]!=0: continue
        nid=key(nr,nc)
        if nid in d1: continue
        if nid in d2: return d1[id_]+d2[nid]
        d1[nid]=d1[id_]+1; nxt.append((nr,nc))
    q1=nxt
  return -1
