// Method 1: Brute
// Time: O((rc)²) | Space: O(rc)
// Each minute, copy the grid and rot any fresh cell that touches a 2. Repeat until nothing changes. You scan the whole grid once per minute, up to rc minutes.

#include <stdlib.h>
int orangesRotting(int** grid, int rows, int cols) {
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  int minutes=0;
  int* next=(int*)malloc(sizeof(int)*rows*cols);
  while (1) {
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) next[r*cols+c]=grid[r][c];
    int changed=0;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
      if (grid[r][c]!=2) continue;
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (grid[nr][nc]!=1) continue;
        next[nr*cols+nc]=2; changed=1;
      }
    }
    if (!changed) break;
    for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) grid[r][c]=next[r*cols+c];
    minutes++;
  }
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) if (grid[r][c]==1) return -1;
  return minutes;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// Put every rotten orange in the queue at minute 0. BFS infects fresh neighbors. The last minute you used is the answer. If any 1 remains, return -1.

#include <stdlib.h>
int orangesRotting(int** grid, int rows, int cols) {
  int* qr=(int*)malloc(sizeof(int)*rows*cols);
  int* qc=(int*)malloc(sizeof(int)*rows*cols);
  int* qt=(int*)malloc(sizeof(int)*rows*cols);
  int h=0,t=0,fresh=0;
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
    if (grid[r][c]==2) { qr[t]=r; qc[t]=c; qt[t]=0; t++; }
    if (grid[r][c]==1) fresh++;
  }
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  int minutes=0;
  while (h<t) {
    int r=qr[h],c=qc[h],tm=qt[h]; h++; minutes=tm;
    for (int i=0;i<4;i++) {
      int nr=r+dirs[i][0], nc=c+dirs[i][1];
      if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
      if (grid[nr][nc]!=1) continue;
      grid[nr][nc]=2; fresh--;
      qr[t]=nr; qc[t]=nc; qt[t]=tm+1; t++;
    }
  }
  return fresh==0 ? minutes : -1;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Same multi-source BFS, but the grid itself stores time as 2 + minutes. No third tuple field. Space is still the queue. Linear in cells.

#include <stdlib.h>
int orangesRotting(int** grid, int rows, int cols) {
  int* qr=(int*)malloc(sizeof(int)*rows*cols);
  int* qc=(int*)malloc(sizeof(int)*rows*cols);
  int h=0,t=0,fresh=0;
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
    if (grid[r][c]==2) { qr[t]=r; qc[t]=c; t++; }
    else if (grid[r][c]==1) fresh++;
  }
  if (!fresh) return 0;
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  int minutes=0;
  while (h<t) {
    int size=t-h; int infected=0;
    for (int s=0;s<size;s++) {
      int r=qr[h], c=qc[h]; h++;
      for (int i=0;i<4;i++) {
        int nr=r+dirs[i][0], nc=c+dirs[i][1];
        if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
        if (grid[nr][nc]!=1) continue;
        grid[nr][nc]=2; fresh--; infected=1; qr[t]=nr; qc[t]=nc; t++;
      }
    }
    if (infected) minutes++;
  }
  return fresh==0 ? minutes : -1;
}
