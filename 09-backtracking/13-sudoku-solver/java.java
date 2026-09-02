// Method 1: Brute
// Time: O(9^{e}) | Space: O(e)
// e empty cells. Each guess clones the board and scans from scratch. Extra copies on every node. Correct but memory-heavy.

class Solution {
  public void solveSudoku(char[][] board) { go(board); }
  boolean valid(char[][] b, int r, int c, char ch) {
    for (int i = 0; i < 9; i++) {
      if (b[r][i] == ch || b[i][c] == ch) return false;
      int br = (r / 3) * 3 + i / 3, bc = (c / 3) * 3 + i % 3;
      if (b[br][bc] == ch) return false;
    }
    return true;
  }
  boolean go(char[][] b) {
    for (int r = 0; r < 9; r++) for (int c = 0; c < 9; c++) {
      if (b[r][c] != '.') continue;
      for (char ch = '1'; ch <= '9'; ch++) {
        if (!valid(b, r, c, ch)) continue;
        char[][] copy = new char[9][9];
        for (int i = 0; i < 9; i++) copy[i] = b[i].clone();
        copy[r][c] = ch;
        if (go(copy)) {
          for (int i = 0; i < 9; i++) b[i] = copy[i];
          return true;
        }
      }
      return false;
    }
    return true;
  }
}


// Method 2: Optimal
// Time: O(9^{e}) | Space: O(e)
// Write a digit in place, recurse, write '.'. isValid scans the row, column, and box. No extra boards. First empty cell, left to right.

class Solution {
  public void solveSudoku(char[][] board) { go(board); }
  boolean valid(char[][] board, int r, int c, char ch) {
    for (int i = 0; i < 9; i++) {
      if (board[r][i] == ch || board[i][c] == ch) return false;
      if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) return false;
    }
    return true;
  }
  boolean go(char[][] board) {
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
}


// Method 3: More optimal
// Time: O(9^{e}) | Space: O(e)
// row[], col[], box[] bitmasks. Pick the empty cell with the fewest remaining digits (MRV) so dead ends die sooner. Toggle bits instead of scanning 9 cells.

class Solution {
  public void solveSudoku(char[][] board) {
    int[] row = new int[9], col = new int[9], box = new int[9];
    java.util.List<int[]> empty = new java.util.ArrayList<int[]>();
    for (int r = 0; r < 9; r++) for (int c = 0; c < 9; c++) {
      if (board[r][c] == '.') empty.add(new int[]{r, c});
      else {
        int bit = 1 << (board[r][c] - '1');
        row[r] |= bit; col[c] |= bit; box[(r / 3) * 3 + c / 3] |= bit;
      }
    }
    go(board, 0, empty, row, col, box);
  }
  boolean go(char[][] board, int k, java.util.List<int[]> empty, int[] row, int[] col, int[] box) {
    if (k == empty.size()) return true;
    int best = k, bestN = 10;
    for (int i = k; i < empty.size(); i++) {
      int r = empty.get(i)[0], c = empty.get(i)[1];
      int used = row[r] | col[c] | box[(r / 3) * 3 + c / 3];
      int n = 9 - Integer.bitCount(used);
      if (n < bestN) { bestN = n; best = i; }
    }
    java.util.Collections.swap(empty, k, best);
    int r = empty.get(k)[0], c = empty.get(k)[1], b = (r / 3) * 3 + c / 3;
    int avail = ((1 << 9) - 1) ^ (row[r] | col[c] | box[b]);
    while (avail != 0) {
      int bit = avail & -avail;
      avail ^= bit;
      int d = Integer.numberOfTrailingZeros(bit) + 1;
      board[r][c] = (char) ('0' + d);
      row[r] |= bit; col[c] |= bit; box[b] |= bit;
      if (go(board, k + 1, empty, row, col, box)) return true;
      row[r] ^= bit; col[c] ^= bit; box[b] ^= bit;
      board[r][c] = '.';
    }
    return false;
  }
}
