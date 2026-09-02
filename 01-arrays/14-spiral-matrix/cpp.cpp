// Method 1: Brute
// Time: O(m·n) | Space: O(m·n)
// You still visit each cell once, but a boolean grid of the same size is extra memory.
// How it works: start at (0,0) facing right. If the next cell is out of bounds or visited, turn right. Push each value.

// vector, unordered_map, string
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  if (!(int)matrix.size()) return {};
  int rows = (int)matrix.size();
  int cols = matrix[0].length;
  vector<int> seen;
  for (int r = 0; r < rows; r++) seen.push_back(vector<int>(cols, 0));
  int dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  vector<int> out;
  int r = 0;
  int c = 0;
  int d = 0;
  for (int k = 0; k < rows * cols; k++) {
    out.push_back(matrix[r][c]);
    seen[r][c] = true;
    int nr = r + dirs[d][0];
    int nc = c + dirs[d][1];
    if (nr < 0 || nr >= rows || nc < 0 || nc >= cols || seen[nr][nc]) {
      d = (d + 1) % 4;
    }
    r += dirs[d][0];
    c += dirs[d][1];
  }
  return out;
}


// Method 2: Optimal
// Time: O(m·n) | Space: O(1)
// Output list is required. Extra memory is a few bound integers, treated as O(1).
// How it works: peel a layer: walk top row left->right, right col top->bottom, bottom row right->left, left col bottom->top, then shrink the four bounds.

// vector, unordered_map, string
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  if (!(int)matrix.size()) return {};
  vector<int> out;
  int top = 0;
  int bottom = (int)matrix.size() - 1;
  int left = 0;
  int right = matrix[0].length - 1;
  while (top <= bottom && left <= right) {
    for (int c = left; c <= right; c++) out.push_back(matrix[top][c]);
    top++;
    for (int r = top; r <= bottom; r++) out.push_back(matrix[r][right]);
    right--;
    if (top <= bottom) {
      for (int c = right; c >= left; c--) out.push_back(matrix[bottom][c]);
      bottom--;
    }
    if (left <= right) {
      for (int r = bottom; r >= top; r--) out.push_back(matrix[r][left]);
      left++;
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(m·n) | Space: O(1)
// Same bounds idea in one counted loop: visit exactly rows*cols cells, turn when the next step would leave the remaining rectangle.
// How it works: after a turn, shrink the bound you just finished (top, right, bottom, or left) so the next lap is the inner layer.

// vector, unordered_map, string
vector<int> spiralOrder(vector<vector<int>>& matrix) {
  if (!(int)matrix.size()) return {};
  int rows = (int)matrix.size();
  int cols = matrix[0].length;
  vector<int> out;
  int top = 0;
  int bottom = rows - 1;
  int left = 0;
  int right = cols - 1;
  int dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  int d = 0;
  int r = 0;
  int c = 0;
  for (int k = 0; k < rows * cols; k++) {
    out.push_back(matrix[r][c]);
    int nr = r + dirs[d][0];
    int nc = c + dirs[d][1];
    if (nr < top || nr > bottom || nc < left || nc > right) {
      if (d == 0) top++;
      else if (d == 1) right--;
      else if (d == 2) bottom--;
      else left++;
      d = (d + 1) % 4;
      r += dirs[d][0];
      c += dirs[d][1];
    } else {
      r = nr;
      c = nc;
    }
  }
  return out;
}
