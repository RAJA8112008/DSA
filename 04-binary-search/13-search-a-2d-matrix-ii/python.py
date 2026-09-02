# Method 1: Brute
# Time: O(rc) | Space: O(1)
# Visit every cell. Correct, ignores both sorted axes.

def searchMatrix(matrix, target):
  for row in matrix:
    if target in row:
      return True
  return False


# Method 2: Optimal
# Time: O(r log c) | Space: O(1)
# Each row is sorted, so binary search that row. Skip a row whose first cell is already larger than target or whose last cell is smaller. Good when there are few rows.

def searchMatrix(matrix, target):
  cols = len(matrix[0])
  for row in matrix:
    if row[0] > target or row[-1] < target:
      continue
    lo, hi = 0, cols - 1
    while lo <= hi:
      mid = lo + ((hi - lo) >> 1)
      if row[mid] == target:
        return True
      if row[mid] < target:
        lo = mid + 1
      else:
        hi = mid - 1
  return False


# Method 3: More optimal
# Time: O(r + c) | Space: O(1)
# Start at top-right. The cell is the largest in its row prefix and the smallest in its column suffix. Larger than target: nothing in this column below can be smaller in a useful way — move left. Smaller: move down. Each step drops a row or a column.

def searchMatrix(matrix, target):
  r, c = 0, len(matrix[0]) - 1
  while r < len(matrix) and c >= 0:
    if matrix[r][c] == target:
      return True
    if matrix[r][c] > target:
      c -= 1
    else:
      r += 1
  return False
