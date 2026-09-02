// Method 1: Brute
// Time: O(n * n!) | Space: O(n^2)
// Generate every permutation of columns with extra copies. After a full permutation, scan every pair for a shared diagonal. Most permutations fail only at the end.

import java.util.*;
class Solution {
  public List<List<String>> solveNQueens(int n) {
    List<List<String>> ans = new ArrayList<List<String>>();
    List<Integer> left = new ArrayList<Integer>();
    for (int c = 0; c < n; c++) left.add(c);
    go(n, left, new ArrayList<Integer>(), ans);
    return ans;
  }
  boolean ok(List<Integer> cols) {
    int n = cols.size();
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
      if (Math.abs(i - j) == Math.abs(cols.get(i) - cols.get(j))) return false;
    return true;
  }
  void go(int n, List<Integer> left, List<Integer> cols, List<List<String>> ans) {
    if (left.isEmpty()) {
      if (!ok(cols)) return;
      List<String> board = new ArrayList<String>();
      for (int r = 0; r < n; r++) {
        char[] row = new char[n];
        Arrays.fill(row, '.');
        row[cols.get(r)] = 'Q';
        board.add(new String(row));
      }
      ans.add(board);
      return;
    }
    for (int i = 0; i < left.size(); i++) {
      List<Integer> nextLeft = new ArrayList<Integer>(left);
      List<Integer> nextCols = new ArrayList<Integer>(cols);
      nextCols.add(nextLeft.remove(i));
      go(n, nextLeft, nextCols, ans);
    }
  }
}


// Method 2: Optimal
// Time: O(n!) | Space: O(n^2)
// Place one queen per row. col[], d1[], d2[] mark attacks. If the square is free, mark, recurse row+1, unmark. Failures die as soon as a row has no square.

import java.util.*;
class Solution {
  public List<List<String>> solveNQueens(int n) {
    List<List<String>> ans = new ArrayList<List<String>>();
    char[][] board = new char[n][n];
    for (int i = 0; i < n; i++) Arrays.fill(board[i], '.');
    go(0, n, board, new int[n], new int[2 * n], new int[2 * n], ans);
    return ans;
  }
  void go(int row, int n, char[][] board, int[] col, int[] d1, int[] d2, List<List<String>> ans) {
    if (row == n) {
      List<String> cur = new ArrayList<String>();
      for (int i = 0; i < n; i++) cur.add(new String(board[i]));
      ans.add(cur);
      return;
    }
    for (int c = 0; c < n; c++) {
      if (col[c] != 0 || d1[row - c + n] != 0 || d2[row + c] != 0) continue;
      col[c] = d1[row - c + n] = d2[row + c] = 1;
      board[row][c] = 'Q';
      go(row + 1, n, board, col, d1, d2, ans);
      board[row][c] = '.';
      col[c] = d1[row - c + n] = d2[row + c] = 0;
    }
  }
}


// Method 3: More optimal
// Time: O(n!) | Space: O(n^2)
// cols, diag, anti as bitmasks. available bits are the free columns. Take the lowest set bit, recurse with shifted diagonals. Same search, O(1) updates.

import java.util.*;
class Solution {
  public List<List<String>> solveNQueens(int n) {
    List<List<String>> ans = new ArrayList<List<String>>();
    char[][] board = new char[n][n];
    for (int i = 0; i < n; i++) Arrays.fill(board[i], '.');
    go(0, n, 0, 0, 0, board, ans);
    return ans;
  }
  void go(int row, int n, int cols, int d1, int d2, char[][] board, List<List<String>> ans) {
    if (row == n) {
      List<String> cur = new ArrayList<String>();
      for (int i = 0; i < n; i++) cur.add(new String(board[i]));
      ans.add(cur);
      return;
    }
    int avail = ((1 << n) - 1) & ~(cols | d1 | d2);
    while (avail != 0) {
      int bit = avail & -avail;
      avail ^= bit;
      int c = Integer.numberOfTrailingZeros(bit);
      board[row][c] = 'Q';
      go(row + 1, n, cols | bit, (d1 | bit) << 1, (d2 | bit) >> 1, board, ans);
      board[row][c] = '.';
    }
  }
}
