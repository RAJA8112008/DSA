// Method 1: Brute
// Time: O(4^{n^2}) | Space: O(n^2)
// Each step clones visited and concatenates a new path string. Exponential walks, extra copies at every node. Fine on n = 2, painful on n = 5.

function ratInMaze(grid) {
  const n = grid.length;
  const ans = [];
  const dirs = [[1, 0, "D"], [0, -1, "L"], [0, 1, "R"], [-1, 0, "U"]];
  function go(r, c, path, seen) {
    if (r === n - 1 && c === n - 1) { ans.push(path); return; }
    for (let i = 0; i < 4; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
      if (grid[nr][nc] === 0 || seen[nr][nc]) continue;
      const copy = seen.map(function (row) { return row.slice(); });
      copy[nr][nc] = true;
      go(nr, nc, path + dirs[i][2], copy);
    }
  }
  if (!n || grid[0][0] === 0) return ans;
  const seen = grid.map(function () { return Array(n).fill(false); });
  seen[0][0] = true;
  go(0, 0, "", seen);
  return ans;
}


// Method 2: Optimal
// Time: O(4^{n^2}) | Space: O(n^2)
// Mark grid[r][c] = 0 (or a visited flag), append D/L/R/U, recurse, restore 1. One path buffer. Copy the string only when you hit the end.

function ratInMaze(grid) {
  const n = grid.length;
  const ans = [];
  const dirs = [[1, 0, "D"], [0, -1, "L"], [0, 1, "R"], [-1, 0, "U"]];
  function go(r, c, path) {
    if (r === n - 1 && c === n - 1) { ans.push(path.join("")); return; }
    for (let i = 0; i < 4; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
      if (grid[nr][nc] === 0) continue;
      grid[nr][nc] = 0;
      path.push(dirs[i][2]);
      go(nr, nc, path);
      path.pop();
      grid[nr][nc] = 1;
    }
  }
  if (!n || grid[0][0] === 0) return ans;
  grid[0][0] = 0;
  go(0, 0, []);
  grid[0][0] = 1;
  return ans;
}


// Method 3: More optimal
// Time: O(4^{n^2}) | Space: O(n^2)
// Same mark/unmark, plus skip a blocked start immediately. Try directions in DLRU order so the output is already sorted, no extra sort. Dead walls never enter the stack.

function ratInMaze(grid) {
  const n = grid.length;
  const ans = [];
  if (!n || grid[0][0] === 0 || grid[n - 1][n - 1] === 0) return ans;
  const dirs = [[1, 0, "D"], [0, -1, "L"], [0, 1, "R"], [-1, 0, "U"]];
  function go(r, c, path) {
    if (r === n - 1 && c === n - 1) { ans.push(path.join("")); return; }
    for (let i = 0; i < 4; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
      if (grid[nr][nc] !== 1) continue;
      grid[nr][nc] = 0;
      path.push(dirs[i][2]);
      go(nr, nc, path);
      path.pop();
      grid[nr][nc] = 1;
    }
  }
  grid[0][0] = 0;
  go(0, 0, []);
  grid[0][0] = 1;
  return ans;
}
