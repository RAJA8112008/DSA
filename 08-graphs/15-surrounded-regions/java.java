// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For each O, copy a visited matrix and DFS. If that blob never hits a border, flip those cells. Repeated walks over the same region.

class Solution {
  public void solve(char[][] board) {
    int rows=board.length; if (rows==0) return;
    int cols=board[0].length;
    int[][] dirs={{1,0},{-1,0},{0,1},{0,-1}};
    boolean[][] flipped=new boolean[rows][cols];
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (board[r][c]!='O' || flipped[r][c]) continue;
      boolean[][] seen=new boolean[rows][cols];
      java.util.ArrayList<int[]> cells=new java.util.ArrayList<int[]>();
      java.util.ArrayDeque<int[]> q=new java.util.ArrayDeque<int[]>();
      q.push(new int[]{r,c}); seen[r][c]=true; boolean border=false;
      while (!q.isEmpty()) {
        int[] cur=q.pop(); int x=cur[0], y=cur[1]; cells.add(cur);
        if (x==0||y==0||x==rows-1||y==cols-1) border=true;
        for (int i=0;i<4;i++) {
          int nx=x+dirs[i][0], ny=y+dirs[i][1];
          if (nx<0||ny<0||nx>=rows||ny>=cols) continue;
          if (seen[nx][ny] || board[nx][ny]!='O') continue;
          seen[nx][ny]=true; q.push(new int[]{nx,ny});
        }
      }
      if (!border) for (int[] cell : cells) board[cell[0]][cell[1]]='X';
      for (int[] cell : cells) flipped[cell[0]][cell[1]]=true;
    }
  }
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// DFS/BFS from every border O and mark those cells (for example '#'). Then walk the board: leftover O is surrounded and becomes X; '#' is restored to O.

class Solution {
  int rows, cols;
  void dfs(char[][] board, int r, int c) {
    if (r<0||c<0||r>=rows||c>=cols) return;
    if (board[r][c]!='O') return;
    board[r][c]='#';
    dfs(board,r+1,c); dfs(board,r-1,c); dfs(board,r,c+1); dfs(board,r,c-1);
  }
  public void solve(char[][] board) {
    rows=board.length; if (rows==0) return; cols=board[0].length;
    for (int r=0;r<rows;r++) { dfs(board,r,0); dfs(board,r,cols-1); }
    for (int c=0;c<cols;c++) { dfs(board,0,c); dfs(board,rows-1,c); }
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (board[r][c]=='O') board[r][c]='X';
      else if (board[r][c]=='#') board[r][c]='O';
    }
  }
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Union-Find. Dummy node DUMMY represents 'touches border'. Union every O with its O neighbors, and union border O with DUMMY. Then flip O whose root is not DUMMY. No recursion.

class Solution {
  int[] parent;
  int find(int x) { while (parent[x]!=x) { parent[x]=parent[parent[x]]; x=parent[x]; } return x; }
  void union(int a, int b) { int x=find(a), y=find(b); if (x!=y) parent[y]=x; }
  public void solve(char[][] board) {
    int rows=board.length; if (rows==0) return; int cols=board[0].length;
    int DUMMY=rows*cols; parent=new int[DUMMY+1];
    for (int i=0;i<=DUMMY;i++) parent[i]=i;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (board[r][c]!='O') continue;
      if (r==0||c==0||r==rows-1||c==cols-1) union(r*cols+c, DUMMY);
      if (r+1<rows && board[r+1][c]=='O') union(r*cols+c, (r+1)*cols+c);
      if (c+1<cols && board[r][c+1]=='O') union(r*cols+c, r*cols+c+1);
    }
    int dummyRoot=find(DUMMY);
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++)
      if (board[r][c]=='O' && find(r*cols+c)!=dummyRoot) board[r][c]='X';
  }
}
