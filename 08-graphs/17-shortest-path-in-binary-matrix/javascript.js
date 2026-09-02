// Method 1: Brute
// Time: O(8^{n²}) | Space: O(n²)
// DFS every simple path with a copied visited matrix. Keep the shortest length. Correct on a 2x2, exponential on a 20x20.

function shortestPathBinaryMatrix(grid) {
  const n = grid.length;
  if (grid[0][0] || grid[n - 1][n - 1]) return -1;
  let best = Infinity;
  const dirs = [];
  for (let dr = -1; dr <= 1; dr++) {
    for (let dc = -1; dc <= 1; dc++) {
      if (dr || dc) dirs.push([dr, dc]);
    }
  }
  function dfs(r, c, dist, seen) {
    if (dist >= best) return;
    if (r === n - 1 && c === n - 1) { best = dist; return; }
    for (let i = 0; i < dirs.length; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
      if (grid[nr][nc] !== 0 || seen[nr][nc]) continue;
      const copy = seen.map(function (row) { return row.slice(); });
      copy[nr][nc] = true;
      dfs(nr, nc, dist + 1, copy);
    }
  }
  const seen = Array.from({ length: n }, function () { return Array(n).fill(false); });
  seen[0][0] = true;
  dfs(0, 0, 1, seen);
  return best === Infinity ? -1 : best;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// BFS from (0,0). First time you pop the end cell is the shortest length. Mark cells when you push so the queue stays small. 8 neighbors.

function shortestPathBinaryMatrix(grid) {
  const n = grid.length;
  if (grid[0][0] || grid[n - 1][n - 1]) return -1;
  const q = [[0, 0, 1]];
  grid[0][0] = 1;
  const dirs = [];
  for (let dr = -1; dr <= 1; dr++) {
    for (let dc = -1; dc <= 1; dc++) {
      if (dr || dc) dirs.push([dr, dc]);
    }
  }
  while (q.length) {
    const cur = q.shift();
    const r = cur[0], c = cur[1], d = cur[2];
    if (r === n - 1 && c === n - 1) return d;
    for (let i = 0; i < dirs.length; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
      if (grid[nr][nc] !== 0) continue;
      grid[nr][nc] = 1;
      q.push([nr, nc, d + 1]);
    }
  }
  return -1;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Bidirectional BFS from start and end. When a neighbor sits in the other frontier, the two searches met. Fewer cells expanded on large open maps. Same worst-case O(n²).

function shortestPathBinaryMatrix(grid) {
  const n = grid.length;
  if (grid[0][0] || grid[n - 1][n - 1]) return -1;
  if (n === 1) return 1;
  const dirs = [];
  for (let dr = -1; dr <= 1; dr++) {
    for (let dc = -1; dc <= 1; dc++) {
      if (dr || dc) dirs.push([dr, dc]);
    }
  }
  function key(r, c) { return r * n + c; }
  let q1 = [[0, 0]];
  let q2 = [[n - 1, n - 1]];
  let d1 = {};
  let d2 = {};
  d1[key(0, 0)] = 1;
  d2[key(n - 1, n - 1)] = 1;

  while (q1.length && q2.length) {
    if (q1.length > q2.length) {
      const tq = q1; q1 = q2; q2 = tq;
      const td = d1; d1 = d2; d2 = td;
    }
    const next = [];
    for (let i = 0; i < q1.length; i++) {
      const r = q1[i][0], c = q1[i][1];
      const id = key(r, c);
      for (let k = 0; k < dirs.length; k++) {
        const nr = r + dirs[k][0], nc = c + dirs[k][1];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
        if (grid[nr][nc] !== 0) continue;
        const nid = key(nr, nc);
        if (d1[nid] !== undefined) continue;
        if (d2[nid] !== undefined) return d1[id] + d2[nid];
        d1[nid] = d1[id] + 1;
        next.push([nr, nc]);
      }
    }
    q1 = next;
  }
  return -1;
}
