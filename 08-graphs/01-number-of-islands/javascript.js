// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For every land cell we copy a full visited matrix and DFS that island. The extra copies are wasted work. Correct, but memory traffic is huge on a large grid.

function numIslands(grid) {
  const rows = grid.length;
  if (!rows) return 0;
  const cols = grid[0].length;
  const global = grid.map(function () {
    return Array(cols).fill(false);
  });
  let count = 0;
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] !== "1" || global[r][c]) continue;
      count++;
      // extra visited copy for this island walk
      const seen = global.map(function (row) { return row.slice(); });
      const stack = [[r, c]];
      seen[r][c] = true;
      while (stack.length) {
        const cell = stack.pop();
        const x = cell[0], y = cell[1];
        global[x][y] = true;
        for (let i = 0; i < 4; i++) {
          const nx = x + dirs[i][0];
          const ny = y + dirs[i][1];
          if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) continue;
          if (grid[nx][ny] !== "1" || seen[nx][ny]) continue;
          seen[nx][ny] = true;
          stack.push([nx, ny]);
        }
      }
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// One DFS (or BFS) per island. Mutating land to water is the visited mark, so we never copy a matrix. Each cell is entered a constant number of times.

function numIslands(grid) {
  const rows = grid.length;
  if (!rows) return 0;
  const cols = grid[0].length;
  let count = 0;

  function dfs(r, c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    if (grid[r][c] !== "1") return;
    grid[r][c] = "0";
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
  }

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === "1") {
        count++;
        dfs(r, c);
      }
    }
  }
  return count;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Union-Find treats each land cell as a node. You only union with the right and down land neighbor, so each edge is processed once. The island count is how many land roots remain. No recursion.

function numIslands(grid) {
  const rows = grid.length;
  if (!rows) return 0;
  const cols = grid[0].length;
  const n = rows * cols;
  const parent = Array.from({ length: n }, function (_, i) { return i; });
  const rank = Array(n).fill(0);
  let islands = 0;

  function id(r, c) { return r * cols + c; }
  function find(x) {
    while (parent[x] !== x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  function union(a, b) {
    let x = find(a), y = find(b);
    if (x === y) return;
    if (rank[x] < rank[y]) { const t = x; x = y; y = t; }
    parent[y] = x;
    if (rank[x] === rank[y]) rank[x]++;
    islands--;
  }

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] !== "1") continue;
      islands++;
      if (c + 1 < cols && grid[r][c + 1] === "1") union(id(r, c), id(r, c + 1));
      if (r + 1 < rows && grid[r + 1][c] === "1") union(id(r, c), id(r + 1, c));
    }
  }
  return islands;
}
