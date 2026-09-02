// Method 1: Brute
// Time: O(8^{n²}) | Space: O(n²)
// DFS every simple path with a copied visited matrix. Keep the shortest length. Correct on a 2x2, exponential on a 20x20.

class Solution {
  int n, best;
  int[][] dirs=new int[8][2];
  void dfs(int[][] grid, int r, int c, int dist, boolean[][] seen) {
    if (dist>=best) return;
    if (r==n-1 && c==n-1) { best=dist; return; }
    for (int i=0;i<8;i++) {
      int nr=r+dirs[i][0], nc=c+dirs[i][1];
      if (nr<0||nc<0||nr>=n||nc>=n) continue;
      if (grid[nr][nc]!=0 || seen[nr][nc]) continue;
      boolean[][] copy=new boolean[n][n];
      for (int k=0;k<n;k++) copy[k]=seen[k].clone();
      copy[nr][nc]=true;
      dfs(grid, nr, nc, dist+1, copy);
    }
  }
  public int shortestPathBinaryMatrix(int[][] grid) {
    n=grid.length; if (grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
    int k=0; for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr!=0||dc!=0) dirs[k++]=new int[]{dr,dc};
    best=Integer.MAX_VALUE/4;
    boolean[][] seen=new boolean[n][n]; seen[0][0]=true;
    dfs(grid, 0, 0, 1, seen);
    return best>=Integer.MAX_VALUE/4 ? -1 : best;
  }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// BFS from (0,0). First time you pop the end cell is the shortest length. Mark cells when you push so the queue stays small. 8 neighbors.

import java.util.*;
class Solution {
  public int shortestPathBinaryMatrix(int[][] grid) {
    int n=grid.length; if (grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
    ArrayDeque<int[]> q=new ArrayDeque<int[]>();
    q.addLast(new int[]{0,0,1}); grid[0][0]=1;
    int[][] dirs=new int[8][2]; int k=0;
    for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr!=0||dc!=0) dirs[k++]=new int[]{dr,dc};
    while (!q.isEmpty()) {
      int[] cur=q.pollFirst(); int r=cur[0],c=cur[1],d=cur[2];
      if (r==n-1 && c==n-1) return d;
      for (int i=0;i<8;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=n||nc>=n) continue;
        if (grid[nr][nc]!=0) continue;
        grid[nr][nc]=1; q.addLast(new int[]{nr,nc,d+1});
      }
    }
    return -1;
  }
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Bidirectional BFS from start and end. When a neighbor sits in the other frontier, the two searches met. Fewer cells expanded on large open maps. Same worst-case O(n²).

import java.util.*;
class Solution {
  public int shortestPathBinaryMatrix(int[][] grid) {
    int n=grid.length; if (grid[0][0]!=0 || grid[n-1][n-1]!=0) return -1;
    if (n==1) return 1;
    int[][] dirs=new int[8][2]; int k=0;
    for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr!=0||dc!=0) dirs[k++]=new int[]{dr,dc};
    List<int[]> q1=new ArrayList<int[]>(), q2=new ArrayList<int[]>();
    q1.add(new int[]{0,0}); q2.add(new int[]{n-1,n-1});
    Map<Integer,Integer> d1=new HashMap<Integer,Integer>(), d2=new HashMap<Integer,Integer>();
    d1.put(0,1); d2.put((n-1)*n+(n-1),1);
    while (!q1.isEmpty() && !q2.isEmpty()) {
      if (q1.size()>q2.size()) { List<int[]> tq=q1; q1=q2; q2=tq; Map<Integer,Integer> td=d1; d1=d2; d2=td; }
      List<int[]> next=new ArrayList<int[]>();
      for (int[] cell : q1) {
        int r=cell[0], c=cell[1], id=r*n+c;
        for (int i=0;i<8;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=n||nc>=n) continue;
          if (grid[nr][nc]!=0) continue;
          int nid=nr*n+nc;
          if (d1.containsKey(nid)) continue;
          if (d2.containsKey(nid)) return d1.get(id)+d2.get(nid);
          d1.put(nid, d1.get(id)+1); next.add(new int[]{nr,nc});
        }
      }
      q1=next;
    }
    return -1;
  }
}
