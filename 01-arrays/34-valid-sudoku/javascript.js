// Method 1: Brute
// Time: O(1) for 9x9 | Space: O(1)
// For every filled cell, walk its row, column, and 3x3 box looking for the same digit elsewhere. On a 9x9 this is constant, but the nested scans are noisy.

function isValidSudoku(board) {
  function ok(r, c, d) {
    for (let i = 0; i < 9; i++) {
      if (i !== c && board[r][i] === d) return false;
      if (i !== r && board[i][c] === d) return false;
    }
    const br = Math.floor(r / 3) * 3, bc = Math.floor(c / 3) * 3;
    for (let i = 0; i < 3; i++) {
      for (let j = 0; j < 3; j++) {
        const rr = br + i, cc = bc + j;
        if ((rr !== r || cc !== c) && board[rr][cc] === d) return false;
      }
    }
    return true;
  }
  for (let r = 0; r < 9; r++) {
    for (let c = 0; c < 9; c++) {
      if (board[r][c] === ".") continue;
      if (!ok(r, c, board[r][c])) return false;
    }
  }
  return true;
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// Nine sets for rows, nine for columns, nine for boxes. Box id is (r/3)*3 + c/3. Fail on the first repeat.

function isValidSudoku(board) {
    const row = Array.from({ length: 9 }, function () { return Object.create(null); });
    const col = Array.from({ length: 9 }, function () { return Object.create(null); });
    const box = Array.from({ length: 9 }, function () { return Object.create(null); });
    for (let r = 0; r < 9; r++) {
      for (let c = 0; c < 9; c++) {
        const d = board[r][c];
        if (d === ".") continue;
        const b = Math.floor(r / 3) * 3 + Math.floor(c / 3);
        if (row[r][d] || col[c][d] || box[b][d]) return false;
        row[r][d] = col[c][d] = box[b][d] = true;
      }
    }
    return true;
  }


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Nine ints for rows, columns, boxes. Bit (1 << digit) marks a used number. A second hit on the same bit is a duplicate. Same logic, no hash sets.

function isValidSudoku(board) {
  const row = Array(9).fill(0);
  const col = Array(9).fill(0);
  const box = Array(9).fill(0);
  for (let r = 0; r < 9; r++) {
    for (let c = 0; c < 9; c++) {
      const ch = board[r][c];
      if (ch === ".") continue;
      const bit = 1 << (ch.charCodeAt(0) - 49);
      const b = Math.floor(r / 3) * 3 + Math.floor(c / 3);
      if ((row[r] & bit) || (col[c] & bit) || (box[b] & bit)) return false;
      row[r] |= bit;
      col[c] |= bit;
      box[b] |= bit;
    }
  }
  return true;
}
