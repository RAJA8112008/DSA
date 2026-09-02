# Method 1: Brute
# Time: O(9^{e}) | Space: O(e)
# e empty cells. Each guess clones the board and scans from scratch. Extra copies on every node. Correct but memory-heavy.

def solveSudoku(board):
  def valid(b, r, c, ch):
    for i in range(9):
      if b[r][i] == ch or b[i][c] == ch:
        return False
      br = (r // 3) * 3 + i // 3
      bc = (c // 3) * 3 + i % 3
      if b[br][bc] == ch:
        return False
    return True
  def go(b):
    for r in range(9):
      for c in range(9):
        if b[r][c] != ".":
          continue
        for d in range(1, 10):
          ch = str(d)
          if not valid(b, r, c, ch):
            continue
          copy = [row[:] for row in b]
          copy[r][c] = ch
          if go(copy):
            for i in range(9):
              b[i] = copy[i]
            return True
        return False
    return True
  go(board)


# Method 2: Optimal
# Time: O(9^{e}) | Space: O(e)
# Write a digit in place, recurse, write '.'. isValid scans the row, column, and box. No extra boards. First empty cell, left to right.

def solveSudoku(board):
  def valid(r, c, ch):
    for i in range(9):
      if board[r][i] == ch or board[i][c] == ch:
        return False
      if board[(r // 3) * 3 + i // 3][(c // 3) * 3 + i % 3] == ch:
        return False
    return True
  def go():
    for r in range(9):
      for c in range(9):
        if board[r][c] != ".":
          continue
        for d in range(1, 10):
          ch = str(d)
          if not valid(r, c, ch):
            continue
          board[r][c] = ch
          if go():
            return True
          board[r][c] = "."
        return False
    return True
  go()


# Method 3: More optimal
# Time: O(9^{e}) | Space: O(e)
# row[], col[], box[] bitmasks. Pick the empty cell with the fewest remaining digits (MRV) so dead ends die sooner. Toggle bits instead of scanning 9 cells.

def solveSudoku(board):
  row = [0] * 9
  col = [0] * 9
  box = [0] * 9
  empty = []
  for r in range(9):
    for c in range(9):
      if board[r][c] == ".":
        empty.append([r, c])
      else:
        bit = 1 << (ord(board[r][c]) - 49)
        row[r] |= bit
        col[c] |= bit
        box[(r // 3) * 3 + c // 3] |= bit
  def go(k):
    if k == len(empty):
      return True
    best, best_n = k, 10
    for i in range(k, len(empty)):
      r, c = empty[i]
      used = row[r] | col[c] | box[(r // 3) * 3 + c // 3]
      n = 9 - bin(used).count("1")
      if n < best_n:
        best_n, best = n, i
    empty[k], empty[best] = empty[best], empty[k]
    r, c = empty[k]
    b = (r // 3) * 3 + c // 3
    avail = ((1 << 9) - 1) ^ (row[r] | col[c] | box[b])
    while avail:
      bit = avail & -avail
      avail ^= bit
      d = bit.bit_length()
      board[r][c] = str(d)
      row[r] |= bit; col[c] |= bit; box[b] |= bit
      if go(k + 1):
        return True
      row[r] ^= bit; col[c] ^= bit; box[b] ^= bit
      board[r][c] = "."
    return False
  go(0)
