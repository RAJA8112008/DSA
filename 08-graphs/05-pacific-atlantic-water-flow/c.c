// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// From every cell, DFS toward lower/equal neighbors with a fresh visited copy. Check if that walk hits a Pacific border and an Atlantic border. Extra copies plus a full search per cell.

#include <stdlib.h>
int** pacificAtlantic(int** heights, int rows, int cols, int* returnSize, int** returnColumnSizes) {
  int** ans = (int**)malloc(sizeof(int*)*rows*cols);
  int p = 0;
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  int* seen = (int*)malloc(sizeof(int)*rows*cols);
  int* stx=(int*)malloc(sizeof(int)*rows*cols);
  int* sty=(int*)malloc(sizeof(int)*rows*cols);
  for (int sr=0; sr<rows; sr++) for (int sc=0; sc<cols; sc++) {
    for (int i=0;i<rows*cols;i++) seen[i]=0;
    int sn=0; stx[sn]=sr; sty[sn]=sc; sn++; seen[sr*cols+sc]=1;
    int pac=0, atl=0;
    while (sn) {
      int r=stx[--sn], c=sty[sn];
      if (r==0||c==0) pac=1;
      if (r==rows-1||c==cols-1) atl=1;
      if (pac&&atl) break;
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (seen[nr*cols+nc] || heights[nr][nc] > heights[r][c]) continue;
        seen[nr*cols+nc]=1; stx[sn]=nr; sty[sn]=nc; sn++;
      }
    }
    if (pac&&atl) { ans[p]=(int*)malloc(sizeof(int)*2); ans[p][0]=sr; ans[p][1]=sc; p++; }
  }
  *returnSize = p;
  *returnColumnSizes = (int*)malloc(sizeof(int)*p);
  for (int i=0;i<p;i++) (*returnColumnSizes)[i]=2;
  return ans;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Reverse the flow: water climbs to equal or higher cells. DFS from all Pacific border cells, then from all Atlantic border cells. A cell in both visited sets is an answer. Each cell is processed a constant number of times.

#include <stdlib.h>
int rows_p, cols_p;
void dfs_pa(int** h, int r, int c, int* seen) {
  seen[r*cols_p+c]=1;
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  for (int i=0;i<4;i++) {
    int nr=r+dirs[i][0], nc=c+dirs[i][1];
    if (nr<0||nc<0||nr>=rows_p||nc>=cols_p) continue;
    if (seen[nr*cols_p+nc] || h[nr][nc] < h[r][c]) continue;
    dfs_pa(h, nr, nc, seen);
  }
}
int** pacificAtlantic(int** heights, int rows, int cols, int* returnSize, int** returnColumnSizes) {
  rows_p=rows; cols_p=cols;
  int* pac=(int*)calloc(rows*cols,sizeof(int));
  int* atl=(int*)calloc(rows*cols,sizeof(int));
  for (int r=0;r<rows;r++) { dfs_pa(heights,r,0,pac); dfs_pa(heights,r,cols-1,atl); }
  for (int c=0;c<cols;c++) { dfs_pa(heights,0,c,pac); dfs_pa(heights,rows-1,c,atl); }
  int** ans=(int**)malloc(sizeof(int*)*rows*cols); int p=0;
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (pac[r*cols+c]&&atl[r*cols+c]) {
    ans[p]=(int*)malloc(sizeof(int)*2); ans[p][0]=r; ans[p][1]=c; p++;
  }
  *returnSize=p; *returnColumnSizes=(int*)malloc(sizeof(int)*p);
  for (int i=0;i<p;i++) (*returnColumnSizes)[i]=2;
  return ans;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Same reverse idea with BFS from both oceans. No recursion on a huge grid. Complexity is still linear in cells. This is the interview upgrade when they worry about stack depth.

#include <stdlib.h>
void bfs_pa(int** h, int rows, int cols, int* qr, int* qc, int h0, int t, int* seen) {
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  int hd=h0;
  while (hd<t) {
    int r=qr[hd], c=qc[hd]; hd++;
    for (int i=0;i<4;i++) {
      int nr=r+dirs[i][0], nc=c+dirs[i][1];
      if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
      if (seen[nr*cols+nc] || h[nr][nc] < h[r][c]) continue;
      seen[nr*cols+nc]=1; qr[t]=nr; qc[t]=c; /* bug: should be nc */
      qc[t]=nc; t++;
    }
  }
}
int** pacificAtlantic(int** heights, int rows, int cols, int* returnSize, int** returnColumnSizes) {
  int* pac=(int*)calloc(rows*cols,sizeof(int));
  int* atl=(int*)calloc(rows*cols,sizeof(int));
  int* qr=(int*)malloc(sizeof(int)*rows*cols*2);
  int* qc=(int*)malloc(sizeof(int)*rows*cols*2);
  int t=0;
  for (int r=0;r<rows;r++) { pac[r*cols+0]=1; qr[t]=r; qc[t]=0; t++; }
  int t2=0;
  int* qr2=(int*)malloc(sizeof(int)*rows*cols*2);
  int* qc2=(int*)malloc(sizeof(int)*rows*cols*2);
  for (int r=0;r<rows;r++) { atl[r*cols+cols-1]=1; qr2[t2]=r; qc2[t2]=cols-1; t2++; }
  for (int c=0;c<cols;c++) { pac[0*cols+c]=1; qr[t]=0; qc[t]=c; t++; atl[(rows-1)*cols+c]=1; qr2[t2]=rows-1; qc2[t2]=c; t2++; }
  bfs_pa(heights, rows, cols, qr, qc, 0, t, pac);
  bfs_pa(heights, rows, cols, qr2, qc2, 0, t2, atl);
  int** ans=(int**)malloc(sizeof(int*)*rows*cols); int p=0;
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (pac[r*cols+c]&&atl[r*cols+c]) {
    ans[p]=(int*)malloc(sizeof(int)*2); ans[p][0]=r; ans[p][1]=c; p++;
  }
  *returnSize=p; *returnColumnSizes=(int*)malloc(sizeof(int)*p);
  for (int i=0;i<p;i++) (*returnColumnSizes)[i]=2;
  return ans;
}
