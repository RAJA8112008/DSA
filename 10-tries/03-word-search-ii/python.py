# Method 1: Brute
# Time: O(w m n 4^L) | Space: O(L)
# For each word, DFS from every cell. Mark the cell, try four neighbors, unmark. Correct, but you restart the whole board for every dictionary word.

def findWords(board, words):
  rows, cols = len(board), len(board[0])
  dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
  def dfs(r, c, k, word):
    if k == len(word):
      return True
    if r < 0 or c < 0 or r >= rows or c >= cols:
      return False
    if board[r][c] != word[k]:
      return False
    saved = board[r][c]
    board[r][c] = "#"
    for dr, dc in dirs:
      if dfs(r + dr, c + dc, k + 1, word):
        board[r][c] = saved
        return True
    board[r][c] = saved
    return False
  out = []
  for word in words:
    found = False
    for r in range(rows):
      if found:
        break
      for c in range(cols):
        if dfs(r, c, 0, word):
          found = True
          break
    if found:
      out.append(word)
  return out


# Method 2: Optimal
# Time: O(m n 4^L) | Space: O(total chars)
# Build a trie of all words, then DFS from every cell following only living children. One board walk instead of one walk per word.

def findWords(board, words):
  def node():
    return {"ch": [None] * 26, "end": False, "word": ""}
  root = node()
  for s in words:
    cur = root
    for ch in s:
      idx = ord(ch) - 97
      if cur["ch"][idx] is None:
        cur["ch"][idx] = node()
      cur = cur["ch"][idx]
    cur["end"] = True
    cur["word"] = s
  rows, cols = len(board), len(board[0])
  dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
  seen = set()
  out = []
  def dfs(r, c, cur):
    if r < 0 or c < 0 or r >= rows or c >= cols:
      return
    ch = board[r][c]
    if ch == "#":
      return
    nxt = cur["ch"][ord(ch) - 97]
    if nxt is None:
      return
    if nxt["end"] and nxt["word"] not in seen:
      seen.add(nxt["word"])
      out.append(nxt["word"])
    board[r][c] = "#"
    for dr, dc in dirs:
      dfs(r + dr, c + dc, nxt)
    board[r][c] = ch
  for r in range(rows):
    for c in range(cols):
      dfs(r, c, root)
  return out


# Method 3: More optimal
# Time: O(m n 4^L) | Space: O(total chars)
# Same trie DFS, but after you emit a word you clear that end mark (and optionally prune empty children). That stops duplicate work and extra copies of the same word.

def findWords(board, words):
  def node():
    return {"ch": {}, "word": None}
  root = node()
  for s in words:
    cur = root
    for ch in s:
      if ch not in cur["ch"]:
        cur["ch"][ch] = node()
      cur = cur["ch"][ch]
    cur["word"] = s
  rows, cols = len(board), len(board[0])
  dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]]
  out = []
  def dfs(r, c, cur):
    ch = board[r][c]
    nxt = cur["ch"].get(ch)
    if nxt is None:
      return
    if nxt["word"]:
      out.append(nxt["word"])
      nxt["word"] = None
    board[r][c] = "#"
    for dr, dc in dirs:
      nr, nc = r + dr, c + dc
      if nr < 0 or nc < 0 or nr >= rows or nc >= cols:
        continue
      if board[nr][nc] == "#":
        continue
      dfs(nr, nc, nxt)
    board[r][c] = ch
  for r in range(rows):
    for c in range(cols):
      dfs(r, c, root)
  return out
