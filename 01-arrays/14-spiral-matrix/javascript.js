// Method 1: Brute
// Time: O(m·n) | Space: O(m·n)
// You still visit each cell once, but a boolean grid of the same size is extra memory.
// How it works: start at (0,0) facing right. If the next cell is out of bounds or visited, turn right. Push each value.

function spiralOrder(matrix) {
  if (!matrix.length) return [];
  const rows = matrix.length;
  const cols = matrix[0].length;
  const seen = [];
  for (let r = 0; r < rows; r++) seen.push(new Array(cols).fill(false));
  const dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  const out = [];
  let r = 0;
  let c = 0;
  let d = 0;
  for (let k = 0; k < rows * cols; k++) {
    out.push(matrix[r][c]);
    seen[r][c] = true;
    const nr = r + dirs[d][0];
    const nc = c + dirs[d][1];
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

function spiralOrder(matrix) {
  if (!matrix.length) return [];
  const out = [];
  let top = 0;
  let bottom = matrix.length - 1;
  let left = 0;
  let right = matrix[0].length - 1;
  while (top <= bottom && left <= right) {
    for (let c = left; c <= right; c++) out.push(matrix[top][c]);
    top++;
    for (let r = top; r <= bottom; r++) out.push(matrix[r][right]);
    right--;
    if (top <= bottom) {
      for (let c = right; c >= left; c--) out.push(matrix[bottom][c]);
      bottom--;
    }
    if (left <= right) {
      for (let r = bottom; r >= top; r--) out.push(matrix[r][left]);
      left++;
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(m·n) | Space: O(1)
// Same bounds idea in one counted loop: visit exactly rows*cols cells, turn when the next step would leave the remaining rectangle.
// How it works: after a turn, shrink the bound you just finished (top, right, bottom, or left) so the next lap is the inner layer.

function spiralOrder(matrix) {
  if (!matrix.length) return [];
  const rows = matrix.length;
  const cols = matrix[0].length;
  const out = [];
  let top = 0;
  let bottom = rows - 1;
  let left = 0;
  let right = cols - 1;
  const dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]];
  let d = 0;
  let r = 0;
  let c = 0;
  for (let k = 0; k < rows * cols; k++) {
    out.push(matrix[r][c]);
    const nr = r + dirs[d][0];
    const nc = c + dirs[d][1];
    if (nr < top || nr > bottom || nc < left || nc > right) {
      if (d === 0) top++;
      else if (d === 1) right--;
      else if (d === 2) bottom--;
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
