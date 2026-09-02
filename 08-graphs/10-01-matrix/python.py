# Method 1: Brute
# Time: O(r²c²) | Space: O(rc)
# For each 1, BFS with a fresh visited matrix until you hit a 0. You re-walk the same cells from many starts.

from collections import deque
def updateMatrix(mat):
  rows, cols = len(mat), len(mat[0])
  out = [[0]*cols for _ in range(rows)]
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  def dist(sr, sc):
    seen = [[False]*cols for _ in range(rows)]
    q = deque([(sr, sc, 0)])
    seen[sr][sc] = True
    while q:
      r,c,d = q.popleft()
      if mat[r][c]==0: return d
      for i in range(4):
        nr, nc = r+dirs[i][0], c+dirs[i][1]
        if nr<0 or nc<0 or nr>=rows or nc>=cols or seen[nr][nc]: continue
        seen[nr][nc]=True
        q.append((nr,nc,d+1))
    return 0
  for r in range(rows):
    for c in range(cols):
      if mat[r][c] != 0: out[r][c] = dist(r,c)
  return out


# Method 2: Optimal
# Time: O(rc) | Space: O(rc)
# Multi-source BFS from all zeros. Each 1 is reached first by its nearest 0. One visit per cell.

from collections import deque
def updateMatrix(mat):
  rows, cols = len(mat), len(mat[0])
  inf = rows * cols
  dist = [[inf]*cols for _ in range(rows)]
  q = deque()
  for r in range(rows):
    for c in range(cols):
      if mat[r][c]==0:
        dist[r][c]=0; q.append((r,c))
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  while q:
    r,c = q.popleft()
    for i in range(4):
      nr, nc = r+dirs[i][0], c+dirs[i][1]
      if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
      if dist[nr][nc] <= dist[r][c]+1: continue
      dist[nr][nc] = dist[r][c]+1
      q.append((nr,nc))
  return dist


# Method 3: More optimal
# Time: O(rc) | Space: O(1)
# Two DP sweeps. First pass uses top and left (already processed). Second pass uses bottom and right. You can write into the output matrix only; extra space is O(1) besides the answer. Same linear time, no queue.

def updateMatrix(mat):
  rows, cols = len(mat), len(mat[0])
  inf = rows + cols
  dist = [[0 if v==0 else inf for v in row] for r,row in enumerate(mat)]
  for r in range(rows):
    for c in range(cols):
      if r>0: dist[r][c] = min(dist[r][c], dist[r-1][c]+1)
      if c>0: dist[r][c] = min(dist[r][c], dist[r][c-1]+1)
  for r in range(rows-1, -1, -1):
    for c in range(cols-1, -1, -1):
      if r+1<rows: dist[r][c] = min(dist[r][c], dist[r+1][c]+1)
      if c+1<cols: dist[r][c] = min(dist[r][c], dist[r][c+1]+1)
  return dist
