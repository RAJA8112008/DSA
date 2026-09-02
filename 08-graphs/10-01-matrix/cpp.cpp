// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For each 1, BFS with a fresh visited matrix until you hit a 0. You re-walk the same cells from many starts.

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows=(int)mat.size(), cols=(int)mat[0].size();
    vector<vector<int>> out(rows, vector<int>(cols));
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    for (int sr=0;sr<rows;sr++) for (int sc=0;sc<cols;sc++) {
      if (mat[sr][sc]==0) continue;
      vector<vector<int>> seen(rows, vector<int>(cols));
      queue<array<int,3>> q; q.push({sr,sc,0}); seen[sr][sc]=1;
      while (!q.empty()) {
        auto cur=q.front(); q.pop();
        int r=cur[0],c=cur[1],d=cur[2];
        if (mat[r][c]==0) { out[sr][sc]=d; break; }
        for (int i=0;i<4;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols||seen[nr][nc]) continue;
          seen[nr][nc]=1; q.push({nr,nc,d+1});
        }
      }
    }
    return out;
  }
};


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Multi-source BFS from all zeros. Each 1 is reached first by its nearest 0. One visit per cell.

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows=(int)mat.size(), cols=(int)mat[0].size(), inf=rows*cols;
    vector<vector<int>> dist(rows, vector<int>(cols, inf));
    queue<pair<int,int>> q;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (mat[r][c]==0) { dist[r][c]=0; q.push({r,c}); }
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()) {
      auto cur=q.front(); q.pop(); int r=cur.first,c=cur.second;
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (dist[nr][nc] <= dist[r][c]+1) continue;
        dist[nr][nc]=dist[r][c]+1; q.push({nr,nc});
      }
    }
    return dist;
  }
};


// Method 3: More optimal
// Time: O(rc) | Space: O(1)
// Two DP sweeps. First pass uses top and left (already processed). Second pass uses bottom and right. You can write into the output matrix only; extra space is O(1) besides the answer. Same linear time, no queue.

class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows=(int)mat.size(), cols=(int)mat[0].size(), inf=rows+cols;
    vector<vector<int>> dist(rows, vector<int>(cols));
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) dist[r][c]=mat[r][c]==0?0:inf;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (r>0) dist[r][c]=min(dist[r][c], dist[r-1][c]+1);
      if (c>0) dist[r][c]=min(dist[r][c], dist[r][c-1]+1);
    }
    for (int r=rows-1;r>=0;r--) for (int c=cols-1;c>=0;c--) {
      if (r+1<rows) dist[r][c]=min(dist[r][c], dist[r+1][c]+1);
      if (c+1<cols) dist[r][c]=min(dist[r][c], dist[r][c+1]+1);
    }
    return dist;
  }
};
