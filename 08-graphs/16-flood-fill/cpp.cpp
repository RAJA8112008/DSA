// Method 1: Brute
// Time: O(rc) | Space: O(rc)
// DFS with a brand-new visited matrix copy even though one matrix is enough. Extra memory, same walk. Shows the 'copy visited' habit you should drop.

class Solution {
  int rows, cols, old, color;
  void dfs(vector<vector<int>>& image, int r, int c, vector<vector<int>> vis) {
    if (r<0||c<0||r>=rows||c>=cols) return;
    if (vis[r][c] || image[r][c]!=old) return;
    auto copy=vis; copy[r][c]=1; vis[r][c]=1; image[r][c]=color;
    dfs(image,r+1,c,copy); dfs(image,r-1,c,copy); dfs(image,r,c+1,copy); dfs(image,r,c-1,copy);
  }
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    old=image[sr][sc]; if (old==color) return image;
    this->color=color; rows=(int)image.size(); cols=(int)image[0].size();
    dfs(image, sr, sc, vector<vector<int>>(rows, vector<int>(cols)));
    return image;
  }
};


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// DFS from the start. Painting to the new color is the visited mark when old !== color. Each cell in the blob is painted once.

class Solution {
  int old, rows, cols, color;
  void dfs(vector<vector<int>>& image, int r, int c) {
    if (r<0||c<0||r>=rows||c>=cols) return;
    if (image[r][c]!=old) return;
    image[r][c]=color;
    dfs(image,r+1,c); dfs(image,r-1,c); dfs(image,r,c+1); dfs(image,r,c-1);
  }
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    old=image[sr][sc]; if (old==color) return image;
    this->color=color; rows=(int)image.size(); cols=(int)image[0].size();
    dfs(image, sr, sc);
    return image;
  }
};


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// BFS with a queue. Same linear bound, no recursive stack. Prefer this on a huge image so the call stack cannot overflow.

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int old=image[sr][sc]; if (old==color) return image;
    int rows=(int)image.size(), cols=(int)image[0].size();
    queue<pair<int,int>> q; q.push({sr,sc}); image[sr][sc]=color;
    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    while (!q.empty()) {
      auto cur=q.front(); q.pop(); int r=cur.first, c=cur.second;
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (image[nr][nc]!=old) continue;
        image[nr][nc]=color; q.push({nr,nc});
      }
    }
    return image;
  }
};
