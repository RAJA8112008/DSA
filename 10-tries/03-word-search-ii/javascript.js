// Method 1: Brute
// Time: O(w m n 4^L) | Space: O(L)
// For each word, DFS from every cell. Mark the cell, try four neighbors, unmark. Correct, but you restart the whole board for every dictionary word.

function findWords(board, words) {
  const rows = board.length, cols = board[0].length;
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
  function dfs(r, c, k, word) {
    if (k === word.length) return true;
    if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
    if (board[r][c] !== word[k]) return false;
    const saved = board[r][c];
    board[r][c] = "#";
    for (let i = 0; i < 4; i++) {
      if (dfs(r + dirs[i][0], c + dirs[i][1], k + 1, word)) {
        board[r][c] = saved;
        return true;
      }
    }
    board[r][c] = saved;
    return false;
  }
  const out = [];
  for (let w = 0; w < words.length; w++) {
    let found = false;
    for (let r = 0; r < rows && !found; r++) {
      for (let c = 0; c < cols && !found; c++) {
        if (dfs(r, c, 0, words[w])) found = true;
      }
    }
    if (found) out.push(words[w]);
  }
  return out;
}


// Method 2: Optimal
// Time: O(m n 4^L) | Space: O(total chars)
// Build a trie of all words, then DFS from every cell following only living children. One board walk instead of one walk per word.

function findWords(board, words) {
  function node() { return { ch: Array(26).fill(null), end: false, word: "" }; }
  const root = node();
  for (let w = 0; w < words.length; w++) {
    let cur = root;
    const s = words[w];
    for (let i = 0; i < s.length; i++) {
      const idx = s.charCodeAt(i) - 97;
      if (!cur.ch[idx]) cur.ch[idx] = node();
      cur = cur.ch[idx];
    }
    cur.end = true;
    cur.word = s;
  }
  const rows = board.length, cols = board[0].length;
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
  const seen = {};
  const out = [];
  function dfs(r, c, cur) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    const ch = board[r][c];
    if (ch === "#") return;
    const nxt = cur.ch[ch.charCodeAt(0) - 97];
    if (!nxt) return;
    if (nxt.end && !seen[nxt.word]) {
      seen[nxt.word] = true;
      out.push(nxt.word);
    }
    board[r][c] = "#";
    for (let i = 0; i < 4; i++) dfs(r + dirs[i][0], c + dirs[i][1], nxt);
    board[r][c] = ch;
  }
  for (let r = 0; r < rows; r++) for (let c = 0; c < cols; c++) dfs(r, c, root);
  return out;
}


// Method 3: More optimal
// Time: O(m n 4^L) | Space: O(total chars)
// Same trie DFS, but after you emit a word you clear that end mark (and optionally prune empty children). That stops duplicate work and extra copies of the same word.

function findWords(board, words) {
  function node() { return { ch: {}, word: null }; }
  const root = node();
  for (let w = 0; w < words.length; w++) {
    let cur = root;
    const s = words[w];
    for (let i = 0; i < s.length; i++) {
      if (!cur.ch[s[i]]) cur.ch[s[i]] = node();
      cur = cur.ch[s[i]];
    }
    cur.word = s;
  }
  const rows = board.length, cols = board[0].length;
  const dirs = [[1, 0], [-1, 0], [0, 1], [0, -1]];
  const out = [];
  function dfs(r, c, cur) {
    const ch = board[r][c];
    const nxt = cur.ch[ch];
    if (!nxt) return;
    if (nxt.word) {
      out.push(nxt.word);
      nxt.word = null;
    }
    board[r][c] = "#";
    for (let i = 0; i < 4; i++) {
      const nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
      if (board[nr][nc] === "#") continue;
      dfs(nr, nc, nxt);
    }
    board[r][c] = ch;
  }
  for (let r = 0; r < rows; r++) for (let c = 0; c < cols; c++) dfs(r, c, root);
  return out;
}
