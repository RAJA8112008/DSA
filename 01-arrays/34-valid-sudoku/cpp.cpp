// Method 1: Brute
// Time: O(1) for 9x9 | Space: O(1)
// For every filled cell, walk its row, column, and 3x3 box looking for the same digit elsewhere. On a 9x9 this is constant, but the nested scans are noisy.

bool isValidSudoku(vector<vector<char>>& board) {
  auto ok = [&](int r, int c, char d) {
    for (int i = 0; i < 9; i++) {
      if (i != c && board[r][i] == d) return false;
      if (i != r && board[i][c] == d) return false;
    }
    int br = (r / 3) * 3, bc = (c / 3) * 3;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        int rr = br + i, cc = bc + j;
        if ((rr != r || cc != c) && board[rr][cc] == d) return false;
      }
    return true;
  };
  for (int r = 0; r < 9; r++)
    for (int c = 0; c < 9; c++)
      if (board[r][c] != '.' && !ok(r, c, board[r][c])) return false;
  return true;
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// Nine sets for rows, nine for columns, nine for boxes. Box id is (r/3)*3 + c/3. Fail on the first repeat.

bool isValidSudoku(vector<vector<char>>& board) {
  vector<unordered_set<char>> row(9), col(9), box(9);
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      char d = board[r][c];
      if (d == '.') continue;
      int b = (r / 3) * 3 + (c / 3);
      if (row[r].count(d) || col[c].count(d) || box[b].count(d)) return false;
      row[r].insert(d); col[c].insert(d); box[b].insert(d);
    }
  }
  return true;
}


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Nine ints for rows, columns, boxes. Bit (1 << digit) marks a used number. A second hit on the same bit is a duplicate. Same logic, no hash sets.

bool isValidSudoku(vector<vector<char>>& board) {
  int row[9] = {}, col[9] = {}, box[9] = {};
  for (int r = 0; r < 9; r++) {
    for (int c = 0; c < 9; c++) {
      char ch = board[r][c];
      if (ch == '.') continue;
      int bit = 1 << (ch - '1');
      int b = (r / 3) * 3 + (c / 3);
      if ((row[r] & bit) || (col[c] & bit) || (box[b] & bit)) return false;
      row[r] |= bit; col[c] |= bit; box[b] |= bit;
    }
  }
  return true;
}
