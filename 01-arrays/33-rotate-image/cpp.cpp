// Method 1: Brute
// Time: O(n²) | Space: O(n²)
// new[c][n-1-r] = old[r][c]. Copy back. Clear picture, extra matrix.

void rotate(vector<vector<int>>& matrix) {
  int n = (int)matrix.size();
  vector<vector<int>> neu(n, vector<int>(n));
  for (int r = 0; r < n; r++)
    for (int c = 0; c < n; c++) neu[c][n - 1 - r] = matrix[r][c];
  matrix = neu;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(1)
// Transpose (swap across the diagonal) then reverse each row. Two easy passes, in place.

void rotate(vector<vector<int>>& matrix) {
  int n = (int)matrix.size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) swap(matrix[i][j], matrix[j][i]);
  for (int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1)
// Layer by layer. For each offset, rotate the four cells of the cycle in one temp. Same work, no transpose helper. Nice to draw on a whiteboard.

void rotate(vector<vector<int>>& matrix) {
  int n = (int)matrix.size();
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
