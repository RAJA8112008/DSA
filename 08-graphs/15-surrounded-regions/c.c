// Method 1: Brute
// Time: O(r²c²) | Space: O(rc)
// For each O, copy a visited matrix and DFS. If that blob never hits a border, flip those cells. Repeated walks over the same region.

#include <stdlib.h>
#include <string.h>
void solve(char** board, int rows, int cols) {
  if (!rows) return;
  int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
  int* flipped=(int*)calloc(rows*cols,sizeof(int));
  int* seen=(int*)malloc(sizeof(int)*rows*cols);
  int* sx=(int*)malloc(sizeof(int)*rows*cols);
  int* sy=(int*)malloc(sizeof(int)*rows*cols);
  int* cx=(int*)malloc(sizeof(int)*rows*cols);
  int* cy=(int*)malloc(sizeof(int)*rows*cols);
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
    if (board[r][c]!='O' || flipped[r*cols+c]) continue;
    memset(seen,0,sizeof(int)*rows*cols);
    int sn=0, cn=0; sx[sn]=r; sy[sn]=c; sn++; seen[r*cols+c]=1; int border=0;
    while (sn) {
      int x=sx[--sn], y=sy[sn]; cx[cn]=x; cy[cn]=y; cn++;
      if (x==0||y==0||x==rows-1||y==cols-1) border=1;
      for (int i=0;i<4;i++) {
        int nx=x+dirs[i][0], ny=y+dirs[i][1];
        if (nx<0||ny<0||nx>=rows||ny>=cols) continue;
        if (seen[nx*cols+ny] || board[nx][ny]!='O') continue;
        seen[nx*cols+ny]=1; sx[sn]=nx; sy[sn]=ny; sn++;
      }
    }
    if (!border) for (int i=0;i<cn;i++) board[cx[i]][cy[i]]='X';
    for (int i=0;i<cn;i++) flipped[cx[i]*cols+cy[i]]=1;
  }
}


// Method 2: Optimal
// Time: O(rc) | Space: O(rc)
// DFS/BFS from every border O and mark those cells (for example '#'). Then walk the board: leftover O is surrounded and becomes X; '#' is restored to O.

int rows_s, cols_s;
void dfs_sol(char** board, int r, int c) {
  if (r<0||c<0||r>=rows_s||c>=cols_s) return;
  if (board[r][c]!='O') return;
  board[r][c]='#';
  dfs_sol(board,r+1,c); dfs_sol(board,r-1,c); dfs_sol(board,r,c+1); dfs_sol(board,r,c-1);
}
void solve(char** board, int rows, int cols) {
  if (!rows) return;
  rows_s=rows; cols_s=cols;
  for (int r=0;r<rows;r++) { dfs_sol(board,r,0); dfs_sol(board,r,cols-1); }
  for (int c=0;c<cols;c++) { dfs_sol(board,0,c); dfs_sol(board,rows-1,c); }
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
    if (board[r][c]=='O') board[r][c]='X';
    else if (board[r][c]=='#') board[r][c]='O';
  }
}


// Method 3: More optimal
// Time: O(rc) | Space: O(rc)
// Union-Find. Dummy node DUMMY represents 'touches border'. Union every O with its O neighbors, and union border O with DUMMY. Then flip O whose root is not DUMMY. No recursion.

#include <stdlib.h>
int find_sol(int* p, int x) { while (p[x]!=x) { p[x]=p[p[x]]; x=p[x]; } return x; }
void solve(char** board, int rows, int cols) {
  if (!rows) return;
  int DUMMY=rows*cols;
  int* parent=(int*)malloc(sizeof(int)*(DUMMY+1));
  for (int i=0;i<=DUMMY;i++) parent[i]=i;
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++) {
    if (board[r][c]!='O') continue;
    if (r==0||c==0||r==rows-1||c==cols-1) {
      int x=find_sol(parent,r*cols+c), y=find_sol(parent,DUMMY); if (x!=y) parent[y]=x;
    }
    if (r+1<rows && board[r+1][c]=='O') {
      int x=find_sol(parent,r*cols+c), y=find_sol(parent,(r+1)*cols+c); if (x!=y) parent[y]=x;
    }
    if (c+1<cols && board[r][c+1]=='O') {
      int x=find_sol(parent,r*cols+c), y=find_sol(parent,r*cols+c+1); if (x!=y) parent[y]=x;
    }
  }
  int dummyRoot=find_sol(parent, DUMMY);
  for (int r=0;r<rows;r++) for (int c=0;c<cols;c++)
    if (board[r][c]=='O' && find_sol(parent, r*cols+c)!=dummyRoot) board[r][c]='X';
}
