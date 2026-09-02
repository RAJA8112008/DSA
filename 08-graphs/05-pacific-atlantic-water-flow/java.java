// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// From every cell, DFS toward lower/equal neighbors with a fresh visited copy. Check if that walk hits a Pacific border and an Atlantic border. Extra copies plus a full search per cell.

import java.util.*;
class Solution {
  public List<List<Integer>> pacificAtlantic(int[][] heights) {
    int rows = heights.length, cols = heights[0].length;
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int sr = 0; sr < rows; sr++) for (int sc = 0; sc < cols; sc++) {
      boolean[][] seen = new boolean[rows][cols];
      ArrayDeque<int[]> stack = new ArrayDeque<int[]>();
      stack.push(new int[]{sr, sc}); seen[sr][sc] = true;
      boolean pac = false, atl = false;
      while (!stack.isEmpty()) {
        int[] cur = stack.pop(); int r=cur[0], c=cur[1];
        if (r==0 || c==0) pac = true;
        if (r==rows-1 || c==cols-1) atl = true;
        if (pac && atl) break;
        for (int i = 0; i < 4; i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
          if (seen[nr][nc] || heights[nr][nc] > heights[r][c]) continue;
          seen[nr][nc]=true; stack.push(new int[]{nr,nc});
        }
      }
      if (pac && atl) ans.add(Arrays.asList(sr, sc));
    }
    return ans;
  }
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Reverse the flow: water climbs to equal or higher cells. DFS from all Pacific border cells, then from all Atlantic border cells. A cell in both visited sets is an answer. Each cell is processed a constant number of times.

import java.util.*;
class Solution {
  int rows, cols;
  void dfs(int[][] h, int r, int c, boolean[][] seen) {
    seen[r][c] = true;
    int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < 4; i++) {
      int nr=r+dirs[i][0], nc=c+dirs[i][1];
      if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
      if (seen[nr][nc] || h[nr][nc] < h[r][c]) continue;
      dfs(h, nr, nc, seen);
    }
  }
  public List<List<Integer>> pacificAtlantic(int[][] heights) {
    rows = heights.length; cols = heights[0].length;
    boolean[][] pac = new boolean[rows][cols], atl = new boolean[rows][cols];
    for (int r = 0; r < rows; r++) { dfs(heights, r, 0, pac); dfs(heights, r, cols-1, atl); }
    for (int c = 0; c < cols; c++) { dfs(heights, 0, c, pac); dfs(heights, rows-1, c, atl); }
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    for (int r = 0; r < rows; r++) for (int c = 0; c < cols; c++)
      if (pac[r][c] && atl[r][c]) ans.add(Arrays.asList(r, c));
    return ans;
  }
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Same reverse idea with BFS from both oceans. No recursion on a huge grid. Complexity is still linear in cells. This is the interview upgrade when they worry about stack depth.

import java.util.*;
class Solution {
  public List<List<Integer>> pacificAtlantic(int[][] heights) {
    int rows=heights.length, cols=heights[0].length;
    boolean[][] pac=new boolean[rows][cols], atl=new boolean[rows][cols];
    int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    ArrayDeque<int[]> qp=new ArrayDeque<int[]>(), qa=new ArrayDeque<int[]>();
    for (int r=0;r<rows;r++) {
      pac[r][0]=true; qp.addLast(new int[]{r,0});
      atl[r][cols-1]=true; qa.addLast(new int[]{r,cols-1});
    }
    for (int c=0;c<cols;c++) {
      pac[0][c]=true; qp.addLast(new int[]{0,c});
      atl[rows-1][c]=true; qa.addLast(new int[]{rows-1,c});
    }
    for (ArrayDeque<int[]> q : new ArrayDeque[]{qp}) {}
    ArrayDeque<int[]>[] qs = new ArrayDeque[]{qp, qa};
    boolean[][][] seens = {pac, atl};
    for (int t=0;t<2;t++) {
      ArrayDeque<int[]> q = t==0?qp:qa; boolean[][] seen=t==0?pac:atl;
      while (!q.isEmpty()) {
        int[] cur=q.pollFirst(); int r=cur[0], c=cur[1];
        for (int i=0;i<4;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
          if (seen[nr][nc] || heights[nr][nc] < heights[r][c]) continue;
          seen[nr][nc]=true; q.addLast(new int[]{nr,nc});
        }
      }
    }
    List<List<Integer>> ans=new ArrayList<List<Integer>>();
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (pac[r][c]&&atl[r][c]) ans.add(Arrays.asList(r,c));
    return ans;
  }
}
