# Method 1: Brute
# Time: O((rc)²) | Space: O(rc)
# Each minute, copy the grid and rot any fresh cell that touches a 2. Repeat until nothing changes. You scan the whole grid once per minute, up to rc minutes.

def orangesRotting(grid):
  rows, cols = len(grid), len(grid[0])
  def countFresh(g):
    n = 0
    for r in range(rows):
      for c in range(cols):
        if g[r][c] == 1: n += 1
    return n
  minutes = 0
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  while True:
    nxt = [row[:] for row in grid]
    changed = False
    for r in range(rows):
      for c in range(cols):
        if grid[r][c] != 2: continue
        for i in range(4):
          nr, nc = r+dirs[i][0], c+dirs[i][1]
          if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
          if grid[nr][nc] != 1: continue
          nxt[nr][nc] = 2
          changed = True
    if not changed: break
    grid = nxt
    minutes += 1
  return -1 if countFresh(grid) else minutes


# Method 2: Optimal
# Time: O(rc) | Space: O(rc)
# Put every rotten orange in the queue at minute 0. BFS infects fresh neighbors. The last minute you used is the answer. If any 1 remains, return -1.

from collections import deque
def orangesRotting(grid):
  rows, cols = len(grid), len(grid[0])
  q = deque()
  fresh = 0
  for r in range(rows):
    for c in range(cols):
      if grid[r][c]==2: q.append((r,c,0))
      if grid[r][c]==1: fresh += 1
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  minutes = 0
  while q:
    r,c,t = q.popleft()
    minutes = t
    for i in range(4):
      nr, nc = r+dirs[i][0], c+dirs[i][1]
      if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
      if grid[nr][nc]!=1: continue
      grid[nr][nc]=2; fresh -= 1
      q.append((nr,nc,t+1))
  return minutes if fresh==0 else -1


# Method 3: More optimal
# Time: O(rc) | Space: O(rc)
# Same multi-source BFS, but the grid itself stores time as 2 + minutes. No third tuple field. Space is still the queue. Linear in cells.

from collections import deque
def orangesRotting(grid):
  rows, cols = len(grid), len(grid[0])
  q = deque()
  fresh = 0
  for r in range(rows):
    for c in range(cols):
      if grid[r][c]==2: q.append((r,c))
      elif grid[r][c]==1: fresh += 1
  if fresh==0: return 0
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  minutes = 0
  while q:
    size = len(q)
    infected = False
    for s in range(size):
      r,c = q.popleft()
      for i in range(4):
        nr, nc = r+dirs[i][0], c+dirs[i][1]
        if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
        if grid[nr][nc]!=1: continue
        grid[nr][nc]=2; fresh -= 1; infected=True
        q.append((nr,nc))
    if infected: minutes += 1
  return minutes if fresh==0 else -1
