// Method 1: Brute
// Time: O(8^{n²}) | Space: O(n²)
// DFS every simple path with a copied visited matrix. Keep the shortest length. Correct on a 2x2, exponential on a 20x20.

#include <stdlib.h>
#include <string.h>
#include <limits.h>
int n_sp, best_sp, dirs_sp[8][2];
void dfs_sp(int** grid, int r, int c, int dist, int* seen) {
  if (dist>=best_sp) return;
  if (r==n_sp-1 && c==n_sp-1) { best_sp=dist; return; }
  for (int i=0;i<8;i++) {
    int nr=r+dirs_sp[i][0], nc=c+dirs_sp[i][1];
    if (nr<0||nc<0||nr>=n_sp||nc>=n_sp) continue;
    if (grid[nr][nc]!=0 || seen[nr*n_sp+nc]) continue;
    int* copy=(int*)malloc(sizeof(int)*n_sp*n_sp);
    memcpy(copy, seen, sizeof(int)*n_sp*n_sp); copy[nr*n_sp+nc]=1;
    dfs_sp(grid, nr, nc, dist+1, copy);
    free(copy);
  }
}
int shortestPathBinaryMatrix(int** grid, int n) {
  n_sp=n; if (grid[0][0]||grid[n-1][n-1]) return -1;
  int k=0; for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr||dc) { dirs_sp[k][0]=dr; dirs_sp[k][1]=dc; k++; }
  best_sp=INT_MAX/4;
  int* seen=(int*)calloc(n*n,sizeof(int)); seen[0]=1;
  dfs_sp(grid, 0, 0, 1, seen);
  return best_sp>=INT_MAX/4 ? -1 : best_sp;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// BFS from (0,0). First time you pop the end cell is the shortest length. Mark cells when you push so the queue stays small. 8 neighbors.

#include <stdlib.h>
int shortestPathBinaryMatrix(int** grid, int n) {
  if (grid[0][0]||grid[n-1][n-1]) return -1;
  int dirs[8][2]; int k=0;
  for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr||dc) { dirs[k][0]=dr; dirs[k][1]=dc; k++; }
  int* qr=(int*)malloc(sizeof(int)*n*n);
  int* qc=(int*)malloc(sizeof(int)*n*n);
  int* qd=(int*)malloc(sizeof(int)*n*n);
  int h=0,t=0; qr[t]=0; qc[t]=0; qd[t]=1; t++; grid[0][0]=1;
  while (h<t) {
    int r=qr[h], c=qc[h], d=qd[h]; h++;
    if (r==n-1 && c==n-1) return d;
    for (int i=0;i<8;i++) {
      int nr=r+dirs[i][0], nc=c+dirs[i][1];
      if (nr<0||nc<0||nr>=n||nc>=n) continue;
      if (grid[nr][nc]!=0) continue;
      grid[nr][nc]=1; qr[t]=nr; qc[t]=nc; qd[t]=d+1; t++;
    }
  }
  return -1;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Bidirectional BFS from start and end. When a neighbor sits in the other frontier, the two searches met. Fewer cells expanded on large open maps. Same worst-case O(n²).

#include <stdlib.h>
int shortestPathBinaryMatrix(int** grid, int n) {
  if (grid[0][0]||grid[n-1][n-1]) return -1;
  if (n==1) return 1;
  int dirs[8][2], k=0;
  for (int dr=-1;dr<=1;dr++) for (int dc=-1;dc<=1;dc++) if (dr||dc) { dirs[k][0]=dr; dirs[k][1]=dc; k++; }
  int* d1=(int*)malloc(sizeof(int)*n*n); int* d2=(int*)malloc(sizeof(int)*n*n);
  for (int i=0;i<n*n;i++) { d1[i]=-1; d2[i]=-1; }
  int* q1r=(int*)malloc(sizeof(int)*n*n); int* q1c=(int*)malloc(sizeof(int)*n*n); int n1=1; q1r[0]=0; q1c[0]=0; d1[0]=1;
  int* q2r=(int*)malloc(sizeof(int)*n*n); int* q2c=(int*)malloc(sizeof(int)*n*n); int n2=1; q2r[0]=n-1; q2c[0]=n-1; d2[(n-1)*n+n-1]=1;
  while (n1 && n2) {
    if (n1>n2) { int* tr=q1r; q1r=q2r; q2r=tr; int* tc=q1c; q1c=q2c; q2c=tc; int tn=n1; n1=n2; n2=tn; int* td=d1; d1=d2; d2=td; }
    int* nr_=(int*)malloc(sizeof(int)*n*n); int* nc_=(int*)malloc(sizeof(int)*n*n); int nn=0;
    for (int i=0;i<n1;i++) {
      int r=q1r[i], c=q1c[i], id=r*n+c;
      for (int t=0;t<8;t++) {
        int nr=r+dirs[t][0], nc=c+dirs[t][1];
        if (nr<0||nc<0||nr>=n||nc>=n) continue;
        if (grid[nr][nc]!=0) continue;
        int nid=nr*n+nc;
        if (d1[nid]!=-1) continue;
        if (d2[nid]!=-1) return d1[id]+d2[nid];
        d1[nid]=d1[id]+1; nr_[nn]=nr; nc_[nn]=nc; nn++;
      }
    }
    free(q1r); free(q1c); q1r=nr_; q1c=nc_; n1=nn;
  }
  return -1;
}
