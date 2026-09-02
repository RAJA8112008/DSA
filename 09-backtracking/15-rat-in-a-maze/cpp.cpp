// Method 1: Brute
// Time: O(4^{n^2}) | Space: O(n^2)
// Each step clones visited and concatenates a new path string. Exponential walks, extra copies at every node. Fine on n = 2, painful on n = 5.

void go(vector<vector<int>>& grid, int r, int c, string path, vector<vector<int>> seen, vector<string>& ans) {
  int n = (int)grid.size();
  if (r == n - 1 && c == n - 1) { ans.push_back(path); return; }
  int dr[4] = {1, 0, 0, -1}, dc[4] = {0, -1, 1, 0};
  char ch[4] = {'D', 'L', 'R', 'U'};
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
    if (grid[nr][nc] == 0 || seen[nr][nc]) continue;
    auto copy = seen; copy[nr][nc] = 1;
    go(grid, nr, nc, path + ch[i], copy, ans);
  }
}


// Method 2: Optimal
// Time: O(4^{n^2}) | Space: O(n^2)
// Mark grid[r][c] = 0 (or a visited flag), append D/L/R/U, recurse, restore 1. One path buffer. Copy the string only when you hit the end.

void go(vector<vector<int>>& grid, int r, int c, string& path, vector<string>& ans) {
  int n = (int)grid.size();
  if (r == n - 1 && c == n - 1) { ans.push_back(path); return; }
  int dr[4] = {1,0,0,-1}, dc[4] = {0,-1,1,0};
  char ch[4] = {'D','L','R','U'};
  for (int i = 0; i < 4; i++) {
    int nr = r + dr[i], nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] == 0) continue;
    grid[nr][nc] = 0;
    path.push_back(ch[i]);
    go(grid, nr, nc, path, ans);
    path.pop_back();
    grid[nr][nc] = 1;
  }
}


// Method 3: More optimal
// Time: O(4^{n^2}) | Space: O(n^2)
// Same mark/unmark, plus skip a blocked start immediately. Try directions in DLRU order so the output is already sorted, no extra sort. Dead walls never enter the stack.

vector<string> ratInMaze(vector<vector<int>>& grid) {
  int n = (int)grid.size();
  vector<string> ans;
  if (!n || grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return ans;
  string path;
  grid[0][0] = 0;
  function<void(int,int)> go = [&](int r, int c) {
    if (r == n - 1 && c == n - 1) { ans.push_back(path); return; }
    int dr[4] = {1,0,0,-1}, dc[4] = {0,-1,1,0};
    char ch[4] = {'D','L','R','U'};
    for (int i = 0; i < 4; i++) {
      int nr = r + dr[i], nc = c + dc[i];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] != 1) continue;
      grid[nr][nc] = 0; path.push_back(ch[i]);
      go(nr, nc);
      path.pop_back(); grid[nr][nc] = 1;
    }
  };
  go(0, 0);
  grid[0][0] = 1;
  return ans;
}
