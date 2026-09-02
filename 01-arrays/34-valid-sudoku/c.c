// Method 1: Brute
// Time: O(1) for 9x9 | Space: O(1)
// For every filled cell, walk its row, column, and 3x3 box looking for the same digit elsewhere. On a 9x9 this is constant, but the nested scans are noisy.

int okCell(char board[9][9], int r, int c, char d) {
  int i, j, br, bc;
  for (i = 0; i < 9; i++) {
    if (i != c && board[r][i] == d) return 0;
    if (i != r && board[i][c] == d) return 0;
  }
  br = (r / 3) * 3; bc = (c / 3) * 3;
  for (i = 0; i < 3; i++)
    for (j = 0; j < 3; j++) {
      int rr = br + i, cc = bc + j;
      if ((rr != r || cc != c) && board[rr][cc] == d) return 0;
    }
  return 1;
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// Nine sets for rows, nine for columns, nine for boxes. Box id is (r/3)*3 + c/3. Fail on the first repeat.

int isValidSudoku(char board[9][9]) {
  int row[9][10] = {0}, col[9][10] = {0}, box[9][10] = {0};
  int r, c;
  for (r = 0; r < 9; r++) {
    for (c = 0; c < 9; c++) {
      char d = board[r][c];
      int v, b;
      if (d == '.') continue;
      v = d - '0';
      b = (r / 3) * 3 + (c / 3);
      if (row[r][v] || col[c][v] || box[b][v]) return 0;
      row[r][v] = col[c][v] = box[b][v] = 1;
    }
  }
  return 1;
}


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Nine ints for rows, columns, boxes. Bit (1 << digit) marks a used number. A second hit on the same bit is a duplicate. Same logic, no hash sets.

int isValidSudokuBits(char board[9][9]) {
  int row[9] = {0}, col[9] = {0}, box[9] = {0};
  int r, c;
  for (r = 0; r < 9; r++) {
    for (c = 0; c < 9; c++) {
      char ch = board[r][c];
      int bit, b;
      if (ch == '.') continue;
      bit = 1 << (ch - '1');
      b = (r / 3) * 3 + (c / 3);
      if ((row[r] & bit) || (col[c] & bit) || (box[b] & bit)) return 0;
      row[r] |= bit; col[c] |= bit; box[b] |= bit;
    }
  }
  return 1;
}
