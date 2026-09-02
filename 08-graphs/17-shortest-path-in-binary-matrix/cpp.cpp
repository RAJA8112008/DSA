// Method 1: Brute
// Time: O(8^{n²}) | Space: O(n²)
// DFS every simple path with a copied visited matrix. Keep the shortest length. Correct on a 2x2, exponential on a 20x20.

class Solution {
  int n, best;
  vector<pair<int,int>> dirs;
  void dfs(vector<vector<int>>& grid, int r, int c, int dist, vector<vector<int>> seen) {
    if (dist>=best) return;
    if (r==n-1 && c==n-1) { best=dist; return; }
    for (auto d : dirs) {
      int nr=r+d.first, nc=c+d.second;
      if (nr<0||nc<0||nr>=n||nc>=n) continue;
      if (grid[nr][nc]!=0 || seen[nr][nc]) continue;
      auto copy=seen; copy[nr][nc]=1;
      dfs(grid, nr, nc, dist+1, copy);
    }
  }
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    n=(int)grid.size(); if (grid[0][0]||grid[n-1][n-1]) return -1;
    for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr||dc) dirs.push_back({dr,dc});
    best=INT_MAX/4;
    vector<vector<int>> seen(n, vector<int>(n)); seen[0][0]=1;
    dfs(grid, 0, 0, 1, seen);
    return best>=INT_MAX/4 ? -1 : best;
  }
};


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// BFS from (0,0). First time you pop the end cell is the shortest length. Mark cells when you push so the queue stays small. 8 neighbors.

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=(int)grid.size(); if (grid[0][0]||grid[n-1][n-1]) return -1;
    queue<array<int,3>> q; q.push({0,0,1}); grid[0][0]=1;
    vector<pair<int,int>> dirs;
    for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr||dc) dirs.push_back({dr,dc});
    while (!q.empty()) {
      auto cur=q.front(); q.pop(); int r=cur[0],c=cur[1],d=cur[2];
      if (r==n-1 && c==n-1) return d;
      for (auto dir : dirs) {
        int nr=r+dir.first, nc=c+dir.second;
        if (nr<0||nc<0||nr>=n||nc>=n) continue;
        if (grid[nr][nc]!=0) continue;
        grid[nr][nc]=1; q.push({nr,nc,d+1});
      }
    }
    return -1;
  }
};


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Bidirectional BFS from start and end. When a neighbor sits in the other frontier, the two searches met. Fewer cells expanded on large open maps. Same worst-case O(n²).

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n=(int)grid.size(); if (grid[0][0]||grid[n-1][n-1]) return -1;
    if (n==1) return 1;
    vector<pair<int,int>> dirs;
    for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr||dc) dirs.push_back({dr,dc});
    auto key=[&](int r,int c){ return r*n+c; };
    vector<pair<int,int>> q1={{0,0}}, q2={{n-1,n-1}};
    unordered_map<int,int> d1, d2; d1[key(0,0)]=1; d2[key(n-1,n-1)]=1;
    while (!q1.empty() && !q2.empty()) {
      if (q1.size()>q2.size()) { swap(q1,q2); swap(d1,d2); }
      vector<pair<int,int>> next;
      for (auto cell : q1) {
        int r=cell.first, c=cell.second, id=key(r,c);
        for (auto dir : dirs) {
          int nr=r+dir.first, nc=c+dir.second;
          if (nr<0||nc<0||nr>=n||nc>=n) continue;
          if (grid[nr][nc]!=0) continue;
          int nid=key(nr,nc);
          if (d1.count(nid)) continue;
          if (d2.count(nid)) return d1[id]+d2[nid];
          d1[nid]=d1[id]+1; next.push_back({nr,nc});
        }
      }
      q1.swap(next);
    }
    return -1;
  }
};
