// Method 1: Brute
// Time: O(rc) | Space: O(1)
// Compare every cell. Correct on any matrix. Ignores both sorted properties.

function searchMatrix(matrix, target) {
  for (let r = 0; r < matrix.length; r++) {
    for (let c = 0; c < matrix[0].length; c++) {
      if (matrix[r][c] === target) return true;
    }
  }
  return false;
}


// Method 2: Optimal
// Time: O(log(rc)) | Space: O(1)
// Treat the grid as one sorted array of length rows*cols. Ordinary binary search. This uses the stronger 'next row starts after this row' rule.

function searchMatrix(matrix, target) {
  const rows = matrix.length, cols = matrix[0].length;
  let lo = 0, hi = rows * cols - 1;
  while (lo <= hi) {
    const mid = (lo + hi) >> 1;
    const val = matrix[Math.floor(mid / cols)][mid % cols];
    if (val === target) return true;
    if (val < target) lo = mid + 1;
    else hi = mid - 1;
  }
  return false;
}


// Method 3: More optimal
// Time: O(log r + log c) | Space: O(1)
// Overflow-safe mid. First find the last row whose first cell is <= target (or the unique row that can hold it). Then binary search that row. Same log(rc) probes, often clearer in an interview sketch.

function searchMatrix(matrix, target) {
  const rows = matrix.length, cols = matrix[0].length;
  let lo = 0, hi = rows - 1, row = -1;
  while (lo <= hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (matrix[mid][0] <= target && target <= matrix[mid][cols - 1]) {
      row = mid;
      break;
    }
    if (matrix[mid][0] > target) hi = mid - 1;
    else lo = mid + 1;
  }
  if (row < 0) return false;
  lo = 0; hi = cols - 1;
  while (lo <= hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (matrix[row][mid] === target) return true;
    if (matrix[row][mid] < target) lo = mid + 1;
    else hi = mid - 1;
  }
  return false;
}
