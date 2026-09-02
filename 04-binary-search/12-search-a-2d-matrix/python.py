# Method 1: Brute
# Time: O(rc) | Space: O(1)
# Compare every cell. Correct on any matrix. Ignores both sorted properties.

def searchMatrix(matrix, target):
  for row in matrix:
    for v in row:
      if v == target:
        return True
  return False


# Method 2: Optimal
# Time: O(log(rc)) | Space: O(1)
# Treat the grid as one sorted array of length rows*cols. Ordinary binary search. This uses the stronger 'next row starts after this row' rule.

def searchMatrix(matrix, target):
  rows, cols = len(matrix), len(matrix[0])
  lo, hi = 0, rows * cols - 1
  while lo <= hi:
    mid = (lo + hi) >> 1
    val = matrix[mid // cols][mid % cols]
    if val == target:
      return True
    if val < target:
      lo = mid + 1
    else:
      hi = mid - 1
  return False


# Method 3: More optimal
# Time: O(log r + log c) | Space: O(1)
# Overflow-safe mid. First find the last row whose first cell is <= target (or the unique row that can hold it). Then binary search that row. Same log(rc) probes, often clearer in an interview sketch.

def searchMatrix(matrix, target):
  rows, cols = len(matrix), len(matrix[0])
  lo, hi, row = 0, rows - 1, -1
  while lo <= hi:
    mid = lo + ((hi - lo) >> 1)
    if matrix[mid][0] <= target <= matrix[mid][cols - 1]:
      row = mid
      break
    if matrix[mid][0] > target:
      hi = mid - 1
    else:
      lo = mid + 1
  if row < 0:
    return False
  lo, hi = 0, cols - 1
  while lo <= hi:
    mid = lo + ((hi - lo) >> 1)
    if matrix[row][mid] == target:
      return True
    if matrix[row][mid] < target:
      lo = mid + 1
    else:
      hi = mid - 1
  return False
