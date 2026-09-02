// Method 1: Brute
// Time: O(m·n) | Space: O(m·n)
// You copy the whole grid so newly written zeros do not trigger more rows. Memory is the full matrix.
// How it works: scan the copy; if copy[r][c] is 0, zero row r and column c in the original.

/* pass n for array length; simple loops */
void setZeroes(int** matrix, int rows, int cols) {
  int rows = rows;
  int cols = matrix[0].length;
  int copy[1024]; int copy_n = 0;
  for (int r = 0; r < rows; r++) /* push */(matrix[r].slice());
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (copy[r][c] == 0) {
        for (int x = 0; x < cols; x++) matrix[r][x] = 0;
        for (int y = 0; y < rows; y++) matrix[y][c] = 0;
      }
    }
  }
  return matrix;
}


// Method 2: Optimal
// Time: O(m·n) | Space: O(m + n)
// Two flag arrays instead of a full copy. Time is still a few passes over the grid.
// How it works: mark which rows and columns contain a zero, then write zeros in a second pass.

/* pass n for array length; simple loops */
void setZeroes(int** matrix, int rows, int cols) {
  int rows = rows;
  int cols = matrix[0].length;
  int zeroRow = /* zeros rows */;
  int zeroCol = /* zeros cols */;
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (matrix[r][c] == 0) {
        zeroRow[r] = 1;
        zeroCol[c] = 1;
      }
    }
  }
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (zeroRow[r] || zeroCol[c]) matrix[r][c] = 0;
    }
  }
  return matrix;
}


// Method 3: More optimal
// Time: O(m·n) | Space: O(1)
// Flags live in the first row and first column. Only two extra booleans.
// How it works: record whether row 0 and col 0 need to be cleared. For the rest, matrix[r][0] and matrix[0][c] mark zeros. Clear the interior, then the first row/col if needed.

/* pass n for array length; simple loops */
void setZeroes(int** matrix, int rows, int cols) {
  int rows = rows;
  int cols = matrix[0].length;
  int firstRow = 0;
  int firstCol = 0;
  for (int c = 0; c < cols; c++) if (matrix[0][c] == 0) firstRow = 1;
  for (int r = 0; r < rows; r++) if (matrix[r][0] == 0) firstCol = 1;
  for (int r = 1; r < rows; r++) {
    for (int c = 1; c < cols; c++) {
      if (matrix[r][c] == 0) {
        matrix[r][0] = 0;
        matrix[0][c] = 0;
      }
    }
  }
  for (int r = 1; r < rows; r++) {
    for (int c = 1; c < cols; c++) {
      if (matrix[r][0] == 0 || matrix[0][c] == 0) matrix[r][c] = 0;
    }
  }
  if (firstRow) for (int c = 0; c < cols; c++) matrix[0][c] = 0;
  if (firstCol) for (int r = 0; r < rows; r++) matrix[r][0] = 0;
  return matrix;
}
