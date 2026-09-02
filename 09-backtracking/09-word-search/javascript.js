// Method 1: Brute
// Time: O(r c * 4^L) | Space: O(r c * L)
// Every recursive step clones the whole visited grid. Correct, but memory traffic is huge. L is the word length. 4^L walks from each start.

function exist(board, word) {
  const rows = board.length, cols = board[0].length;
  function dfs(r, c, k, seen) {
    if (k === word.length) return true;
    if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
    if (seen[r][c] || board[r][c] !== word[k]) return false;
    const copy = seen.map(function (row) { return row.slice(); });
    copy[r][c] = true;
    return dfs(r + 1, c, k + 1, copy) || dfs(r - 1, c, k + 1, copy) ||
           dfs(r, c + 1, k + 1, copy) || dfs(r, c - 1, k + 1, copy);
  }
  const blank = board.map(function () { return Array(cols).fill(false); });
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (dfs(r, c, 0, blank)) return true;
    }
  }
  return false;
}


// Method 2: Optimal
// Time: O(r c * 4^L) | Space: O(L)
// Mark the cell as '#' (or a visited flag), recurse four ways, restore the letter. One board, undo after each branch. Stack is O(L).

function exist(board, word) {
  const rows = board.length, cols = board[0].length;
  function dfs(r, c, k) {
    if (k === word.length) return true;
    if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
    if (board[r][c] !== word[k]) return false;
    const ch = board[r][c];
    board[r][c] = "#";
    const ok = dfs(r + 1, c, k + 1) || dfs(r - 1, c, k + 1) ||
               dfs(r, c + 1, k + 1) || dfs(r, c - 1, k + 1);
    board[r][c] = ch;
    return ok;
  }
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (dfs(r, c, 0)) return true;
    }
  }
  return false;
}


// Method 3: More optimal
// Time: O(r c * 4^L) | Space: O(L)
// Count letters first. If the board cannot supply a letter, return false. Search from the rarer end of the word. Return true on the first hit so you do not walk the rest of the grid.

function exist(board, word) {
  const rows = board.length, cols = board[0].length;
  const need = {};
  const have = {};
  for (let i = 0; i < word.length; i++) need[word[i]] = (need[word[i]] || 0) + 1;
  for (let r = 0; r < rows; r++) for (let c = 0; c < cols; c++) have[board[r][c]] = (have[board[r][c]] || 0) + 1;
  for (const ch in need) if ((have[ch] || 0) < need[ch]) return false;
  if (have[word[0]] > have[word[word.length - 1]]) {
    word = word.split("").reverse().join("");
  }
  function dfs(r, c, k) {
    if (k === word.length) return true;
    if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
    if (board[r][c] !== word[k]) return false;
    const ch = board[r][c];
    board[r][c] = "#";
    const ok = dfs(r + 1, c, k + 1) || dfs(r - 1, c, k + 1) || dfs(r, c + 1, k + 1) || dfs(r, c - 1, k + 1);
    board[r][c] = ch;
    return ok;
  }
  for (let r = 0; r < rows; r++) for (let c = 0; c < cols; c++) if (dfs(r, c, 0)) return true;
  return false;
}
