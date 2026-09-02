# Method 1: Brute
# Time: O(1) for 9x9 | Space: O(1)
# For every filled cell, walk its row, column, and 3x3 box looking for the same digit elsewhere. On a 9x9 this is constant, but the nested scans are noisy.

def isValidSudoku(board):
  def ok(r, c, d):
    for i in range(9):
      if i != c and board[r][i] == d:
        return False
      if i != r and board[i][c] == d:
        return False
    br, bc = (r // 3) * 3, (c // 3) * 3
    for i in range(3):
      for j in range(3):
        rr, cc = br + i, bc + j
        if (rr != r or cc != c) and board[rr][cc] == d:
          return False
    return True
  for r in range(9):
    for c in range(9):
      if board[r][c] == ".":
        continue
      if not ok(r, c, board[r][c]):
        return False
  return True


# Method 2: Optimal
# Time: O(1) | Space: O(1)
# Nine sets for rows, nine for columns, nine for boxes. Box id is (r/3)*3 + c/3. Fail on the first repeat.

def isValidSudoku(board):
  row = [set() for _ in range(9)]
  col = [set() for _ in range(9)]
  box = [set() for _ in range(9)]
  for r in range(9):
    for c in range(9):
      d = board[r][c]
      if d == ".":
        continue
      b = (r // 3) * 3 + (c // 3)
      if d in row[r] or d in col[c] or d in box[b]:
        return False
      row[r].add(d)
      col[c].add(d)
      box[b].add(d)
  return True


# Method 3: More optimal
# Time: O(1) | Space: O(1)
# Nine ints for rows, columns, boxes. Bit (1 << digit) marks a used number. A second hit on the same bit is a duplicate. Same logic, no hash sets.

def isValidSudoku(board):
  row = [0] * 9
  col = [0] * 9
  box = [0] * 9
  for r in range(9):
    for c in range(9):
      ch = board[r][c]
      if ch == ".":
        continue
      bit = 1 << (ord(ch) - 49)
      b = (r // 3) * 3 + (c // 3)
      if (row[r] & bit) or (col[c] & bit) or (box[b] & bit):
        return False
      row[r] |= bit
      col[c] |= bit
      box[b] |= bit
  return True
