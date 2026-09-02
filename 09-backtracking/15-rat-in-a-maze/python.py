# Method 1: Brute
# Time: O(4^{n^2}) | Space: O(n^2)
# Each step clones visited and concatenates a new path string. Exponential walks, extra copies at every node. Fine on n = 2, painful on n = 5.

def ratInMaze(grid):
  n = len(grid)
  ans = []
  dirs = [(1, 0, "D"), (0, -1, "L"), (0, 1, "R"), (-1, 0, "U")]
  def go(r, c, path, seen):
    if r == n - 1 and c == n - 1:
      ans.append(path)
      return
    for dr, dc, ch in dirs:
      nr, nc = r + dr, c + dc
      if nr < 0 or nc < 0 or nr >= n or nc >= n:
        continue
      if grid[nr][nc] == 0 or seen[nr][nc]:
        continue
      copy = [row[:] for row in seen]
      copy[nr][nc] = True
      go(nr, nc, path + ch, copy)
  if not n or grid[0][0] == 0:
    return ans
  seen = [[False] * n for _ in range(n)]
  seen[0][0] = True
  go(0, 0, "", seen)
  return ans


# Method 2: Optimal
# Time: O(4^{n^2}) | Space: O(n^2)
# Mark grid[r][c] = 0 (or a visited flag), append D/L/R/U, recurse, restore 1. One path buffer. Copy the string only when you hit the end.

def ratInMaze(grid):
  n = len(grid)
  ans = []
  dirs = [(1, 0, "D"), (0, -1, "L"), (0, 1, "R"), (-1, 0, "U")]
  def go(r, c, path):
    if r == n - 1 and c == n - 1:
      ans.append("".join(path))
      return
    for dr, dc, ch in dirs:
      nr, nc = r + dr, c + dc
      if nr < 0 or nc < 0 or nr >= n or nc >= n:
        continue
      if grid[nr][nc] == 0:
        continue
      grid[nr][nc] = 0
      path.append(ch)
      go(nr, nc, path)
      path.pop()
      grid[nr][nc] = 1
  if not n or grid[0][0] == 0:
    return ans
  grid[0][0] = 0
  go(0, 0, [])
  grid[0][0] = 1
  return ans


# Method 3: More optimal
# Time: O(4^{n^2}) | Space: O(n^2)
# Same mark/unmark, plus skip a blocked start immediately. Try directions in DLRU order so the output is already sorted, no extra sort. Dead walls never enter the stack.

def ratInMaze(grid):
  n = len(grid)
  ans = []
  if not n or grid[0][0] == 0 or grid[n - 1][n - 1] == 0:
    return ans
  dirs = [(1, 0, "D"), (0, -1, "L"), (0, 1, "R"), (-1, 0, "U")]
  def go(r, c, path):
    if r == n - 1 and c == n - 1:
      ans.append("".join(path))
      return
    for dr, dc, ch in dirs:
      nr, nc = r + dr, c + dc
      if nr < 0 or nc < 0 or nr >= n or nc >= n:
        continue
      if grid[nr][nc] != 1:
        continue
      grid[nr][nc] = 0
      path.append(ch)
      go(nr, nc, path)
      path.pop()
      grid[nr][nc] = 1
  grid[0][0] = 0
  go(0, 0, [])
  grid[0][0] = 1
  return ans
