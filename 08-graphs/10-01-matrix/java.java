// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For each 1, BFS with a fresh visited matrix until you hit a 0. You re-walk the same cells from many starts.

import java.util.*;
class Solution {
  public int[][] updateMatrix(int[][] mat) {
    int rows=mat.length, cols=mat[0].length;
    int[][] out=new int[rows][cols];
    int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    for (int sr=0; sr<rows; sr++) for (int sc=0; sc<cols; sc++) {
      if (mat[sr][sc]==0) continue;
      boolean[][] seen=new boolean[rows][cols];
      ArrayDeque<int[]> q=new ArrayDeque<int[]>();
      q.addLast(new int[]{sr,sc,0}); seen[sr][sc]=true;
      int d0=0;
      while (!q.isEmpty()) {
        int[] cur=q.pollFirst(); int r=cur[0],c=cur[1],d=cur[2];
        if (mat[r][c]==0) { d0=d; break; }
        for (int i=0;i<4;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols||seen[nr][nc]) continue;
          seen[nr][nc]=true; q.addLast(new int[]{nr,nc,d+1});
        }
      }
      out[sr][sc]=d0;
    }
    return out;
  }
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Multi-source BFS from all zeros. Each 1 is reached first by its nearest 0. One visit per cell.

import java.util.*;
class Solution {
  public int[][] updateMatrix(int[][] mat) {
    int rows=mat.length, cols=mat[0].length, inf=rows*cols;
    int[][] dist=new int[rows][cols];
    ArrayDeque<int[]> q=new ArrayDeque<int[]>();
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (mat[r][c]==0) { dist[r][c]=0; q.addLast(new int[]{r,c}); }
      else dist[r][c]=inf;
    }
    int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.isEmpty()) {
      int[] cur=q.pollFirst(); int r=cur[0],c=cur[1];
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (dist[nr][nc] <= dist[r][c]+1) continue;
        dist[nr][nc]=dist[r][c]+1; q.addLast(new int[]{nr,nc});
      }
    }
    return dist;
  }
}


// Method 3: More optimal
// Time: O(rc) | Space: O(1)
// Two DP sweeps. First pass uses top and left (already processed). Second pass uses bottom and right. You can write into the output matrix only; extra space is O(1) besides the answer. Same linear time, no queue.

class Solution {
  public int[][] updateMatrix(int[][] mat) {
    int rows=mat.length, cols=mat[0].length, inf=rows+cols;
    int[][] dist=new int[rows][cols];
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) dist[r][c]=mat[r][c]==0?0:inf;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (r>0) dist[r][c]=Math.min(dist[r][c], dist[r-1][c]+1);
      if (c>0) dist[r][c]=Math.min(dist[r][c], dist[r][c-1]+1);
    }
    for (int r=rows-1;r>=0;r--) for (int c=cols-1;c>=0;c--) {
      if (r+1<rows) dist[r][c]=Math.min(dist[r][c], dist[r+1][c]+1);
      if (c+1<cols) dist[r][c]=Math.min(dist[r][c], dist[r][c+1]+1);
    }
    return dist;
  }
}
