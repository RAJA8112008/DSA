// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For every land cell we copy a full visited matrix and DFS that island. The extra copies are wasted work. Correct, but memory traffic is huge on a large grid.

#include <stdlib.h>
#include <string.h>
int numIslands(char** grid, int rows, int cols) {
  if (!rows) return 0;
  int* global = (int*)calloc(rows * cols, sizeof(int));
  int count = 0;
  int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
  int* seen = (int*)malloc(sizeof(int)*rows*cols);
  int* stx = (int*)malloc(sizeof(int)*rows*cols);
  int* sty = (int*)malloc(sizeof(int)*rows*cols);
  for (int r = 0; r < rows; r++) for (int c = 0; c < cols; c++) {
    if (grid[r][c] != '1' || global[r*cols+c]) continue;
    count++;
    memcpy(seen, global, sizeof(int)*rows*cols);
    int sn = 0; stx[sn]=r; sty[sn]=c; sn++; seen[r*cols+c]=1;
    while (sn) {
      int x = stx[--sn], y = sty[sn];
      global[x*cols+y] = 1;
      for (int i = 0; i < 4; i++) {
        int nx = x + dirs[i][0], ny = y + dirs[i][1];
        if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) continue;
        if (grid[nx][ny] != '1' || seen[nx*cols+ny]) continue;
        seen[nx*cols+ny]=1; stx[sn]=nx; sty[sn]=ny; sn++;
      }
    }
  }
  free(global); free(seen); free(stx); free(sty);
  return count;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// One DFS (or BFS) per island. Mutating land to water is the visited mark, so we never copy a matrix. Each cell is entered a constant number of times.

int rows_g, cols_g;
void dfs_island(char** grid, int r, int c) {
  if (r < 0 || c < 0 || r >= rows_g || c >= cols_g) return;
  if (grid[r][c] != '1') return;
  grid[r][c] = '0';
  dfs_island(grid, r+1, c); dfs_island(grid, r-1, c);
  dfs_island(grid, r, c+1); dfs_island(grid, r, c-1);
}
int numIslands(char** grid, int rows, int cols) {
  if (!rows) return 0;
  rows_g = rows; cols_g = cols;
  int count = 0;
  for (int r = 0; r < rows; r++) for (int c = 0; c < cols; c++)
    if (grid[r][c] == '1') { count++; dfs_island(grid, r, c); }
  return count;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Union-Find treats each land cell as a node. You only union with the right and down land neighbor, so each edge is processed once. The island count is how many land roots remain. No recursion.

#include <stdlib.h>
int findp(int* parent, int x) {
  while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
  return x;
}
int numIslands(char** grid, int rows, int cols) {
  if (!rows) return 0;
  int n = rows * cols;
  int* parent = (int*)malloc(sizeof(int)*n);
  int* rank = (int*)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) parent[i] = i;
  int islands = 0;
  for (int r = 0; r < rows; r++) for (int c = 0; c < cols; c++) {
    if (grid[r][c] != '1') continue;
    islands++;
    if (c + 1 < cols && grid[r][c+1] == '1') {
      int x = findp(parent, r*cols+c), y = findp(parent, r*cols+c+1);
      if (x != y) { if (rank[x] < rank[y]) { int t=x; x=y; y=t; } parent[y]=x; if (rank[x]==rank[y]) rank[x]++; islands--; }
    }
    if (r + 1 < rows && grid[r+1][c] == '1') {
      int x = findp(parent, r*cols+c), y = findp(parent, (r+1)*cols+c);
      if (x != y) { if (rank[x] < rank[y]) { int t=x; x=y; y=t; } parent[y]=x; if (rank[x]==rank[y]) rank[x]++; islands--; }
    }
  }
  free(parent); free(rank);
  return islands;
}
