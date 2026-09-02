// Method 1: Brute
// Time: O(n * n!) | Space: O(n^2)
// Generate every permutation of columns with extra copies. After a full permutation, scan every pair for a shared diagonal. Most permutations fail only at the end.

int ok(int* cols, int n) {
  int i, j;
  for (i = 0; i < n; i++) for (j = i + 1; j < n; j++)
    if ((i > j ? i - j : j - i) == (cols[i] > cols[j] ? cols[i] - cols[j] : cols[j] - cols[i])) return 0;
  return 1;
}


// Method 2: Optimal
// Time: O(n!) | Space: O(n^2)
// Place one queen per row. col[], d1[], d2[] mark attacks. If the square is free, mark, recurse row+1, unmark. Failures die as soon as a row has no square.

void go(int row, int n, char board[][20], int* col, int* d1, int* d2) {
  int c, k;
  if (row == n) {
    for (k = 0; k < n; k++) { board[k][n] = '\0'; printf("%s\n", board[k]); }
    printf("\n");
    return;
  }
  for (c = 0; c < n; c++) {
    if (col[c] || d1[row - c + n] || d2[row + c]) continue;
    col[c] = d1[row - c + n] = d2[row + c] = 1;
    board[row][c] = 'Q';
    go(row + 1, n, board, col, d1, d2);
    board[row][c] = '.';
    col[c] = d1[row - c + n] = d2[row + c] = 0;
  }
}


// Method 3: More optimal
// Time: O(n!) | Space: O(n^2)
// cols, diag, anti as bitmasks. available bits are the free columns. Take the lowest set bit, recurse with shifted diagonals. Same search, O(1) updates.

void go(int row, int n, int cols, int d1, int d2, char board[][20]) {
  int avail, bit, c, x, k;
  if (row == n) {
    for (k = 0; k < n; k++) { board[k][n] = '\0'; printf("%s\n", board[k]); }
    printf("\n");
    return;
  }
  avail = ((1 << n) - 1) & ~(cols | d1 | d2);
  while (avail) {
    bit = avail & -avail;
    avail ^= bit;
    c = 0; x = bit;
    while (x > 1) { x >>= 1; c++; }
    board[row][c] = 'Q';
    go(row + 1, n, cols | bit, (d1 | bit) << 1, (d2 | bit) >> 1, board);
    board[row][c] = '.';
  }
}
