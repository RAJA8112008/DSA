// Method 1: Brute
// Time: O(n * n!) | Space: O(n^2)
// Generate every permutation of columns with extra copies. After a full permutation, scan every pair for a shared diagonal. Most permutations fail only at the end.

bool ok(vector<int>& cols) {
  int n = (int)cols.size();
  for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
    if (abs(i - j) == abs(cols[i] - cols[j])) return false;
  return true;
}
void go(int n, vector<int> left, vector<int> cols, vector<vector<string>>& ans) {
  if (left.empty()) {
    if (!ok(cols)) return;
    vector<string> board(n, string(n, '.'));
    for (int r = 0; r < n; r++) board[r][cols[r]] = 'Q';
    ans.push_back(board);
    return;
  }
  for (int i = 0; i < (int)left.size(); i++) {
    vector<int> nextLeft = left, nextCols = cols;
    nextCols.push_back(nextLeft[i]);
    nextLeft.erase(nextLeft.begin() + i);
    go(n, nextLeft, nextCols, ans);
  }
}


// Method 2: Optimal
// Time: O(n!) | Space: O(n^2)
// Place one queen per row. col[], d1[], d2[] mark attacks. If the square is free, mark, recurse row+1, unmark. Failures die as soon as a row has no square.

void go(int row, int n, vector<string>& board, vector<int>& col, vector<int>& d1, vector<int>& d2, vector<vector<string>>& ans) {
  if (row == n) { ans.push_back(board); return; }
  for (int c = 0; c < n; c++) {
    if (col[c] || d1[row - c + n] || d2[row + c]) continue;
    col[c] = d1[row - c + n] = d2[row + c] = 1;
    board[row][c] = 'Q';
    go(row + 1, n, board, col, d1, d2, ans);
    board[row][c] = '.';
    col[c] = d1[row - c + n] = d2[row + c] = 0;
  }
}


// Method 3: More optimal
// Time: O(n!) | Space: O(n^2)
// cols, diag, anti as bitmasks. available bits are the free columns. Take the lowest set bit, recurse with shifted diagonals. Same search, O(1) updates.

void go(int row, int n, int cols, int d1, int d2, vector<string>& board, vector<vector<string>>& ans) {
  if (row == n) { ans.push_back(board); return; }
  int avail = ((1 << n) - 1) & ~(cols | d1 | d2);
  while (avail) {
    int bit = avail & -avail;
    avail ^= bit;
    int c = __builtin_ctz(bit);
    board[row][c] = 'Q';
    go(row + 1, n, cols | bit, (d1 | bit) << 1, (d2 | bit) >> 1, board, ans);
    board[row][c] = '.';
  }
}
