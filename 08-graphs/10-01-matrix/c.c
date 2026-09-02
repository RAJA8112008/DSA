// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For each 1, BFS with a fresh visited matrix until you hit a 0. You re-walk the same cells from many starts.

#include <stdlib.h>
int** updateMatrix(int** mat, int rows, int cols, int* returnSize, int** returnColumnSizes) {
  int** out=(int**)malloc(sizeof(int*)*rows);
  for (int r=0;r<rows;r++) { out[r]=(int*)calloc(cols,sizeof(int)); }
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  int* seen=(int*)malloc(sizeof(int)*rows*cols);
  int* qr=(int*)malloc(sizeof(int)*rows*cols);
  int* qc=(int*)malloc(sizeof(int)*rows*cols);
  int* qd=(int*)malloc(sizeof(int)*rows*cols);
  for (int sr=0;sr<rows;sr++) for (int sc=0;sc<cols;sc++) {
    if (mat[sr][sc]==0) continue;
    for (int i=0;i<rows*cols;i++) seen[i]=0;
    int h=0,t=0; qr[t]=sr; qc[t]=sc; qd[t]=0; t++; seen[sr*cols+sc]=1;
    while (h<t) {
      int r=qr[h],c=qc[h],d=qd[h]; h++;
      if (mat[r][c]==0) { out[sr][sc]=d; break; }
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols||seen[nr*cols+nc]) continue;
        seen[nr*cols+nc]=1; qr[t]=nr; qc[t]=nc; qd[t]=d+1; t++;
      }
    }
  }
  *returnSize=rows; *returnColumnSizes=(int*)malloc(sizeof(int)*rows);
  for (int i=0;i<rows;i++) (*returnColumnSizes)[i]=cols;
  return out;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Multi-source BFS from all zeros. Each 1 is reached first by its nearest 0. One visit per cell.

#include <stdlib.h>
int** updateMatrix(int** mat, int rows, int cols, int* returnSize, int** returnColumnSizes) {
  int inf=rows*cols;
  int** dist=(int**)malloc(sizeof(int*)*rows);
  for (int r=0;r<rows;r++) { dist[r]=(int*)malloc(sizeof(int)*cols); for (int c=0;c<cols;c++) dist[r][c]=inf; }
  int* qr=(int*)malloc(sizeof(int)*rows*cols);
  int* qc=(int*)malloc(sizeof(int)*rows*cols);
  int h=0,t=0;
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (mat[r][c]==0) { dist[r][c]=0; qr[t]=r; qc[t]=c; t++; }
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  while (h<t) {
    int r=qr[h],c=qc[h]; h++;
    for (int i=0;i<4;i++) {
      int nr=r+dirs[i][0], nc=c+dirs[i][1];
      if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
      if (dist[nr][nc] <= dist[r][c]+1) continue;
      dist[nr][nc]=dist[r][c]+1; qr[t]=nr; qc[t]=nc; t++;
    }
  }
  *returnSize=rows; *returnColumnSizes=(int*)malloc(sizeof(int)*rows);
  for (int i=0;i<rows;i++) (*returnColumnSizes)[i]=cols;
  return dist;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(1)
// Two DP sweeps. First pass uses top and left (already processed). Second pass uses bottom and right. You can write into the output matrix only; extra space is O(1) besides the answer. Same linear time, no queue.

#include <stdlib.h>
int** updateMatrix(int** mat, int rows, int cols, int* returnSize, int** returnColumnSizes) {
  int inf=rows+cols;
  int** dist=(int**)malloc(sizeof(int*)*rows);
  for (int r=0;r<rows;r++) {
    dist[r]=(int*)malloc(sizeof(int)*cols);
    for (int c=0;c<cols;c++) dist[r][c]=mat[r][c]==0?0:inf;
  }
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
    if (r>0 && dist[r-1][c]+1<dist[r][c]) dist[r][c]=dist[r-1][c]+1;
    if (c>0 && dist[r][c-1]+1<dist[r][c]) dist[r][c]=dist[r][c-1]+1;
  }
  for (int r=rows-1;r>=0;r--) for (int c=cols-1;c>=0;c--) {
    if (r+1<rows && dist[r+1][c]+1<dist[r][c]) dist[r][c]=dist[r+1][c]+1;
    if (c+1<cols && dist[r][c+1]+1<dist[r][c]) dist[r][c]=dist[r][c+1]+1;
  }
  *returnSize=rows; *returnColumnSizes=(int*)malloc(sizeof(int)*rows);
  for (int i=0;i<rows;i++) (*returnColumnSizes)[i]=cols;
  return dist;
}
