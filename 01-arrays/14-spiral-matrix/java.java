// Method 1: Brute
// Time: O(m·n) | Space: O(m·n)
// You still visit each cell once, but a boolean grid of the same size is extra memory.
// How it works: start at (0,0) facing right. If the next cell is out of bounds or visited, turn right. Push each value.

class Solution {
  public List<Integer> spiralOrder(int[][] matrix) {
    if (!matrix.length) return new ArrayList<>();
    int rows = matrix.length;
    int cols = matrix[0].length;
    List<Integer> seen = new ArrayList<>();
    for (int r = 0; r < rows; r++) seen.add(new boolean[cols]);
    int dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    List<Integer> out = new ArrayList<>();
    int r = 0;
    int c = 0;
    int d = 0;
    for (int k = 0; k < rows * cols; k++) {
      out.add(matrix[r][c]);
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
}


// Method 2: Optimal
// Time: O(m·n) | Space: O(1)
// Output list is required. Extra memory is a few bound integers, treated as O(1).
// How it works: peel a layer: walk top row left->right, right col top->bottom, bottom row right->left, left col bottom->top, then shrink the four bounds.

class Solution {
  public List<Integer> spiralOrder(int[][] matrix) {
    if (!matrix.length) return new ArrayList<>();
    List<Integer> out = new ArrayList<>();
    int top = 0;
    int bottom = matrix.length - 1;
    int left = 0;
    int right = matrix[0].length - 1;
    while (top <= bottom && left <= right) {
      for (int c = left; c <= right; c++) out.add(matrix[top][c]);
      top++;
      for (int r = top; r <= bottom; r++) out.add(matrix[r][right]);
      right--;
      if (top <= bottom) {
        for (int c = right; c >= left; c--) out.add(matrix[bottom][c]);
        bottom--;
      }
      if (left <= right) {
        for (int r = bottom; r >= top; r--) out.add(matrix[r][left]);
        left++;
      }
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(m·n) | Space: O(1)
// Same bounds idea in one counted loop: visit exactly rows*cols cells, turn when the next step would leave the remaining rectangle.
// How it works: after a turn, shrink the bound you just finished (top, right, bottom, or left) so the next lap is the inner layer.

class Solution {
  public List<Integer> spiralOrder(int[][] matrix) {
    if (!matrix.length) return new ArrayList<>();
    int rows = matrix.length;
    int cols = matrix[0].length;
    List<Integer> out = new ArrayList<>();
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    int dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
    int d = 0;
    int r = 0;
    int c = 0;
    for (int k = 0; k < rows * cols; k++) {
      out.add(matrix[r][c]);
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
}
