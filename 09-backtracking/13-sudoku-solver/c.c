// Method 1: Brute
// Time: O(9^{e}) | Space: O(e)
// e empty cells. Each guess clones the board and scans from scratch. Extra copies on every node. Correct but memory-heavy.

int valid(char b[9][9], int r, int c, char ch) {
  int i;
  for (i = 0; i < 9; i++) {
    if (b[r][i] == ch || b[i][c] == ch) return 0;
    if (b[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) return 0;
  }
  return 1;
}
void copyBoard(char dst[9][9], char src[9][9]) {
  int i, j;
  for (i = 0; i < 9; i++) for (j = 0; j < 9; j++) dst[i][j] = src[i][j];
}


// Method 2: Optimal
// Time: O(9^{e}) | Space: O(e)
// Write a digit in place, recurse, write '.'. isValid scans the row, column, and box. No extra boards. First empty cell, left to right.

int valid(char board[9][9], int r, int c, char ch) {
  int i;
  for (i = 0; i < 9; i++) {
    if (board[r][i] == ch || board[i][c] == ch) return 0;
    if (board[(r / 3) * 3 + i / 3][(c / 3) * 3 + i % 3] == ch) return 0;
  }
  return 1;
}
int go(char board[9][9]) {
  int r, c; char ch;
  for (r = 0; r < 9; r++) for (c = 0; c < 9; c++) {
    if (board[r][c] != '.') continue;
    for (ch = '1'; ch <= '9'; ch++) {
      if (!valid(board, r, c, ch)) continue;
      board[r][c] = ch;
      if (go(board)) return 1;
      board[r][c] = '.';
    }
    return 0;
  }
  return 1;
}


// Method 3: More optimal
// Time: O(9^{e}) | Space: O(e)
// row[], col[], box[] bitmasks. Pick the empty cell with the fewest remaining digits (MRV) so dead ends die sooner. Toggle bits instead of scanning 9 cells.

int popcount(int x) { int n = 0; while (x) { x &= x - 1; n++; } return n; }
int goBits(char board[9][9], int k, int empty[][2], int nempty, int* row, int* col, int* box) {
  int best, bestN, i, r, c, b, avail, bit, d, x, t;
  if (k == nempty) return 1;
  best = k; bestN = 10;
  for (i = k; i < nempty; i++) {
    r = empty[i][0]; c = empty[i][1];
    t = 9 - popcount(row[r] | col[c] | box[(r / 3) * 3 + c / 3]);
    if (t < bestN) { bestN = t; best = i; }
  }
  r = empty[k][0]; c = empty[k][1]; empty[k][0] = empty[best][0]; empty[k][1] = empty[best][1]; empty[best][0] = r; empty[best][1] = c;
  r = empty[k][0]; c = empty[k][1]; b = (r / 3) * 3 + c / 3;
  avail = ((1 << 9) - 1) ^ (row[r] | col[c] | box[b]);
  while (avail) {
    bit = avail & -avail; avail ^= bit;
    d = 1; x = bit; while (x > 1) { x >>= 1; d++; }
    board[r][c] = (char)('0' + d);
    row[r] |= bit; col[c] |= bit; box[b] |= bit;
    if (goBits(board, k + 1, empty, nempty, row, col, box)) return 1;
    row[r] ^= bit; col[c] ^= bit; box[b] ^= bit;
    board[r][c] = '.';
  }
  return 0;
}
