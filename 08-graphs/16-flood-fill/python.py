# Method 1: Brute
# Time: O(rc) | Space: O(rc)
# DFS with a brand-new visited matrix copy even though one matrix is enough. Extra memory, same walk. Shows the 'copy visited' habit you should drop.

def floodFill(image, sr, sc, color):
  rows, cols = len(image), len(image[0])
  old = image[sr][sc]
  if old == color: return image
  seen = [[False]*cols for _ in range(rows)]
  def dfs(r, c, vis):
    if r<0 or c<0 or r>=rows or c>=cols: return
    if vis[r][c] or image[r][c]!=old: return
    copy = [row[:] for row in vis]
    copy[r][c]=True; vis[r][c]=True
    image[r][c]=color
    dfs(r+1,c,copy); dfs(r-1,c,copy); dfs(r,c+1,copy); dfs(r,c-1,copy)
  dfs(sr, sc, seen)
  return image


# Method 2: Optimal
# Time: O(rc) | Space: O(rc)
# DFS from the start. Painting to the new color is the visited mark when old !== color. Each cell in the blob is painted once.

def floodFill(image, sr, sc, color):
  old=image[sr][sc]
  if old==color: return image
  rows, cols=len(image), len(image[0])
  def dfs(r,c):
    if r<0 or c<0 or r>=rows or c>=cols: return
    if image[r][c]!=old: return
    image[r][c]=color
    dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1)
  dfs(sr,sc)
  return image


# Method 3: More optimal
# Time: O(rc) | Space: O(rc)
# BFS with a queue. Same linear bound, no recursive stack. Prefer this on a huge image so the call stack cannot overflow.

from collections import deque
def floodFill(image, sr, sc, color):
  old=image[sr][sc]
  if old==color: return image
  rows, cols=len(image), len(image[0])
  q=deque([(sr,sc)])
  image[sr][sc]=color
  dirs=[[1,0],[-1,0],[0,1],[0,-1]]
  while q:
    r,c=q.popleft()
    for i in range(4):
      nr,nc=r+dirs[i][0], c+dirs[i][1]
      if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
      if image[nr][nc]!=old: continue
      image[nr][nc]=color; q.append((nr,nc))
  return image
