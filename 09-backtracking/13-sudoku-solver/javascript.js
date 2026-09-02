// Method 1: Brute
// Time: O(9^{e}) | Space: O(e)
// e empty cells. Each guess clones the board and scans from scratch. Extra copies on every node. Correct but memory-heavy.

function solveSudoku(board) {
  function valid(b, r, c, ch) {
    for (let i = 0; i < 9; i++) {
      if (b[r][i] === ch || b[i][c] === ch) return false;
      const br = Math.floor(r / 3) * 3 + Math.floor(i / 3);
      const bc = Math.floor(c / 3) * 3 + (i % 3);
      if (b[br][bc] === ch) return false;
    }
    return true;
  }
  function go(b) {
    for (let r = 0; r < 9; r++) {
      for (let c = 0; c < 9; c++) {
        if (b[r][c] !== ".") continue;
        for (let d = 1; d <= 9; d++) {
          const ch = String(d);
          if (!valid(b, r, c, ch)) continue;
          const copy = b.map(function (row) { return row.slice(); });
          copy[r][c] = ch;
          if (go(copy)) {
            for (let i = 0; i < 9; i++) b[i] = copy[i];
            return true;
          }
        }
        return false;
      }
    }
    return true;
  }
  go(board);
}


// Method 2: Optimal
// Time: O(9^{e}) | Space: O(e)
// Write a digit in place, recurse, write '.'. isValid scans the row, column, and box. No extra boards. First empty cell, left to right.

function solveSudoku(board) {
  function valid(r, c, ch) {
    for (let i = 0; i < 9; i++) {
      if (board[r][i] === ch || board[i][c] === ch) return false;
      const br = Math.floor(r / 3) * 3 + Math.floor(i / 3);
      const bc = Math.floor(c / 3) * 3 + (i % 3);
      if (board[br][bc] === ch) return false;
    }
    return true;
  }
  function go() {
    for (let r = 0; r < 9; r++) {
      for (let c = 0; c < 9; c++) {
        if (board[r][c] !== ".") continue;
        for (let d = 1; d <= 9; d++) {
          const ch = String(d);
          if (!valid(r, c, ch)) continue;
          board[r][c] = ch;
          if (go()) return true;
          board[r][c] = ".";
        }
        return false;
      }
    }
    return true;
  }
  go();
}


// Method 3: More optimal
// Time: O(9^{e}) | Space: O(e)
// row[], col[], box[] bitmasks. Pick the empty cell with the fewest remaining digits (MRV) so dead ends die sooner. Toggle bits instead of scanning 9 cells.

function solveSudoku(board) {
  const row = Array(9).fill(0), col = Array(9).fill(0), box = Array(9).fill(0);
  const empty = [];
  for (let r = 0; r < 9; r++) for (let c = 0; c < 9; c++) {
    if (board[r][c] === ".") empty.push([r, c]);
    else {
      const bit = 1 << (board[r][c].charCodeAt(0) - 49);
      row[r] |= bit; col[c] |= bit; box[Math.floor(r / 3) * 3 + Math.floor(c / 3)] |= bit;
    }
  }
  function popcount(x) { let n = 0; while (x) { x &= x - 1; n++; } return n; }
  function go(k) {
    if (k === empty.length) return true;
    let best = k, bestN = 10;
    for (let i = k; i < empty.length; i++) {
      const r = empty[i][0], c = empty[i][1];
      const used = row[r] | col[c] | box[Math.floor(r / 3) * 3 + Math.floor(c / 3)];
      const n = 9 - popcount(used);
      if (n < bestN) { bestN = n; best = i; }
    }
    const tmp = empty[k]; empty[k] = empty[best]; empty[best] = tmp;
    const r = empty[k][0], c = empty[k][1], b = Math.floor(r / 3) * 3 + Math.floor(c / 3);
    let avail = ((1 << 9) - 1) ^ (row[r] | col[c] | box[b]);
    while (avail) {
      const bit = avail & -avail;
      avail ^= bit;
      let d = 1, x = bit;
      while (x > 1) { x >>= 1; d++; }
      board[r][c] = String(d);
      row[r] |= bit; col[c] |= bit; box[b] |= bit;
      if (go(k + 1)) return true;
      row[r] ^= bit; col[c] ^= bit; box[b] ^= bit;
      board[r][c] = ".";
    }
    return false;
  }
  go(0);
}
