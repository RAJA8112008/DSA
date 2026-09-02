// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Same path tree as Unique Paths, with extra dead ends on stones. No cache, so overlapping cells are walked many times.

function uniquePathsWithObstacles(grid) {
  const rows = grid.length;
  const cols = grid[0].length;
  function go(r, c) {
    if (r >= rows || c >= cols || grid[r][c] === 1) return 0;
    if (r === rows - 1 && c === cols - 1) return 1;
    return go(r + 1, c) + go(r, c + 1);
  }
  return go(0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// Each cell is filled once. Stones store 0. Start is 1 only if it is free. Neighbors that do not exist contribute 0. Classic 2D DP on a grid.

function uniquePathsWithObstacles(grid) {
  const rows = grid.length;
  const cols = grid[0].length;
  if (grid[0][0] === 1) return 0;
  const ways = Array.from({ length: rows }, function () {
    return Array(cols).fill(0);
  });
  ways[0][0] = 1;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === 1) {
        ways[r][c] = 0;
        continue;
      }
      if (r === 0 && c === 0) continue;
      const up = r > 0 ? ways[r - 1][c] : 0;
      const left = c > 0 ? ways[r][c - 1] : 0;
      ways[r][c] = up + left;
    }
  }
  return ways[rows - 1][cols - 1];
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// Reuse one row of width cols. A stone zeros ways[c]. A free cell adds the left cell in this row (already updated) onto the old ways[c] (the cell above). Same time, linear extra memory.

function uniquePathsWithObstacles(grid) {
  const rows = grid.length;
  const cols = grid[0].length;
  const ways = Array(cols).fill(0);
  ways[0] = grid[0][0] === 1 ? 0 : 1;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === 1) ways[c] = 0;
      else if (c > 0) ways[c] += ways[c - 1];
    }
  }
  return ways[cols - 1];
}
