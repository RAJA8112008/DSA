// Method 1: Brute
// Time: O((rc)²) | Space: O(rc)
// Each minute, copy the grid and rot any fresh cell that touches a 2. Repeat until nothing changes. You scan the whole grid once per minute, up to rc minutes.

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int rows=(int)grid.size(), cols=(int)grid[0].size();
    int minutes=0;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while (true) {
      auto next=grid; bool changed=false;
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
};


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Put every rotten orange in the queue at minute 0. BFS infects fresh neighbors. The last minute you used is the answer. If any 1 remains, return -1.

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int rows=(int)grid.size(), cols=(int)grid[0].size();
    queue<array<int,3>> q; int fresh=0;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (grid[r][c]==2) q.push({r,c,0});
      if (grid[r][c]==1) fresh++;
    }
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int minutes=0;
    while (!q.empty()) {
      auto cur=q.front(); q.pop();
      int r=cur[0],c=cur[1],t=cur[2]; minutes=t;
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (grid[nr][nc]!=1) continue;
        grid[nr][nc]=2; fresh--;
        q.push({nr,nc,t+1});
      }
    }
    return fresh==0 ? minutes : -1;
  }
};


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Same multi-source BFS, but the grid itself stores time as 2 + minutes. No third tuple field. Space is still the queue. Linear in cells.

class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    int rows=(int)grid.size(), cols=(int)grid[0].size();
    queue<pair<int,int>> q; int fresh=0;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (grid[r][c]==2) q.push({r,c});
      else if (grid[r][c]==1) fresh++;
    }
    if (!fresh) return 0;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int minutes=0;
    while (!q.empty()) {
      int size=(int)q.size(); bool infected=false;
      for (int s=0;s<size;s++) {
        auto cur=q.front(); q.pop(); int r=cur.first,c=cur.second;
        for (int i=0;i<4;i++) {
          int nr=r+dirs[i][0], nc=c+dirs[i][1];
          if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
          if (grid[nr][nc]!=1) continue;
          grid[nr][nc]=2; fresh--; infected=true; q.push({nr,nc});
        }
      }
      if (infected) minutes++;
    }
    return fresh==0 ? minutes : -1;
  }
};
