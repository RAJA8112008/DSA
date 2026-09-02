// Method 1: Brute
// Time: O(rc) | Space: O(rc)
// DFS with a brand-new visited matrix copy even though one matrix is enough. Extra memory, same walk. Shows the 'copy visited' habit you should drop.

#include <stdlib.h>
#include <string.h>
int rows_f, cols_f, old_f, color_f;
void dfs_ff(int** image, int r, int c, int* vis) {
  if (r<0||c<0||r>=rows_f||c>=cols_f) return;
  if (vis[r*cols_f+c] || image[r][c]!=old_f) return;
  int* copy=(int*)malloc(sizeof(int)*rows_f*cols_f);
  memcpy(copy, vis, sizeof(int)*rows_f*cols_f);
  copy[r*cols_f+c]=1; vis[r*cols_f+c]=1; image[r][c]=color_f;
  dfs_ff(image,r+1,c,copy); dfs_ff(image,r-1,c,copy); dfs_ff(image,r,c+1,copy); dfs_ff(image,r,c-1,copy);
  free(copy);
}
int** floodFill(int** image, int rows, int cols, int sr, int sc, int color) {
  old_f=image[sr][sc]; if (old_f==color) return image;
  color_f=color; rows_f=rows; cols_f=cols;
  int* vis=(int*)calloc(rows*cols,sizeof(int));
  dfs_ff(image, sr, sc, vis);
  return image;
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// DFS from the start. Painting to the new color is the visited mark when old !== color. Each cell in the blob is painted once.

int old_f2, rows_f2, cols_f2, color_f2;
void dfs_ff2(int** image, int r, int c) {
  if (r<0||c<0||r>=rows_f2||c>=cols_f2) return;
  if (image[r][c]!=old_f2) return;
  image[r][c]=color_f2;
  dfs_ff2(image,r+1,c); dfs_ff2(image,r-1,c); dfs_ff2(image,r,c+1); dfs_ff2(image,r,c-1);
}
int** floodFill(int** image, int rows, int cols, int sr, int sc, int color) {
  old_f2=image[sr][sc]; if (old_f2==color) return image;
  color_f2=color; rows_f2=rows; cols_f2=cols;
  dfs_ff2(image, sr, sc);
  return image;
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// BFS with a queue. Same linear bound, no recursive stack. Prefer this on a huge image so the call stack cannot overflow.

#include <stdlib.h>
int** floodFill(int** image, int rows, int cols, int sr, int sc, int color) {
  int old=image[sr][sc]; if (old==color) return image;
  int* qr=(int*)malloc(sizeof(int)*rows*cols);
  int* qc=(int*)malloc(sizeof(int)*rows*cols);
  int h=0,t=0; qr[t]=sr; qc[t]=sc; t++; image[sr][sc]=color;
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  while (h<t) {
    int r=qr[h], c=qc[h]; h++;
    for (int i=0;i<4;i++) {
      int nr=r+dirs[i][0], nc=c+dirs[i][1];
      if (nr<0||nc<0||nr>=rows||nc>=cols) continue;
      if (image[nr][nc]!=old) continue;
      image[nr][nc]=color; qr[t]=nr; qc[t]=nc; t++;
    }
  }
  return image;
}
