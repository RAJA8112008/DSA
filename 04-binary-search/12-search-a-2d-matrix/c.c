// Method 1: Brute
// Time: O(rc) | Space: O(1)
// Compare every cell. Correct on any matrix. Ignores both sorted properties.

int searchMatrix(int** matrix, int rows, int cols, int target) {
  for (int r = 0; r < rows; r++)
    for (int c = 0; c < cols; c++)
      if (matrix[r][c] == target) return 1;
  return 0;
}


// Method 2: Optimal
// Time: O(log(rc)) | Space: O(1)
// Treat the grid as one sorted array of length rows*cols. Ordinary binary search. This uses the stronger 'next row starts after this row' rule.

int searchMatrix(int** matrix, int rows, int cols, int target) {
  int lo = 0, hi = rows * cols - 1;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    int val = matrix[mid / cols][mid % cols];
    if (val == target) return 1;
    if (val < target) lo = mid + 1;
    else hi = mid - 1;
  }
  return 0;
}


// Method 3: More optimal
// Time: O(log r + log c) | Space: O(1)
// Overflow-safe mid. First find the last row whose first cell is <= target (or the unique row that can hold it). Then binary search that row. Same log(rc) probes, often clearer in an interview sketch.

int searchMatrix(int** matrix, int rows, int cols, int target) {
  int lo = 0, hi = rows - 1, row = -1;
  while (lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (matrix[mid][0] <= target && target <= matrix[mid][cols - 1]) { row = mid; break; }
    if (matrix[mid][0] > target) hi = mid - 1;
    else lo = mid + 1;
  }
  if (row < 0) return 0;
  lo = 0; hi = cols - 1;
  while (lo <= hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (matrix[row][mid] == target) return 1;
    if (matrix[row][mid] < target) lo = mid + 1;
    else hi = mid - 1;
  }
  return 0;
}
