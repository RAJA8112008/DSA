// Method 1: Brute
// Time: O(n²) | Space: O(n²)
// new[c][n-1-r] = old[r][c]. Copy back. Clear picture, extra matrix.

class Solution {
  public void rotate(int[][] matrix) {
    int n = matrix.length;
    int[][] neu = new int[n][n];
    for (int r = 0; r < n; r++)
      for (int c = 0; c < n; c++) neu[c][n - 1 - r] = matrix[r][c];
    for (int r = 0; r < n; r++)
      for (int c = 0; c < n; c++) matrix[r][c] = neu[r][c];
  }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(1)
// Transpose (swap across the diagonal) then reverse each row. Two easy passes, in place.

class Solution {
  public void rotate(int[][] matrix) {
    int n = matrix.length;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        int t = matrix[i][j]; matrix[i][j] = matrix[j][i]; matrix[j][i] = t;
      }
    for (int i = 0; i < n; i++) {
      int L = 0, R = n - 1;
      while (L < R) {
        int t = matrix[i][L]; matrix[i][L] = matrix[i][R]; matrix[i][R] = t;
        L++; R--;
      }
    }
  }
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1)
// Layer by layer. For each offset, rotate the four cells of the cycle in one temp. Same work, no transpose helper. Nice to draw on a whiteboard.

class Solution {
  public void rotate(int[][] matrix) {
    int n = matrix.length;
    for (int layer = 0; layer < n / 2; layer++) {
      int last = n - 1 - layer;
      for (int i = 0; i < last - layer; i++) {
        int top = matrix[layer][layer + i];
        matrix[layer][layer + i] = matrix[last - i][layer];
        matrix[last - i][layer] = matrix[last][last - i];
        matrix[last][last - i] = matrix[layer + i][last];
        matrix[layer + i][last] = top;
      }
    }
  }
}
