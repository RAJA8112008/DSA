# Method 1: Brute
# Time: O(r²c²) | Space: O(rc)
# For each O, copy a visited matrix and DFS. If that blob never hits a border, flip those cells. Repeated walks over the same region.

def solve(board):
  rows=len(board)
  if not rows: return
  cols=len(board[0])
  dirs=[[1,0],[-1,0],[0,1],[0,-1]]
  def blob(sr, sc):
    seen=[[False]*cols for _ in range(rows)]
    cells=[]; q=[[sr,sc]]; seen[sr][sc]=True; border=False
    while q:
      r,c=q.pop(); cells.append([r,c])
      if r==0 or c==0 or r==rows-1 or c==cols-1: border=True
      for i in range(4):
        nr,nc=r+dirs[i][0], c+dirs[i][1]
        if nr<0 or nc<0 or nr>=rows or nc>=cols: continue
        if seen[nr][nc] or board[nr][nc]!="O": continue
        seen[nr][nc]=True; q.append([nr,nc])
    return {"cells": cells, "border": border}
  flipped=[[False]*cols for _ in range(rows)]
  for r in range(rows):
    for c in range(cols):
      if board[r][c]!="O" or flipped[r][c]: continue
      info=blob(r,c)
      if not info["border"]:
        for x,y in info["cells"]: board[x][y]="X"
      for x,y in info["cells"]: flipped[x][y]=True


# Method 2: Optimal
# Time: O(rc) | Space: O(rc)
# DFS/BFS from every border O and mark those cells (for example '#'). Then walk the board: leftover O is surrounded and becomes X; '#' is restored to O.

def solve(board):
  rows=len(board)
  if not rows: return
  cols=len(board[0])
  def dfs(r,c):
    if r<0 or c<0 or r>=rows or c>=cols: return
    if board[r][c]!="O": return
    board[r][c]="#"
    dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1)
  for r in range(rows):
    dfs(r,0); dfs(r, cols-1)
  for c in range(cols):
    dfs(0,c); dfs(rows-1, c)
  for r in range(rows):
    for c in range(cols):
      if board[r][c]=="O": board[r][c]="X"
      elif board[r][c]=="#": board[r][c]="O"


# Method 3: More optimal
# Time: O(rc) | Space: O(rc)
# Union-Find. Dummy node DUMMY represents 'touches border'. Union every O with its O neighbors, and union border O with DUMMY. Then flip O whose root is not DUMMY. No recursion.

def solve(board):
  rows=len(board)
  if not rows: return
  cols=len(board[0])
  DUMMY=rows*cols
  parent=list(range(DUMMY+1))
  def find(x):
    while parent[x]!=x:
      parent[x]=parent[parent[x]]; x=parent[x]
    return x
  def union(a,b):
    x,y=find(a),find(b)
    if x!=y: parent[y]=x
  def id(r,c): return r*cols+c
  for r in range(rows):
    for c in range(cols):
      if board[r][c]!="O": continue
      if r==0 or c==0 or r==rows-1 or c==cols-1: union(id(r,c), DUMMY)
      if r+1<rows and board[r+1][c]=="O": union(id(r,c), id(r+1,c))
      if c+1<cols and board[r][c+1]=="O": union(id(r,c), id(r,c+1))
  dummyRoot=find(DUMMY)
  for r in range(rows):
    for c in range(cols):
      if board[r][c]=="O" and find(id(r,c))!=dummyRoot: board[r][c]="X"
