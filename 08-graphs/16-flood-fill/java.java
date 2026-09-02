// Method 1: Brute
// Time: O(rc) | Space: O(rc)
// DFS with a brand-new visited matrix copy even though one matrix is enough. Extra memory, same walk. Shows the 'copy visited' habit you should drop.

class Solution {
  int rows, cols, old, color;
  void dfs(int[][] image, int r, int c, boolean[][] vis) {
    if (r<0||c<0||r>=rows||c>=cols) return;
    if (vis[r][c] || image[r][c]!=old) return;
    boolean[][] copy=new boolean[rows][cols];
    for (int i=0;i<rows;i++) copy[i]=vis[i].clone();
    copy[r][c]=true; vis[r][c]=true; image[r][c]=color;
    dfs(image,r+1,c,copy); dfs(image,r-1,c,copy); dfs(image,r,c+1,copy); dfs(image,r,c-1,copy);
  }
  public int[][] floodFill(int[][] image, int sr, int sc, int color) {
    old=image[sr][sc]; if (old==color) return image;
    this.color=color; rows=image.length; cols=image[0].length;
    dfs(image, sr, sc, new boolean[rows][cols]);
    return image;
  }
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// DFS from the start. Painting to the new color is the visited mark when old !== color. Each cell in the blob is painted once.

class Solution {
  int old, rows, cols, color;
  void dfs(int[][] image, int r, int c) {
    if (r<0||c<0||r>=rows||c>=cols) return;
    if (image[r][c]!=old) return;
    image[r][c]=color;
    dfs(image,r+1,c); dfs(image,r-1,c); dfs(image,r,c+1); dfs(image,r,c-1);
  }
  public int[][] floodFill(int[][] image, int sr, int sc, int color) {
    old=image[sr][sc]; if (old==color) return image;
    this.color=color; rows=image.length; cols=image[0].length;
    dfs(image, sr, sc);
    return image;
  }
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// BFS with a queue. Same linear bound, no recursive stack. Prefer this on a huge image so the call stack cannot overflow.

import java.util.*;
class Solution {
  public int[][] floodFill(int[][] image, int sr, int sc, int color) {
    int old=image[sr][sc]; if (old==color) return image;
    int rows=image.length, cols=image[0].length;
    ArrayDeque<int[]> q=new ArrayDeque<int[]>();
    q.addLast(new int[]{sr,sc}); image[sr][sc]=color;
    int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.isEmpty()) {
      int[] cur=q.pollFirst(); int r=cur[0], c=cur[1];
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (image[nr][nc]!=old) continue;
        image[nr][nc]=color; q.addLast(new int[]{nr,nc});
      }
    }
    return image;
  }
}
