// Method 1: Brute
// Time: O(n * n!) | Space: O(n^2)
// Generate every permutation of columns with extra copies. After a full permutation, scan every pair for a shared diagonal. Most permutations fail only at the end.

function solveNQueens(n) {
  const ans = [];
  function ok(cols) {
    for (let i = 0; i < n; i++) {
      for (let j = i + 1; j < n; j++) {
        if (Math.abs(i - j) === Math.abs(cols[i] - cols[j])) return false;
      }
    }
    return true;
  }
  function go(left, cols) {
    if (left.length === 0) {
      if (!ok(cols)) return;
      const board = [];
      for (let r = 0; r < n; r++) {
        let row = "";
        for (let c = 0; c < n; c++) row += c === cols[r] ? "Q" : ".";
        board.push(row);
      }
      ans.push(board);
      return;
    }
    for (let i = 0; i < left.length; i++) {
      go(left.slice(0, i).concat(left.slice(i + 1)), cols.concat([left[i]]));
    }
  }
  const left = [];
  for (let c = 0; c < n; c++) left.push(c);
  go(left, []);
  return ans;
}


// Method 2: Optimal
// Time: O(n!) | Space: O(n^2)
// Place one queen per row. col[], d1[], d2[] mark attacks. If the square is free, mark, recurse row+1, unmark. Failures die as soon as a row has no square.

function solveNQueens(n) {
  const ans = [];
  const board = Array.from({ length: n }, function () { return Array(n).fill("."); });
  const col = Array(n).fill(0);
  const d1 = Array(2 * n).fill(0);
  const d2 = Array(2 * n).fill(0);
  function go(row) {
    if (row === n) {
      ans.push(board.map(function (r) { return r.join(""); }));
      return;
    }
    for (let c = 0; c < n; c++) {
      if (col[c] || d1[row - c + n] || d2[row + c]) continue;
      col[c] = d1[row - c + n] = d2[row + c] = 1;
      board[row][c] = "Q";
      go(row + 1);
      board[row][c] = ".";
      col[c] = d1[row - c + n] = d2[row + c] = 0;
    }
  }
  go(0);
  return ans;
}


// Method 3: More optimal
// Time: O(n!) | Space: O(n^2)
// cols, diag, anti as bitmasks. available bits are the free columns. Take the lowest set bit, recurse with shifted diagonals. Same search, O(1) updates.

function solveNQueens(n) {
  const ans = [];
  const board = Array.from({ length: n }, function () { return Array(n).fill("."); });
  function go(row, cols, d1, d2) {
    if (row === n) {
      ans.push(board.map(function (r) { return r.join(""); }));
      return;
    }
    let avail = ((1 << n) - 1) & ~(cols | d1 | d2);
    while (avail) {
      const bit = avail & -avail;
      avail ^= bit;
      let c = 0, x = bit;
      while (x > 1) { x >>= 1; c++; }
      board[row][c] = "Q";
      go(row + 1, cols | bit, (d1 | bit) << 1, (d2 | bit) >> 1);
      board[row][c] = ".";
    }
  }
  go(0, 0, 0, 0);
  return ans;
}
