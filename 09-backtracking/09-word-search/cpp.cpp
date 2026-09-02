// Method 1: Brute
// Time: O(r c * 4^L) | Space: O(r c * L)
// Every recursive step clones the whole visited grid. Correct, but memory traffic is huge. L is the word length. 4^L walks from each start.

bool dfs(vector<vector<char>>& board, string& word, int r, int c, int k, vector<vector<int>> seen) {
  if (k == (int)word.size()) return true;
  int rows = (int)board.size(), cols = (int)board[0].size();
  if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
  if (seen[r][c] || board[r][c] != word[k]) return false;
  seen[r][c] = 1;
  return dfs(board, word, r + 1, c, k + 1, seen) || dfs(board, word, r - 1, c, k + 1, seen)
      || dfs(board, word, r, c + 1, k + 1, seen) || dfs(board, word, r, c - 1, k + 1, seen);
}


// Method 2: Optimal
// Time: O(r c * 4^L) | Space: O(L)
// Mark the cell as '#' (or a visited flag), recurse four ways, restore the letter. One board, undo after each branch. Stack is O(L).

bool dfs(vector<vector<char>>& board, string& word, int r, int c, int k) {
  if (k == (int)word.size()) return true;
  int rows = (int)board.size(), cols = (int)board[0].size();
  if (r < 0 || c < 0 || r >= rows || c >= cols) return false;
  if (board[r][c] != word[k]) return false;
  char ch = board[r][c];
  board[r][c] = '#';
  bool ok = dfs(board, word, r + 1, c, k + 1) || dfs(board, word, r - 1, c, k + 1)
         || dfs(board, word, r, c + 1, k + 1) || dfs(board, word, r, c - 1, k + 1);
  board[r][c] = ch;
  return ok;
}
bool exist(vector<vector<char>>& board, string word) {
  for (int r = 0; r < (int)board.size(); r++)
    for (int c = 0; c < (int)board[0].size(); c++)
      if (dfs(board, word, r, c, 0)) return true;
  return false;
}


// Method 3: More optimal
// Time: O(r c * 4^L) | Space: O(L)
// Count letters first. If the board cannot supply a letter, return false. Search from the rarer end of the word. Return true on the first hit so you do not walk the rest of the grid.

bool exist(vector<vector<char>>& board, string word) {
  int need[128] = {0}, have[128] = {0};
  for (char ch : word) need[(int)ch]++;
  for (auto& row : board) for (char ch : row) have[(int)ch]++;
  for (int i = 0; i < 128; i++) if (have[i] < need[i]) return false;
  if (have[(int)word[0]] > have[(int)word.back()]) reverse(word.begin(), word.end());
  function<bool(int,int,int)> dfs = [&](int r, int c, int k) -> bool {
    if (k == (int)word.size()) return true;
    if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return false;
    if (board[r][c] != word[k]) return false;
    char ch = board[r][c];
    board[r][c] = '#';
    bool ok = dfs(r + 1, c, k + 1) || dfs(r - 1, c, k + 1) || dfs(r, c + 1, k + 1) || dfs(r, c - 1, k + 1);
    board[r][c] = ch;
    return ok;
  };
  for (int r = 0; r < (int)board.size(); r++)
    for (int c = 0; c < (int)board[0].size(); c++) if (dfs(r, c, 0)) return true;
  return false;
}
