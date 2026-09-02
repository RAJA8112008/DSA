// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For each O, copy a visited matrix and DFS. If that blob never hits a border, flip those cells. Repeated walks over the same region.

function solve(board) {
  const rows = board.length;
  if (!rows) return;
  const cols = board[0].length;
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];

  function blob(sr, sc) {
    const seen = Array.from({ length: rows }, function () { return Array(cols).fill(false); });
    const cells = [];
    const q = [[sr, sc]];
    seen[sr][sc] = true;
    let border = false;
    while (q.length) {
      const cur = q.pop();
      const r = cur[0], c = cur[1];
      cells.push([r, c]);
      if (r === 0 || c === 0 || r === rows - 1 || c === cols - 1) border = true;
      for (let i = 0; i < 4; i++) {
        const nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
        if (seen[nr][nc] || board[nr][nc] !== "O") continue;
        seen[nr][nc] = true;
        q.push([nr, nc]);
      }
    }
    return { cells: cells, border: border };
  }

  const flipped = Array.from({ length: rows }, function () { return Array(cols).fill(false); });
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (board[r][c] !== "O" || flipped[r][c]) continue;
      const info = blob(r, c);
      if (!info.border) {
        for (let i = 0; i < info.cells.length; i++) {
          const cell = info.cells[i];
          board[cell[0]][cell[1]] = "X";
        }
      }
      for (let i = 0; i < info.cells.length; i++) {
        flipped[info.cells[i][0]][info.cells[i][1]] = true;
      }
    }
  }
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// DFS/BFS from every border O and mark those cells (for example '#'). Then walk the board: leftover O is surrounded and becomes X; '#' is restored to O.

function solve(board) {
  const rows = board.length;
  if (!rows) return;
  const cols = board[0].length;

  function dfs(r, c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    if (board[r][c] !== "O") return;
    board[r][c] = "#";
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
  }

  for (let r = 0; r < rows; r++) {
    dfs(r, 0);
    dfs(r, cols - 1);
  }
  for (let c = 0; c < cols; c++) {
    dfs(0, c);
    dfs(rows - 1, c);
  }
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (board[r][c] === "O") board[r][c] = "X";
      else if (board[r][c] === "#") board[r][c] = "O";
    }
  }
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Union-Find. Dummy node DUMMY represents 'touches border'. Union every O with its O neighbors, and union border O with DUMMY. Then flip O whose root is not DUMMY. No recursion.

function solve(board) {
  const rows = board.length;
  if (!rows) return;
  const cols = board[0].length;
  const DUMMY = rows * cols;
  const parent = Array.from({ length: DUMMY + 1 }, function (_, i) { return i; });
  function find(x) {
    while (parent[x] !== x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  function union(a, b) {
    const x = find(a), y = find(b);
    if (x !== y) parent[y] = x;
  }
  function id(r, c) { return r * cols + c; }
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (board[r][c] !== "O") continue;
      if (r === 0 || c === 0 || r === rows - 1 || c === cols - 1) union(id(r, c), DUMMY);
      if (r + 1 < rows && board[r + 1][c] === "O") union(id(r, c), id(r + 1, c));
      if (c + 1 < cols && board[r][c + 1] === "O") union(id(r, c), id(r, c + 1));
    }
  }
  const dummyRoot = find(DUMMY);
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (board[r][c] === "O" && find(id(r, c)) !== dummyRoot) board[r][c] = "X";
    }
  }
}
