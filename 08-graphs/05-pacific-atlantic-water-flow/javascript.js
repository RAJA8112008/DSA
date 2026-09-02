// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// From every cell, DFS toward lower/equal neighbors with a fresh visited copy. Check if that walk hits a Pacific border and an Atlantic border. Extra copies plus a full search per cell.

function pacificAtlantic(heights) {
  const rows = heights.length, cols = heights[0].length;
  const ans = [];
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

  function reaches(sr, sc) {
    const seen = Array.from({ length: rows }, function () {
      return Array(cols).fill(false);
    });
    const stack = [[sr, sc]];
    seen[sr][sc] = true;
    let pac = false, atl = false;
    while (stack.length) {
      const cur = stack.pop();
      const r = cur[0], c = cur[1];
      if (r === 0 || c === 0) pac = true;
      if (r === rows - 1 || c === cols - 1) atl = true;
      if (pac && atl) return true;
      for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
        if (seen[nr][nc] || heights[nr][nc] > heights[r][c]) continue;
        seen[nr][nc] = true;
        stack.push([nr, nc]);
      }
    }
    return pac && atl;
  }

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (reaches(r, c)) ans.push([r, c]);
    }
  }
  return ans;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Reverse the flow: water climbs to equal or higher cells. DFS from all Pacific border cells, then from all Atlantic border cells. A cell in both visited sets is an answer. Each cell is processed a constant number of times.

function pacificAtlantic(heights) {
  const rows = heights.length, cols = heights[0].length;
  const pac = Array.from({ length: rows }, function () { return Array(cols).fill(false); });
  const atl = Array.from({ length: rows }, function () { return Array(cols).fill(false); });
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

  function dfs(r, c, seen) {
    seen[r][c] = true;
    for (let i = 0; i < 4; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
      if (seen[nr][nc] || heights[nr][nc] < heights[r][c]) continue;
      dfs(nr, nc, seen);
    }
  }

  for (let r = 0; r < rows; r++) {
    dfs(r, 0, pac);
    dfs(r, cols - 1, atl);
  }
  for (let c = 0; c < cols; c++) {
    dfs(0, c, pac);
    dfs(rows - 1, c, atl);
  }

  const ans = [];
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (pac[r][c] && atl[r][c]) ans.push([r, c]);
    }
  }
  return ans;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Same reverse idea with BFS from both oceans. No recursion on a huge grid. Complexity is still linear in cells. This is the interview upgrade when they worry about stack depth.

function pacificAtlantic(heights) {
  const rows = heights.length, cols = heights[0].length;
  const pac = Array.from({ length: rows }, function () { return Array(cols).fill(false); });
  const atl = Array.from({ length: rows }, function () { return Array(cols).fill(false); });
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

  function bfs(q, seen) {
    while (q.length) {
      const cur = q.shift();
      const r = cur[0], c = cur[1];
      for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
        if (seen[nr][nc] || heights[nr][nc] < heights[r][c]) continue;
        seen[nr][nc] = true;
        q.push([nr, nc]);
      }
    }
  }

  const qp = [], qa = [];
  for (let r = 0; r < rows; r++) {
    pac[r][0] = true; qp.push([r, 0]);
    atl[r][cols - 1] = true; qa.push([r, cols - 1]);
  }
  for (let c = 0; c < cols; c++) {
    pac[0][c] = true; qp.push([0, c]);
    atl[rows - 1][c] = true; qa.push([rows - 1, c]);
  }
  bfs(qp, pac);
  bfs(qa, atl);

  const ans = [];
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (pac[r][c] && atl[r][c]) ans.push([r, c]);
    }
  }
  return ans;
}
