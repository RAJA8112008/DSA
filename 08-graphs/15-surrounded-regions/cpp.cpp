// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For each O, copy a visited matrix and DFS. If that blob never hits a border, flip those cells. Repeated walks over the same region.

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int rows=(int)board.size(); if (!rows) return;
    int cols=(int)board[0].size();
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> flipped(rows, vector<int>(cols));
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (board[r][c]!='O' || flipped[r][c]) continue;
      vector<vector<int>> seen(rows, vector<int>(cols));
      vector<pair<int,int>> cells, q; q.push_back({r,c}); seen[r][c]=1; bool border=false;
      while (!q.empty()) {
        auto cur=q.back(); q.pop_back(); int x=cur.first, y=cur.second; cells.push_back(cur);
        if (x==0||y==0||x==rows-1||y==cols-1) border=true;
        for (int i=0;i<4;i++) {
          int nx=x+dirs[i][0], ny=y+dirs[i][1];
          if (nx<0||ny<0||nx>=rows||ny>=cols) continue;
          if (seen[nx][ny] || board[nx][ny]!='O') continue;
          seen[nx][ny]=1; q.push_back({nx,ny});
        }
      }
      if (!border) for (auto cell : cells) board[cell.first][cell.second]='X';
      for (auto cell : cells) flipped[cell.first][cell.second]=1;
    }
  }
};


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// DFS/BFS from every border O and mark those cells (for example '#'). Then walk the board: leftover O is surrounded and becomes X; '#' is restored to O.

class Solution {
  int rows, cols;
  void dfs(vector<vector<char>>& board, int r, int c) {
    if (r<0||c<0||r>=rows||c>=cols) return;
    if (board[r][c]!='O') return;
    board[r][c]='#';
    dfs(board,r+1,c); dfs(board,r-1,c); dfs(board,r,c+1); dfs(board,r,c-1);
  }
public:
  void solve(vector<vector<char>>& board) {
    rows=(int)board.size(); if (!rows) return; cols=(int)board[0].size();
    for (int r=0;r<rows;r++) { dfs(board,r,0); dfs(board,r,cols-1); }
    for (int c=0;c<cols;c++) { dfs(board,0,c); dfs(board,rows-1,c); }
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (board[r][c]=='O') board[r][c]='X';
      else if (board[r][c]=='#') board[r][c]='O';
    }
  }
};


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Union-Find. Dummy node DUMMY represents 'touches border'. Union every O with its O neighbors, and union border O with DUMMY. Then flip O whose root is not DUMMY. No recursion.

class Solution {
  vector<int> parent;
  int find(int x) { while (parent[x]!=x) { parent[x]=parent[parent[x]]; x=parent[x]; } return x; }
  void unite(int a, int b) { int x=find(a), y=find(b); if (x!=y) parent[y]=x; }
public:
  void solve(vector<vector<char>>& board) {
    int rows=(int)board.size(); if (!rows) return; int cols=(int)board[0].size();
    int DUMMY=rows*cols; parent.resize(DUMMY+1);
    for (int i=0;i<=DUMMY;i++) parent[i]=i;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (board[r][c]!='O') continue;
      if (r==0||c==0||r==rows-1||c==cols-1) unite(r*cols+c, DUMMY);
      if (r+1<rows && board[r+1][c]=='O') unite(r*cols+c, (r+1)*cols+c);
      if (c+1<cols && board[r][c+1]=='O') unite(r*cols+c, r*cols+c+1);
    }
    int dummyRoot=find(DUMMY);
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++)
      if (board[r][c]=='O' && find(r*cols+c)!=dummyRoot) board[r][c]='X';
  }
};
