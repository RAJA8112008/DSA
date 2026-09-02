// Method 1: Brute
// Time: O(4^{n^2}) | Space: O(n^2)
// Each step clones visited and concatenates a new path string. Exponential walks, extra copies at every node. Fine on n = 2, painful on n = 5.

import java.util.*;
class Solution {
  public ArrayList<String> ratInMaze(int[][] grid) {
    ArrayList<String> ans = new ArrayList<String>();
    int n = grid.length;
    if (n == 0 || grid[0][0] == 0) return ans;
    boolean[][] seen = new boolean[n][n];
    seen[0][0] = true;
    go(grid, 0, 0, "", seen, ans);
    return ans;
  }
  void go(int[][] grid, int r, int c, String path, boolean[][] seen, ArrayList<String> ans) {
    int n = grid.length;
    if (r == n - 1 && c == n - 1) { ans.add(path); return; }
    int[][] dirs = {{1,0},{0,-1},{0,1},{-1,0}};
    char[] ch = {'D','L','R','U'};
    for (int i = 0; i < 4; i++) {
      int nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
      if (grid[nr][nc] == 0 || seen[nr][nc]) continue;
      boolean[][] copy = new boolean[n][n];
      for (int a = 0; a < n; a++) copy[a] = seen[a].clone();
      copy[nr][nc] = true;
      go(grid, nr, nc, path + ch[i], copy, ans);
    }
  }
}


// Method 2: Optimal
// Time: O(4^{n^2}) | Space: O(n^2)
// Mark grid[r][c] = 0 (or a visited flag), append D/L/R/U, recurse, restore 1. One path buffer. Copy the string only when you hit the end.

import java.util.*;
class Solution {
  public ArrayList<String> ratInMaze(int[][] grid) {
    ArrayList<String> ans = new ArrayList<String>();
    int n = grid.length;
    if (n == 0 || grid[0][0] == 0) return ans;
    grid[0][0] = 0;
    go(grid, 0, 0, new StringBuilder(), ans);
    grid[0][0] = 1;
    return ans;
  }
  void go(int[][] grid, int r, int c, StringBuilder path, ArrayList<String> ans) {
    int n = grid.length;
    if (r == n - 1 && c == n - 1) { ans.add(path.toString()); return; }
    int[][] dirs = {{1,0},{0,-1},{0,1},{-1,0}};
    char[] ch = {'D','L','R','U'};
    for (int i = 0; i < 4; i++) {
      int nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] == 0) continue;
      grid[nr][nc] = 0;
      path.append(ch[i]);
      go(grid, nr, nc, path, ans);
      path.deleteCharAt(path.length() - 1);
      grid[nr][nc] = 1;
    }
  }
}


// Method 3: More optimal
// Time: O(4^{n^2}) | Space: O(n^2)
// Same mark/unmark, plus skip a blocked start immediately. Try directions in DLRU order so the output is already sorted, no extra sort. Dead walls never enter the stack.

import java.util.*;
class Solution {
  public ArrayList<String> ratInMaze(int[][] grid) {
    ArrayList<String> ans = new ArrayList<String>();
    int n = grid.length;
    if (n == 0 || grid[0][0] == 0 || grid[n - 1][n - 1] == 0) return ans;
    grid[0][0] = 0;
    go(grid, 0, 0, new StringBuilder(), ans);
    grid[0][0] = 1;
    return ans;
  }
  void go(int[][] grid, int r, int c, StringBuilder path, ArrayList<String> ans) {
    int n = grid.length;
    if (r == n - 1 && c == n - 1) { ans.add(path.toString()); return; }
    int[][] dirs = {{1,0},{0,-1},{0,1},{-1,0}};
    char[] ch = {'D','L','R','U'};
    for (int i = 0; i < 4; i++) {
      int nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= n || nc >= n || grid[nr][nc] != 1) continue;
      grid[nr][nc] = 0;
      path.append(ch[i]);
      go(grid, nr, nc, path, ans);
      path.deleteCharAt(path.length() - 1);
      grid[nr][nc] = 1;
    }
  }
}
