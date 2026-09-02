// Method 1: Brute
// Time: O(n²) | Space: O(n²)
// new[c][n-1-r] = old[r][c]. Copy back. Clear picture, extra matrix.

void rotate(int n, int matrix[][16]) {
  int neu[16][16];
  int r, c;
  for (r = 0; r < n; r++)
    for (c = 0; c < n; c++) neu[c][n - 1 - r] = matrix[r][c];
  for (r = 0; r < n; r++)
    for (c = 0; c < n; c++) matrix[r][c] = neu[r][c];
}


// Method 2: Optimal
// Time: O(n²) | Space: O(1)
// Transpose (swap across the diagonal) then reverse each row. Two easy passes, in place.

void rotate(int n, int matrix[][16]) {
  int i, j, L, R, t;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      t = matrix[i][j]; matrix[i][j] = matrix[j][i]; matrix[j][i] = t;
    }
  for (i = 0; i < n; i++) {
    L = 0; R = n - 1;
    while (L < R) {
      t = matrix[i][L]; matrix[i][L] = matrix[i][R]; matrix[i][R] = t;
      L++; R--;
    }
  }
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1)
// Layer by layer. For each offset, rotate the four cells of the cycle in one temp. Same work, no transpose helper. Nice to draw on a whiteboard.

void rotateCycles(int n, int matrix[][16]) {
  int layer, i, last, top;
  for (layer = 0; layer < n / 2; layer++) {
    last = n - 1 - layer;
    for (i = 0; i < last - layer; i++) {
      top = matrix[layer][layer + i];
      matrix[layer][layer + i] = matrix[last - i][layer];
      matrix[last - i][layer] = matrix[last][last - i];
      matrix[last][last - i] = matrix[layer + i][last];
      matrix[layer + i][last] = top;
    }
  }
}
