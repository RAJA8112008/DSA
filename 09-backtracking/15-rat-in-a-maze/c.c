// Method 1: Brute
// Time: O(4^{n^2}) | Space: O(n^2)
// Each step clones visited and concatenates a new path string. Exponential walks, extra copies at every node. Fine on n = 2, painful on n = 5.

void go(int** grid, int n, int r, int c, char* path, int len, int** seen) {
  int dr[4] = {1,0,0,-1}, dc[4] = {0,-1,1,0};
  char ch[4] = {'D','L','R','U'};
  int i, nr, nc, a, b, **copy;
  if (r == n - 1 && c == n - 1) { path[len] = '\0'; printf("%s\n", path); return; }
  for (i = 0; i < 4; i++) {
    nr = r + dr[i]; nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
    if (grid[nr][nc] == 0 || seen[nr][nc]) continue;
    copy = (int**)malloc(sizeof(int*) * n);
    for (a = 0; a < n; a++) {
      copy[a] = (int*)malloc(sizeof(int) * n);
      for (b = 0; b < n; b++) copy[a][b] = seen[a][b];
    }
    copy[nr][nc] = 1;
    path[len] = ch[i];
    go(grid, n, nr, nc, path, len + 1, copy);
    for (a = 0; a < n; a++) free(copy[a]);
    free(copy);
  }
}


// Method 2: Optimal
// Time: O(4^{n^2}) | Space: O(n^2)
// Mark grid[r][c] = 0 (or a visited flag), append D/L/R/U, recurse, restore 1. One path buffer. Copy the string only when you hit the end.

void go(int** grid, int n, int r, int c, char* path, int len) {
  int dr[4] = {1,0,0,-1}, dc[4] = {0,-1,1,0};
  char ch[4] = {'D','L','R','U'};
  int i, nr, nc;
  if (r == n - 1 && c == n - 1) { path[len] = '\0'; printf("%s\n", path); return; }
  for (i = 0; i < 4; i++) {
    nr = r + dr[i]; nc = c + dc[i];
    if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] == 0) continue;
    grid[nr][nc] = 0;
    path[len] = ch[i];
    go(grid, n, nr, nc, path, len + 1);
    grid[nr][nc] = 1;
  }
}


// Method 3: More optimal
// Time: O(4^{n^2}) | Space: O(n^2)
// Same mark/unmark, plus skip a blocked start immediately. Try directions in DLRU order so the output is already sorted, no extra sort. Dead walls never enter the stack.

void ratInMaze(int** grid, int n, char* path) {
  if (!n || grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return;
  grid[0][0] = 0;
  go(grid, n, 0, 0, path, 0);
  grid[0][0] = 1;
}
