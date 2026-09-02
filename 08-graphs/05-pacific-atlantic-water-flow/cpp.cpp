// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// From every cell, DFS toward lower/equal neighbors with a fresh visited copy. Check if that walk hits a Pacific border and an Atlantic border. Extra copies plus a full search per cell.

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows=(int)heights.size(), cols=(int)heights[0].size();
    vector<vector<int>> ans;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for (int sr=0; sr<rows; sr++) for (int sc=0; sc<cols; sc++) {
      vector<vector<int>> seen(rows, vector<int>(cols));
      vector<pair<int,int>> st; st.push_back({sr,sc}); seen[sr][sc]=1;
      bool pac=false, atl=false;
      while (!st.empty()) {
        auto cur=st.back(); st.pop_back();
        int r=cur.first, c=cur.second;
        if (r==0||c==0) pac=true;
        if (r==rows-1||c==cols-1) atl=true;
        if (pac&&atl) break;
        for (int i=0;i<4;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
          if (seen[nr][nc] || heights[nr][nc] > heights[r][c]) continue;
          seen[nr][nc]=1; st.push_back({nr,nc});
        }
      }
      if (pac&&atl) ans.push_back({sr,sc});
    }
    return ans;
  }
};


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Reverse the flow: water climbs to equal or higher cells. DFS from all Pacific border cells, then from all Atlantic border cells. A cell in both visited sets is an answer. Each cell is processed a constant number of times.

class Solution {
  int rows, cols;
  void dfs(vector<vector<int>>& h, int r, int c, vector<vector<int>>& seen) {
    seen[r][c]=1;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for (int i=0;i<4;i++) {
      int nr=r+dirs[i][0], nc=c+dirs[i][1];
      if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
      if (seen[nr][nc] || h[nr][nc] < h[r][c]) continue;
      dfs(h, nr, nc, seen);
    }
  }
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    rows=(int)heights.size(); cols=(int)heights[0].size();
    vector<vector<int>> pac(rows, vector<int>(cols)), atl(rows, vector<int>(cols));
    for (int r=0;r<rows;r++) { dfs(heights,r,0,pac); dfs(heights,r,cols-1,atl); }
    for (int c=0;c<cols;c++) { dfs(heights,0,c,pac); dfs(heights,rows-1,c,atl); }
    vector<vector<int>> ans;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (pac[r][c]&&atl[r][c]) ans.push_back({r,c});
    return ans;
  }
};


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Same reverse idea with BFS from both oceans. No recursion on a huge grid. Complexity is still linear in cells. This is the interview upgrade when they worry about stack depth.

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows=(int)heights.size(), cols=(int)heights[0].size();
    vector<vector<int>> pac(rows, vector<int>(cols)), atl(rows, vector<int>(cols));
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int,int>> qp, qa;
    for (int r=0;r<rows;r++) { pac[r][0]=1; qp.push({r,0}); atl[r][cols-1]=1; qa.push({r,cols-1}); }
    for (int c=0;c<cols;c++) { pac[0][c]=1; qp.push({0,c}); atl[rows-1][c]=1; qa.push({rows-1,c}); }
    auto bfs=[&](queue<pair<int,int>>& q, vector<vector<int>>& seen) {
      while (!q.empty()) {
        auto cur=q.front(); q.pop(); int r=cur.first, c=cur.second;
        for (int i=0;i<4;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
          if (seen[nr][nc] || heights[nr][nc] < heights[r][c]) continue;
          seen[nr][nc]=1; q.push({nr,nc});
        }
      }
    };
    bfs(qp, pac); bfs(qa, atl);
    vector<vector<int>> ans;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (pac[r][c]&&atl[r][c]) ans.push_back({r,c});
    return ans;
  }
};
