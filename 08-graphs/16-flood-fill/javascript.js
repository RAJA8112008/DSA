// Method 1: Brute
// Time: O(rc) | Space: O(rc)
// DFS with a brand-new visited matrix copy even though one matrix is enough. Extra memory, same walk. Shows the 'copy visited' habit you should drop.

function floodFill(image, sr, sc, color) {
  const rows = image.length, cols = image[0].length;
  const old = image[sr][sc];
  if (old === color) return image;
  const seen = image.map(function (row) {
    return row.map(function () { return false; });
  });
  function dfs(r, c, vis) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    if (vis[r][c] || image[r][c] !== old) return;
    const copy = vis.map(function (row) { return row.slice(); });
    copy[r][c] = true;
    vis[r][c] = true;
    image[r][c] = color;
    dfs(r + 1, c, copy);
    dfs(r - 1, c, copy);
    dfs(r, c + 1, copy);
    dfs(r, c - 1, copy);
  }
  dfs(sr, sc, seen);
  return image;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// DFS from the start. Painting to the new color is the visited mark when old !== color. Each cell in the blob is painted once.

function floodFill(image, sr, sc, color) {
  const old = image[sr][sc];
  if (old === color) return image;
  const rows = image.length, cols = image[0].length;
  function dfs(r, c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    if (image[r][c] !== old) return;
    image[r][c] = color;
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
  }
  dfs(sr, sc);
  return image;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// BFS with a queue. Same linear bound, no recursive stack. Prefer this on a huge image so the call stack cannot overflow.

function floodFill(image, sr, sc, color) {
  const old = image[sr][sc];
  if (old === color) return image;
  const rows = image.length, cols = image[0].length;
  const q = [[sr, sc]];
  image[sr][sc] = color;
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
  while (q.length) {
    const cur = q.shift();
    const r = cur[0], c = cur[1];
    for (let i = 0; i < 4; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
      if (image[nr][nc] !== old) continue;
      image[nr][nc] = color;
      q.push([nr, nc]);
    }
  }
  return image;
}
