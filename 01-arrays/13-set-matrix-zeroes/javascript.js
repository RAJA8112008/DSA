// Method 1: Brute
// Time: O(m·n) | Space: O(m·n)
// You copy the whole grid so newly written zeros do not trigger more rows. Memory is the full matrix.
// How it works: scan the copy; if copy[r][c] is 0, zero row r and column c in the original.

function setZeroes(matrix) {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const copy = [];
  for (let r = 0; r < rows; r++) copy.push(matrix[r].slice());
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (copy[r][c] === 0) {
        for (let x = 0; x < cols; x++) matrix[r][x] = 0;
        for (let y = 0; y < rows; y++) matrix[y][c] = 0;
      }
    }
  }
  return matrix;
}


// Method 2: Optimal
// Time: O(m·n) | Space: O(m + n)
// Two flag arrays instead of a full copy. Time is still a few passes over the grid.
// How it works: mark which rows and columns contain a zero, then write zeros in a second pass.

function setZeroes(matrix) {
  const rows = matrix.length;
  const cols = matrix[0].length;
  const zeroRow = new Array(rows).fill(false);
  const zeroCol = new Array(cols).fill(false);
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (matrix[r][c] === 0) {
        zeroRow[r] = true;
        zeroCol[c] = true;
      }
    }
  }
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (zeroRow[r] || zeroCol[c]) matrix[r][c] = 0;
    }
  }
  return matrix;
}


// Method 3: More optimal
// Time: O(m·n) | Space: O(1)
// Flags live in the first row and first column. Only two extra booleans.
// How it works: record whether row 0 and col 0 need to be cleared. For the rest, matrix[r][0] and matrix[0][c] mark zeros. Clear the interior, then the first row/col if needed.

function setZeroes(matrix) {
  const rows = matrix.length;
  const cols = matrix[0].length;
  let firstRow = false;
  let firstCol = false;
  for (let c = 0; c < cols; c++) if (matrix[0][c] === 0) firstRow = true;
  for (let r = 0; r < rows; r++) if (matrix[r][0] === 0) firstCol = true;
  for (let r = 1; r < rows; r++) {
    for (let c = 1; c < cols; c++) {
      if (matrix[r][c] === 0) {
        matrix[r][0] = 0;
        matrix[0][c] = 0;
      }
    }
  }
  for (let r = 1; r < rows; r++) {
    for (let c = 1; c < cols; c++) {
      if (matrix[r][0] === 0 || matrix[0][c] === 0) matrix[r][c] = 0;
    }
  }
  if (firstRow) for (let c = 0; c < cols; c++) matrix[0][c] = 0;
  if (firstCol) for (let r = 0; r < rows; r++) matrix[r][0] = 0;
  return matrix;
}
