// Method 1: Brute
// Time: O(rc) | Space: O(1)
// Visit every cell. Correct, ignores both sorted axes.

function searchMatrix(matrix, target) {
  for (let r = 0; r < matrix.length; r++) {
    for (let c = 0; c < matrix[0].length; c++) {
      if (matrix[r][c] === target) return true;
    }
  }
  return false;
}


// Method 2: Optimal
// Time: O(r log c) | Space: O(1)
// Each row is sorted, so binary search that row. Skip a row whose first cell is already larger than target or whose last cell is smaller. Good when there are few rows.

function searchMatrix(matrix, target) {
  const cols = matrix[0].length;
  for (let r = 0; r < matrix.length; r++) {
    if (matrix[r][0] > target || matrix[r][cols - 1] < target) continue;
    let lo = 0, hi = cols - 1;
    while (lo <= hi) {
      const mid = lo + ((hi - lo) >> 1);
      if (matrix[r][mid] === target) return true;
      if (matrix[r][mid] < target) lo = mid + 1;
      else hi = mid - 1;
    }
  }
  return false;
}


// Method 3: More optimal
// Time: O(r + c) | Space: O(1)
// Start at top-right. The cell is the largest in its row prefix and the smallest in its column suffix. Larger than target: nothing in this column below can be smaller in a useful way — move left. Smaller: move down. Each step drops a row or a column.

function searchMatrix(matrix, target) {
  let r = 0, c = matrix[0].length - 1;
  while (r < matrix.length && c >= 0) {
    if (matrix[r][c] === target) return true;
    if (matrix[r][c] > target) c--;
    else r++;
  }
  return false;
}
