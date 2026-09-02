# Method 1: Brute
# Time: O(r²c²) | Space: O(rc)
# From every cell, DFS toward lower/equal neighbors with a fresh visited copy. Check if that walk hits a Pacific border and an Atlantic border. Extra copies plus a full search per cell.

def pacificAtlantic(heights):
  rows, cols = len(heights), len(heights[0])
  ans = []
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  def reaches(sr, sc):
    seen = [[False]*cols for _ in range(rows)]
    stack = [[sr, sc]]
    seen[sr][sc] = True
    pac = atl = False
    while stack:
      r, c = stack.pop()
      if r == 0 or c == 0: pac = True
      if r == rows-1 or c == cols-1: atl = True
      if pac and atl: return True
      for i in range(4):
        nr, nc = r+dirs[i][0], c+dirs[i][1]
        if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
        if seen[nr][nc] or heights[nr][nc] > heights[r][c]: continue
        seen[nr][nc] = True
        stack.append([nr, nc])
    return pac and atl
  for r in range(rows):
    for c in range(cols):
      if reaches(r, c): ans.append([r, c])
  return ans


# Method 2: Optimal
# Time: O(rc) | Space: O(rc)
# Reverse the flow: water climbs to equal or higher cells. DFS from all Pacific border cells, then from all Atlantic border cells. A cell in both visited sets is an answer. Each cell is processed a constant number of times.

def pacificAtlantic(heights):
  rows, cols = len(heights), len(heights[0])
  pac = [[False]*cols for _ in range(rows)]
  atl = [[False]*cols for _ in range(rows)]
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  def dfs(r, c, seen):
    seen[r][c] = True
    for i in range(4):
      nr, nc = r+dirs[i][0], c+dirs[i][1]
      if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
      if seen[nr][nc] or heights[nr][nc] < heights[r][c]: continue
      dfs(nr, nc, seen)
  for r in range(rows):
    dfs(r, 0, pac); dfs(r, cols-1, atl)
  for c in range(cols):
    dfs(0, c, pac); dfs(rows-1, c, atl)
  ans = []
  for r in range(rows):
    for c in range(cols):
      if pac[r][c] and atl[r][c]: ans.append([r,c])
  return ans


# Method 3: More optimal
# Time: O(rc) | Space: O(rc)
# Same reverse idea with BFS from both oceans. No recursion on a huge grid. Complexity is still linear in cells. This is the interview upgrade when they worry about stack depth.

from collections import deque
def pacificAtlantic(heights):
  rows, cols = len(heights), len(heights[0])
  pac = [[False]*cols for _ in range(rows)]
  atl = [[False]*cols for _ in range(rows)]
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  def bfs(q, seen):
    while q:
      r, c = q.popleft()
      for i in range(4):
        nr, nc = r+dirs[i][0], c+dirs[i][1]
        if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
        if seen[nr][nc] or heights[nr][nc] < heights[r][c]: continue
        seen[nr][nc] = True
        q.append((nr, nc))
  qp, qa = deque(), deque()
  for r in range(rows):
    pac[r][0]=True; qp.append((r,0))
    atl[r][cols-1]=True; qa.append((r,cols-1))
  for c in range(cols):
    pac[0][c]=True; qp.append((0,c))
    atl[rows-1][c]=True; qa.append((rows-1,c))
  bfs(qp, pac); bfs(qa, atl)
  ans=[]
  for r in range(rows):
    for c in range(cols):
      if pac[r][c] and atl[r][c]: ans.append([r,c])
  return ans
