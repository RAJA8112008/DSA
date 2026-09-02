// Method 1: Brute
// Time: O(rc) | Space: O(1)
// Visit every cell. Correct, ignores both sorted axes.

int searchMatrix(int** matrix, int rows, int cols, int target) {
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++)
      if (matrix[r][c] == target) return 1;
  return 0;
}


// Method 2: Optimal
// Time: O(r log c) | Space: O(1)
// Each row is sorted, so binary search that row. Skip a row whose first cell is already larger than target or whose last cell is smaller. Good when there are few rows.

int searchMatrix(int** matrix, int rows, int cols, int target) {
  for (int r = 0; r < rows; r++) {
    if (matrix[r][0] > target || matrix[r][cols - 1] < target) continue;
    int lo = 0, hi = cols - 1;
    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (matrix[r][mid] == target) return 1;
      if (matrix[r][mid] < target) lo = mid + 1;
      else hi = mid - 1;
    }
  }
  return 0;
}


// Method 3: More optimal
// Time: O(r + c) | Space: O(1)
// Start at top-right. The cell is the largest in its row prefix and the smallest in its column suffix. Larger than target: nothing in this column below can be smaller in a useful way — move left. Smaller: move down. Each step drops a row or a column.

int searchMatrix(int** matrix, int rows, int cols, int target) {
  int r = 0, c = cols - 1;
  while (r < rows && c >= 0) {
    if (matrix[r][c] == target) return 1;
    if (matrix[r][c] > target) c--;
    else r++;
  }
  return 0;
}
