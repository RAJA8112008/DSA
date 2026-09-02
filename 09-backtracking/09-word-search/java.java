// Method 1: Brute
// Time: O(r c * 4^L) | Space: O(r c * L)
// Every recursive step clones the whole visited grid. Correct, but memory traffic is huge. L is the word length. 4^L walks from each start.

class Solution {
  public boolean exist(char[][] board, String word) {
    int rows = board.length, cols = board[0].length;
    boolean[][] blank = new boolean[rows][cols];
    for (int r = 0; r < rows; r++)
      for (int c = 0; c < cols; c++)
        if (dfs(board, word, r, c, 0, blank)) return true;
    return false;
  }
  boolean dfs(char[][] board, String word, int r, int c, int k, boolean[][] seen) {
    if (k == word.length()) return true;
    int rows = board.length, cols = board[0].length;
    if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
    if (seen[r][c] || board[r][c] != word.charAt(k)) return false;
    boolean[][] copy = new boolean[rows][cols];
    for (int i = 0; i < rows; i++) copy[i] = seen[i].clone();
    copy[r][c] = true;
    return dfs(board, word, r + 1, c, k + 1, copy) || dfs(board, word, r - 1, c, k + 1, copy)
        || dfs(board, word, r, c + 1, k + 1, copy) || dfs(board, word, r, c - 1, k + 1, copy);
  }
}


// Method 2: Optimal
// Time: O(r c * 4^L) | Space: O(L)
// Mark the cell as '#' (or a visited flag), recurse four ways, restore the letter. One board, undo after each branch. Stack is O(L).

class Solution {
  public boolean exist(char[][] board, String word) {
    int rows = board.length, cols = board[0].length;
    for (int r = 0; r < rows; r++)
      for (int c = 0; c < cols; c++)
        if (dfs(board, word, r, c, 0)) return true;
    return false;
  }
  boolean dfs(char[][] board, String word, int r, int c, int k) {
    if (k == word.length()) return true;
    if (r < 0 || c < 0 || r >= board.length || c >= board[0].length) return false;
    if (board[r][c] != word.charAt(k)) return false;
    char ch = board[r][c];
    board[r][c] = '#';
    boolean ok = dfs(board, word, r + 1, c, k + 1) || dfs(board, word, r - 1, c, k + 1)
        || dfs(board, word, r, c + 1, k + 1) || dfs(board, word, r, c - 1, k + 1);
    board[r][c] = ch;
    return ok;
  }
}


// Method 3: More optimal
// Time: O(r c * 4^L) | Space: O(L)
// Count letters first. If the board cannot supply a letter, return false. Search from the rarer end of the word. Return true on the first hit so you do not walk the rest of the grid.

class Solution {
  public boolean exist(char[][] board, String word) {
    int[] need = new int[128], have = new int[128];
    for (int i = 0; i < word.length(); i++) need[word.charAt(i)]++;
    for (char[] row : board) for (char ch : row) have[ch]++;
    for (int i = 0; i < 128; i++) if (have[i] < need[i]) return false;
    if (have[word.charAt(0)] > have[word.charAt(word.length() - 1)])
      word = new StringBuilder(word).reverse().toString();
    for (int r = 0; r < board.length; r++)
      for (int c = 0; c < board[0].length; c++)
        if (dfs(board, word, r, c, 0)) return true;
    return false;
  }
  boolean dfs(char[][] board, String word, int r, int c, int k) {
    if (k == word.length()) return true;
    if (r < 0 || c < 0 || r >= board.length || c >= board[0].length) return false;
    if (board[r][c] != word.charAt(k)) return false;
    char ch = board[r][c];
    board[r][c] = '#';
    boolean ok = dfs(board, word, r + 1, c, k + 1) || dfs(board, word, r - 1, c, k + 1)
        || dfs(board, word, r, c + 1, k + 1) || dfs(board, word, r, c - 1, k + 1);
    board[r][c] = ch;
    return ok;
  }
}
