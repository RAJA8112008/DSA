// Method 1: Brute
// Time: O(r c * 4^L) | Space: O(r c * L)
// Every recursive step clones the whole visited grid. Correct, but memory traffic is huge. L is the word length. 4^L walks from each start.

int dfs(char** board, int rows, int cols, const char* word, int r, int c, int k, int** seen) {
  int **copy, i, j, ok;
  if (word[k] == '\0') return 1;
  if (r < 0 || c < 0 || r >= rows || c >= cols) return 0;
  if (seen[r][c] || board[r][c] != word[k]) return 0;
  copy = (int**)malloc(sizeof(int*) * rows);
  for (i = 0; i < rows; i++) {
    copy[i] = (int*)malloc(sizeof(int) * cols);
    for (j = 0; j < cols; j++) copy[i][j] = seen[i][j];
  }
  copy[r][c] = 1;
  ok = dfs(board, rows, cols, word, r + 1, c, k + 1, copy) || dfs(board, rows, cols, word, r - 1, c, k + 1, copy)
    || dfs(board, rows, cols, word, r, c + 1, k + 1, copy) || dfs(board, rows, cols, word, r, c - 1, k + 1, copy);
  for (i = 0; i < rows; i++) free(copy[i]);
  free(copy);
  return ok;
}


// Method 2: Optimal
// Time: O(r c * 4^L) | Space: O(L)
// Mark the cell as '#' (or a visited flag), recurse four ways, restore the letter. One board, undo after each branch. Stack is O(L).

int dfs(char** board, int rows, int cols, const char* word, int r, int c, int k) {
  char ch; int ok;
  if (word[k] == '\0') return 1;
  if (r < 0 || c < 0 || r >= rows || c >= cols) return 0;
  if (board[r][c] != word[k]) return 0;
  ch = board[r][c];
  board[r][c] = '#';
  ok = dfs(board, rows, cols, word, r + 1, c, k + 1) || dfs(board, rows, cols, word, r - 1, c, k + 1)
    || dfs(board, rows, cols, word, r, c + 1, k + 1) || dfs(board, rows, cols, word, r, c - 1, k + 1);
  board[r][c] = ch;
  return ok;
}


// Method 3: More optimal
// Time: O(r c * 4^L) | Space: O(L)
// Count letters first. If the board cannot supply a letter, return false. Search from the rarer end of the word. Return true on the first hit so you do not walk the rest of the grid.

int existMore(char** board, int rows, int cols, char* word) {
  int need[128] = {0}, have[128] = {0}, i, r, c, n;
  n = (int)strlen(word);
  for (i = 0; i < n; i++) need[(int)word[i]]++;
  for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) have[(int)board[r][c]]++;
  for (i = 0; i < 128; i++) if (have[i] < need[i]) return 0;
  for (r = 0; r < rows; r++) for (c = 0; c < cols; c++)
    if (dfs(board, rows, cols, word, r, c, 0)) return 1;
  return 0;
}
