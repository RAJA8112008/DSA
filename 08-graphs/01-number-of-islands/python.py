# Method 1: Brute
# Time: O(r²c²) | Space: O(rc)
# For every land cell we copy a full visited matrix and DFS that island. The extra copies are wasted work. Correct, but memory traffic is huge on a large grid.

def numIslands(grid):
  rows = len(grid)
  if not rows: return 0
  cols = len(grid[0])
  globalv = [[False] * cols for _ in range(rows)]
  count = 0
  dirs = [[1,0],[-1,0],[0,1],[0,-1]]
  for r in range(rows):
    for c in range(cols):
      if grid[r][c] != "1" or globalv[r][c]: continue
      count += 1
      seen = [row[:] for row in globalv]
      stack = [[r, c]]
      seen[r][c] = True
      while stack:
        x, y = stack.pop()
        globalv[x][y] = True
        for i in range(4):
          nx, ny = x + dirs[i][0], y + dirs[i][1]
          if nx < 0 or ny < 0 or nx >= rows or ny >= cols: continue
          if grid[nx][ny] != "1" or seen[nx][ny]: continue
          seen[nx][ny] = True
          stack.append([nx, ny])
  return count


# Method 2: Optimal
# Time: O(rc) | Space: O(rc)
# One DFS (or BFS) per island. Mutating land to water is the visited mark, so we never copy a matrix. Each cell is entered a constant number of times.

def numIslands(grid):
  rows = len(grid)
  if not rows: return 0
  cols = len(grid[0])
  count = 0
  def dfs(r, c):
    if r < 0 or c < 0 or r >= rows or c >= cols: return
    if grid[r][c] != "1": return
    grid[r][c] = "0"
    dfs(r+1, c); dfs(r-1, c); dfs(r, c+1); dfs(r, c-1)
  for r in range(rows):
    for c in range(cols):
      if grid[r][c] == "1":
        count += 1
        dfs(r, c)
  return count


# Method 3: More optimal
# Time: O(rc) | Space: O(rc)
# Union-Find treats each land cell as a node. You only union with the right and down land neighbor, so each edge is processed once. The island count is how many land roots remain. No recursion.

def numIslands(grid):
  rows = len(grid)
  if not rows: return 0
  cols = len(grid[0])
  n = rows * cols
  parent = list(range(n))
  rank = [0] * n
  islands = 0
  def id(r, c): return r * cols + c
  def find(x):
    while parent[x] != x:
      parent[x] = parent[parent[x]]
      x = parent[x]
    return x
  def union(a, b):
    nonlocal islands
    x, y = find(a), find(b)
    if x == y: return
    if rank[x] < rank[y]: x, y = y, x
    parent[y] = x
    if rank[x] == rank[y]: rank[x] += 1
    islands -= 1
  for r in range(rows):
    for c in range(cols):
      if grid[r][c] != "1": continue
      islands += 1
      if c + 1 < cols and grid[r][c+1] == "1": union(id(r,c), id(r,c+1))
      if r + 1 < rows and grid[r+1][c] == "1": union(id(r,c), id(r+1,c))
  return islands
