# Method 1: Brute
# Time: O(r c * 4^L) | Space: O(r c * L)
# Every recursive step clones the whole visited grid. Correct, but memory traffic is huge. L is the word length. 4^L walks from each start.

def exist(board, word):
  rows, cols = len(board), len(board[0])
  def dfs(r, c, k, seen):
    if k == len(word):
      return True
    if r < 0 or c < 0 or r >= rows or c >= cols:
      return False
    if seen[r][c] or board[r][c] != word[k]:
      return False
    copy = [row[:] for row in seen]
    copy[r][c] = True
    return (dfs(r + 1, c, k + 1, copy) or dfs(r - 1, c, k + 1, copy) or
            dfs(r, c + 1, k + 1, copy) or dfs(r, c - 1, k + 1, copy))
  blank = [[False] * cols for _ in range(rows)]
  for r in range(rows):
    for c in range(cols):
      if dfs(r, c, 0, blank):
        return True
  return False


# Method 2: Optimal
# Time: O(r c * 4^L) | Space: O(L)
# Mark the cell as '#' (or a visited flag), recurse four ways, restore the letter. One board, undo after each branch. Stack is O(L).

def exist(board, word):
  rows, cols = len(board), len(board[0])
  def dfs(r, c, k):
    if k == len(word):
      return True
    if r < 0 or c < 0 or r >= rows or c >= cols:
      return False
    if board[r][c] != word[k]:
      return False
    ch = board[r][c]
    board[r][c] = "#"
    ok = (dfs(r + 1, c, k + 1) or dfs(r - 1, c, k + 1) or
          dfs(r, c + 1, k + 1) or dfs(r, c - 1, k + 1))
    board[r][c] = ch
    return ok
  for r in range(rows):
    for c in range(cols):
      if dfs(r, c, 0):
        return True
  return False


# Method 3: More optimal
# Time: O(r c * 4^L) | Space: O(L)
# Count letters first. If the board cannot supply a letter, return false. Search from the rarer end of the word. Return true on the first hit so you do not walk the rest of the grid.

def exist(board, word):
  rows, cols = len(board), len(board[0])
  need = {}
  have = {}
  for ch in word:
    need[ch] = need.get(ch, 0) + 1
  for r in range(rows):
    for c in range(cols):
      have[board[r][c]] = have.get(board[r][c], 0) + 1
  for ch, cnt in need.items():
    if have.get(ch, 0) < cnt:
      return False
  if have.get(word[0], 0) > have.get(word[-1], 0):
    word = word[::-1]
  def dfs(r, c, k):
    if k == len(word):
      return True
    if r < 0 or c < 0 or r >= rows or c >= cols:
      return False
    if board[r][c] != word[k]:
      return False
    ch = board[r][c]
    board[r][c] = "#"
    ok = (dfs(r + 1, c, k + 1) or dfs(r - 1, c, k + 1) or
          dfs(r, c + 1, k + 1) or dfs(r, c - 1, k + 1))
    board[r][c] = ch
    return ok
  for r in range(rows):
    for c in range(cols):
      if dfs(r, c, 0):
        return True
  return False
