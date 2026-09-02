// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For each 1, BFS with a fresh visited matrix until you hit a 0. You re-walk the same cells from many starts.

function updateMatrix(mat) {
  const rows = mat.length, cols = mat[0].length;
  const out = Array.from({ length: rows }, function () { return Array(cols).fill(0); });
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

  function dist(sr, sc) {
    const seen = Array.from({ length: rows }, function () { return Array(cols).fill(false); });
    const q = [[sr, sc, 0]];
    seen[sr][sc] = true;
    while (q.length) {
      const cur = q.shift();
      const r = cur[0], c = cur[1], d = cur[2];
      if (mat[r][c] === 0) return d;
      for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || seen[nr][nc]) continue;
        seen[nr][nc] = true;
        q.push([nr, nc, d + 1]);
      }
    }
    return 0;
  }

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (mat[r][c] !== 0) out[r][c] = dist(r, c);
    }
  }
  return out;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Multi-source BFS from all zeros. Each 1 is reached first by its nearest 0. One visit per cell.

function updateMatrix(mat) {
  const rows = mat.length, cols = mat[0].length;
  const inf = rows * cols;
  const dist = Array.from({ length: rows }, function () { return Array(cols).fill(inf); });
  const q = [];
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (mat[r][c] === 0) {
        dist[r][c] = 0;
        q.push([r, c]);
      }
    }
  }
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
  while (q.length) {
    const cur = q.shift();
    const r = cur[0], c = cur[1];
    for (let i = 0; i < 4; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
      if (dist[nr][nc] <= dist[r][c] + 1) continue;
      dist[nr][nc] = dist[r][c] + 1;
      q.push([nr, nc]);
    }
  }
  return dist;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(1)
// Two DP sweeps. First pass uses top and left (already processed). Second pass uses bottom and right. You can write into the output matrix only; extra space is O(1) besides the answer. Same linear time, no queue.

function updateMatrix(mat) {
  const rows = mat.length, cols = mat[0].length;
  const inf = rows + cols;
  const dist = Array.from({ length: rows }, function (_, r) {
    return mat[r].map(function (v) { return v === 0 ? 0 : inf; });
  });
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (r > 0) dist[r][c] = Math.min(dist[r][c], dist[r - 1][c] + 1);
      if (c > 0) dist[r][c] = Math.min(dist[r][c], dist[r][c - 1] + 1);
    }
  }
  for (let r = rows - 1; r >= 0; r--) {
    for (let c = cols - 1; c >= 0; c--) {
      if (r + 1 < rows) dist[r][c] = Math.min(dist[r][c], dist[r + 1][c] + 1);
      if (c + 1 < cols) dist[r][c] = Math.min(dist[r][c], dist[r][c + 1] + 1);
    }
  }
  return dist;
}
