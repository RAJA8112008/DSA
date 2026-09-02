// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For every land cell we copy a full visited matrix and DFS that island. The extra copies are wasted work. Correct, but memory traffic is huge on a large grid.

import java.util.*;
class Solution {
  public int numIslands(char[][] grid) {
    int rows = grid.length;
    if (rows == 0) return 0;
    int cols = grid[0].length;
    boolean[][] global = new boolean[rows][cols];
    int count = 0;
    int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (grid[r][c] != '1' || global[r][c]) continue;
        count++;
        boolean[][] seen = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) seen[i] = global[i].clone();
        ArrayDeque<int[]> stack = new ArrayDeque<int[]>();
        stack.push(new int[]{r, c}); seen[r][c] = true;
        while (!stack.isEmpty()) {
          int[] cell = stack.pop();
          int x = cell[0], y = cell[1];
          global[x][y] = true;
          for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i][0], ny = y + dirs[i][1];
            if (nx < 0 || ny < 0 || nx >= rows || ny >= cols) continue;
            if (grid[nx][ny] != '1' || seen[nx][ny]) continue;
            seen[nx][ny] = true; stack.push(new int[]{nx, ny});
          }
        }
      }
    }
    return count;
  }
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// One DFS (or BFS) per island. Mutating land to water is the visited mark, so we never copy a matrix. Each cell is entered a constant number of times.

class Solution {
  int rows, cols;
  void dfs(char[][] grid, int r, int c) {
    if (r < 0 || c < 0 || r >= rows || c >= cols) return;
    if (grid[r][c] != '1') return;
    grid[r][c] = '0';
    dfs(grid, r+1, c); dfs(grid, r-1, c); dfs(grid, r, c+1); dfs(grid, r, c-1);
  }
  public int numIslands(char[][] grid) {
    rows = grid.length; if (rows == 0) return 0;
    cols = grid[0].length;
    int count = 0;
    for (int r = 0; r < rows; r++) for (int c = 0; c < cols; c++) {
      if (grid[r][c] == '1') { count++; dfs(grid, r, c); }
    }
    return count;
  }
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Union-Find treats each land cell as a node. You only union with the right and down land neighbor, so each edge is processed once. The island count is how many land roots remain. No recursion.

class Solution {
  int[] parent, rank; int islands;
  int find(int x) {
    while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
    return x;
  }
  void union(int a, int b) {
    int x = find(a), y = find(b);
    if (x == y) return;
    if (rank[x] < rank[y]) { int t=x; x=y; y=t; }
    parent[y] = x;
    if (rank[x] == rank[y]) rank[x]++;
    islands--;
  }
  public int numIslands(char[][] grid) {
    int rows = grid.length; if (rows == 0) return 0;
    int cols = grid[0].length;
    int n = rows * cols;
    parent = new int[n]; rank = new int[n];
    for (int i = 0; i < n; i++) parent[i] = i;
    islands = 0;
    for (int r = 0; r < rows; r++) for (int c = 0; c < cols; c++) {
      if (grid[r][c] != '1') continue;
      islands++;
      if (c + 1 < cols && grid[r][c+1] == '1') union(r*cols+c, r*cols+c+1);
      if (r + 1 < rows && grid[r+1][c] == '1') union(r*cols+c, (r+1)*cols+c);
    }
    return islands;
  }
}
