// Method 1: Brute
// Time: O(1) for 9x9 | Space: O(1)
// For every filled cell, walk its row, column, and 3x3 box looking for the same digit elsewhere. On a 9x9 this is constant, but the nested scans are noisy.

class Solution {
  boolean ok(char[][] board, int r, int c, char d) {
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
  }
  public boolean isValidSudoku(char[][] board) {
    for (int r = 0; r < 9; r++)
      for (int c = 0; c < 9; c++)
        if (board[r][c] != '.' && !ok(board, r, c, board[r][c])) return false;
    return true;
  }
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// Nine sets for rows, nine for columns, nine for boxes. Box id is (r/3)*3 + c/3. Fail on the first repeat.

import java.util.*;
class Solution {
  public boolean isValidSudoku(char[][] board) {
    Set<Character>[] row = new HashSet[9];
    Set<Character>[] col = new HashSet[9];
    Set<Character>[] box = new HashSet[9];
    for (int i = 0; i < 9; i++) {
      row[i] = new HashSet<Character>();
      col[i] = new HashSet<Character>();
      box[i] = new HashSet<Character>();
    }
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        char d = board[r][c];
        if (d == '.') continue;
        int b = (r / 3) * 3 + (c / 3);
        if (!row[r].add(d) || !col[c].add(d) || !box[b].add(d)) return false;
      }
    }
    return true;
  }
}


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Nine ints for rows, columns, boxes. Bit (1 << digit) marks a used number. A second hit on the same bit is a duplicate. Same logic, no hash sets.

class Solution {
  public boolean isValidSudoku(char[][] board) {
    int[] row = new int[9], col = new int[9], box = new int[9];
    for (int r = 0; r < 9; r++) {
      for (int c = 0; c < 9; c++) {
        char ch = board[r][c];
        if (ch == '.') continue;
        int bit = 1 << (ch - '1');
        int b = (r / 3) * 3 + (c / 3);
        if ((row[r] & bit) != 0 || (col[c] & bit) != 0 || (box[b] & bit) != 0) return false;
        row[r] |= bit; col[c] |= bit; box[b] |= bit;
      }
    }
    return true;
  }
}
