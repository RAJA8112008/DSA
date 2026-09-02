// Method 1: Brute
// Time: O(9^{e}) | Space: O(e)
// e empty cells. Each guess clones the board and scans from scratch. Extra copies on every node. Correct but memory-heavy.

bool valid(vector<vector<char>>& b, int r, int c, char ch) {
  for (int i = 0; i < 9; i++) {
    if (b[r][i] == ch || b[i][c] == ch) return false;
    if (b[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) return false;
  }
  return true;
}
bool go(vector<vector<char>> b, vector<vector<char>>& out) {
  for (int r = 0; r < 9; r++) for (int c = 0; c < 9; c++) {
    if (b[r][c] != '.') continue;
    for (char ch = '1'; ch <= '9'; ch++) {
      if (!valid(b, r, c, ch)) continue;
      auto copy = b; copy[r][c] = ch;
      if (go(copy, out)) return true;
    }
    return false;
  }
  out = b; return true;
}


// Method 2: Optimal
// Time: O(9^{e}) | Space: O(e)
// Write a digit in place, recurse, write '.'. isValid scans the row, column, and box. No extra boards. First empty cell, left to right.

bool valid(vector<vector<char>>& board, int r, int c, char ch) {
  for (int i = 0; i < 9; i++) {
    if (board[r][i] == ch || board[i][c] == ch) return false;
    if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) return false;
  }
  return true;
}
bool go(vector<vector<char>>& board) {
  for (int r = 0; r < 9; r++) for (int c = 0; c < 9; c++) {
    if (board[r][c] != '.') continue;
    for (char ch = '1'; ch <= '9'; ch++) {
      if (!valid(board, r, c, ch)) continue;
      board[r][c] = ch;
      if (go(board)) return true;
      board[r][c] = '.';
    }
    return false;
  }
  return true;
}


// Method 3: More optimal
// Time: O(9^{e}) | Space: O(e)
// row[], col[], box[] bitmasks. Pick the empty cell with the fewest remaining digits (MRV) so dead ends die sooner. Toggle bits instead of scanning 9 cells.

bool go(vector<vector<char>>& board, int k, vector<pair<int,int>>& empty, vector<int>& row, vector<int>& col, vector<int>& box) {
  if (k == (int)empty.size()) return true;
  int best = k, bestN = 10;
  for (int i = k; i < (int)empty.size(); i++) {
    int r = empty[i].first, c = empty[i].second;
    int used = row[r] | col[c] | box[(r / 3) * 3 + c / 3];
    int n = 9 - __builtin_popcount(used);
    if (n < bestN) { bestN = n; best = i; }
  }
  swap(empty[k], empty[best]);
  int r = empty[k].first, c = empty[k].second, b = (r / 3) * 3 + c / 3;
  int avail = ((1 << 9) - 1) ^ (row[r] | col[c] | box[b]);
  while (avail) {
    int bit = avail & -avail; avail ^= bit;
    int d = __builtin_ctz(bit) + 1;
    board[r][c] = char('0' + d);
    row[r] |= bit; col[c] |= bit; box[b] |= bit;
    if (go(board, k + 1, empty, row, col, box)) return true;
    row[r] ^= bit; col[c] ^= bit; box[b] ^= bit;
    board[r][c] = '.';
  }
  return false;
}
