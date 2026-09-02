// Method 1: Brute
// Time: O((rc)²) | Space: O(rc)
// Each minute, copy the grid and rot any fresh cell that touches a 2. Repeat until nothing changes. You scan the whole grid once per minute, up to rc minutes.

class Solution {
  public int orangesRotting(int[][] grid) {
    int rows=grid.length, cols=grid[0].length;
    int minutes=0;
    int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    while (true) {
      int[][] next=new int[rows][cols];
      for (int r=0;r<rows;r++) next[r]=grid[r].clone();
      boolean changed=false;
      for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
        if (grid[r][c]!=2) continue;
        for (int i=0;i<4;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
          if (grid[nr][nc]!=1) continue;
          next[nr][nc]=2; changed=true;
        }
      }
      if (!changed) break;
      grid=next; minutes++;
    }
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (grid[r][c]==1) return -1;
    return minutes;
  }
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Put every rotten orange in the queue at minute 0. BFS infects fresh neighbors. The last minute you used is the answer. If any 1 remains, return -1.

import java.util.*;
class Solution {
  public int orangesRotting(int[][] grid) {
    int rows=grid.length, cols=grid[0].length;
    ArrayDeque<int[]> q=new ArrayDeque<int[]>();
    int fresh=0;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (grid[r][c]==2) q.addLast(new int[]{r,c,0});
      if (grid[r][c]==1) fresh++;
    }
    int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    int minutes=0;
    while (!q.isEmpty()) {
      int[] cur=q.pollFirst(); int r=cur[0],c=cur[1],t=cur[2];
      minutes=t;
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (grid[nr][nc]!=1) continue;
        grid[nr][nc]=2; fresh--;
        q.addLast(new int[]{nr,nc,t+1});
      }
    }
    return fresh==0 ? minutes : -1;
  }
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Same multi-source BFS, but the grid itself stores time as 2 + minutes. No third tuple field. Space is still the queue. Linear in cells.

import java.util.*;
class Solution {
  public int orangesRotting(int[][] grid) {
    int rows=grid.length, cols=grid[0].length;
    ArrayDeque<int[]> q=new ArrayDeque<int[]>();
    int fresh=0;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (grid[r][c]==2) q.addLast(new int[]{r,c});
      else if (grid[r][c]==1) fresh++;
    }
    if (fresh==0) return 0;
    int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    int minutes=0;
    while (!q.isEmpty()) {
      int size=q.size(); boolean infected=false;
      for (int s=0;s<size;s++) {
        int[] cur=q.pollFirst(); int r=cur[0],c=cur[1];
        for (int i=0;i<4;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
          if (grid[nr][nc]!=1) continue;
          grid[nr][nc]=2; fresh--; infected=true; q.addLast(new int[]{nr,nc});
        }
      }
      if (infected) minutes++;
    }
    return fresh==0 ? minutes : -1;
  }
}
