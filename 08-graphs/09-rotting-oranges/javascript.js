// Method 1: Brute
// Time: O((rc)²) | Space: O(rc)
// Each minute, copy the grid and rot any fresh cell that touches a 2. Repeat until nothing changes. You scan the whole grid once per minute, up to rc minutes.

function orangesRotting(grid) {
  const rows = grid.length, cols = grid[0].length;
  function countFresh(g) {
    let n = 0;
    for (let r = 0; r < rows; r++) {
      for (let c = 0; c < cols; c++) if (g[r][c] === 1) n++;
    }
    return n;
  }
  let minutes = 0;
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
  while (true) {
    const next = grid.map(function (row) { return row.slice(); });
    let changed = false;
    for (let r = 0; r < rows; r++) {
      for (let c = 0; c < cols; c++) {
        if (grid[r][c] !== 2) continue;
        for (let i = 0; i < 4; i++) {
          const nr = r + dirs[i][0], nc = c + dirs[i][1];
          if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
          if (grid[nr][nc] !== 1) continue;
          next[nr][nc] = 2;
          changed = true;
        }
      }
    }
    if (!changed) break;
    grid = next;
    minutes++;
  }
  return countFresh(grid) ? -1 : minutes;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Put every rotten orange in the queue at minute 0. BFS infects fresh neighbors. The last minute you used is the answer. If any 1 remains, return -1.

function orangesRotting(grid) {
  const rows = grid.length, cols = grid[0].length;
  const q = [];
  let fresh = 0;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === 2) q.push([r, c, 0]);
      if (grid[r][c] === 1) fresh++;
    }
  }
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
  let minutes = 0;
  while (q.length) {
    const cur = q.shift();
    const r = cur[0], c = cur[1], t = cur[2];
    minutes = t;
    for (let i = 0; i < 4; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
      if (grid[nr][nc] !== 1) continue;
      grid[nr][nc] = 2;
      fresh--;
      q.push([nr, nc, t + 1]);
    }
  }
  return fresh === 0 ? minutes : -1;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Same multi-source BFS, but the grid itself stores time as 2 + minutes. No third tuple field. Space is still the queue. Linear in cells.

function orangesRotting(grid) {
  const rows = grid.length, cols = grid[0].length;
  const q = [];
  let fresh = 0;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === 2) q.push([r, c]);
      else if (grid[r][c] === 1) fresh++;
    }
  }
  if (fresh === 0) return 0;
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
  let minutes = 0;
  while (q.length) {
    const size = q.length;
    let infected = false;
    for (let s = 0; s < size; s++) {
      const cur = q.shift();
      const r = cur[0], c = cur[1];
      for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
        if (grid[nr][nc] !== 1) continue;
        grid[nr][nc] = 2;
        fresh--;
        infected = true;
        q.push([nr, nc]);
      }
    }
    if (infected) minutes++;
  }
  return fresh === 0 ? minutes : -1;
}
