# Method 1: Brute
# Time: O(n * n!) | Space: O(n^2)
# Generate every permutation of columns with extra copies. After a full permutation, scan every pair for a shared diagonal. Most permutations fail only at the end.

def solveNQueens(n):
  ans = []
  def ok(cols):
    for i in range(n):
      for j in range(i + 1, n):
        if abs(i - j) == abs(cols[i] - cols[j]):
          return False
    return True
  def go(left, cols):
    if not left:
      if not ok(cols):
        return
      board = []
      for r in range(n):
        board.append("".join("Q" if c == cols[r] else "." for c in range(n)))
      ans.append(board)
      return
    for i in range(len(left)):
      go(left[:i] + left[i+1:], cols + [left[i]])
  go(list(range(n)), [])
  return ans


# Method 2: Optimal
# Time: O(n!) | Space: O(n^2)
# Place one queen per row. col[], d1[], d2[] mark attacks. If the square is free, mark, recurse row+1, unmark. Failures die as soon as a row has no square.

def solveNQueens(n):
  ans = []
  board = [["."] * n for _ in range(n)]
  col = [0] * n
  d1 = [0] * (2 * n)
  d2 = [0] * (2 * n)
  def go(row):
    if row == n:
      ans.append(["".join(r) for r in board])
      return
    for c in range(n):
      if col[c] or d1[row - c + n] or d2[row + c]:
        continue
      col[c] = d1[row - c + n] = d2[row + c] = 1
      board[row][c] = "Q"
      go(row + 1)
      board[row][c] = "."
      col[c] = d1[row - c + n] = d2[row + c] = 0
  go(0)
  return ans


# Method 3: More optimal
# Time: O(n!) | Space: O(n^2)
# cols, diag, anti as bitmasks. available bits are the free columns. Take the lowest set bit, recurse with shifted diagonals. Same search, O(1) updates.

def solveNQueens(n):
  ans = []
  board = [["."] * n for _ in range(n)]
  def go(row, cols, d1, d2):
    if row == n:
      ans.append(["".join(r) for r in board])
      return
    avail = ((1 << n) - 1) & ~(cols | d1 | d2)
    while avail:
      bit = avail & -avail
      avail ^= bit
      c = (bit.bit_length() - 1)
      board[row][c] = "Q"
      go(row + 1, cols | bit, (d1 | bit) << 1, (d2 | bit) >> 1)
      board[row][c] = "."
  go(0, 0, 0, 0)
  return ans
