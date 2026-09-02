// Method 1: Brute
// Time: O(n²) | Space: O(n²)
// new[c][n-1-r] = old[r][c]. Copy back. Clear picture, extra matrix.

function rotate(matrix) {
  const n = matrix.length;
  const neu = Array.from({ length: n }, function () { return Array(n); });
  for (let r = 0; r < n; r++) {
    for (let c = 0; c < n; c++) neu[c][n - 1 - r] = matrix[r][c];
  }
  for (let r = 0; r < n; r++) {
    for (let c = 0; c < n; c++) matrix[r][c] = neu[r][c];
  }
  return matrix;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(1)
// Transpose (swap across the diagonal) then reverse each row. Two easy passes, in place.

function rotate(matrix) {
  const n = matrix.length;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const t = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = t;
    }
  }
  for (let i = 0; i < n; i++) {
    let L = 0, R = n - 1;
    while (L < R) {
      const t = matrix[i][L];
      matrix[i][L] = matrix[i][R];
      matrix[i][R] = t;
      L++;
      R--;
    }
  }
  return matrix;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1)
// Layer by layer. For each offset, rotate the four cells of the cycle in one temp. Same work, no transpose helper. Nice to draw on a whiteboard.

function rotate(matrix) {
  const n = matrix.length;
  for (let layer = 0; layer < (n >> 1); layer++) {
    const last = n - 1 - layer;
    for (let i = 0; i < last - layer; i++) {
      const top = matrix[layer][layer + i];
      matrix[layer][layer + i] = matrix[last - i][layer];
      matrix[last - i][layer] = matrix[last][last - i];
      matrix[last][last - i] = matrix[layer + i][last];
      matrix[layer + i][last] = top;
    }
  }
  return matrix;
}
