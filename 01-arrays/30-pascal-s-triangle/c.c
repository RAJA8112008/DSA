// Method 1: Brute
// Time: O(n³) with naive fact | Space: O(n²)
// Each cell is nCr. Computing factorials from scratch per cell is slow and overflows. Picture is right, implementation is not the interview one.

long nCr(int n, int r) {
  long a = 1, b = 1; int i;
  for (i = 0; i < r; i++) { a *= (n - i); b *= (i + 1); }
  return a / b;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// Row 0 is [1]. Each next row starts and ends with 1. Inner slot j is prev[j-1] + prev[j]. No overflow beyond 32-bit on the usual n <= 30 constraint.

void generate(int numRows, int out[][32], int* lens) {
  int r, j;
  out[0][0] = 1; lens[0] = 1;
  for (r = 1; r < numRows; r++) {
    out[r][0] = 1;
    for (j = 1; j < r; j++) out[r][j] = out[r - 1][j - 1] + out[r - 1][j];
    out[r][r] = 1;
    lens[r] = r + 1;
  }
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Each row built independently with the running product formula. Useful when you only need row r (Pascal's Triangle II) and do not want the whole triangle.

void generateRow(int r, int* row) {
  int k; long v = 1;
  row[0] = 1;
  for (k = 1; k <= r; k++) {
    v = v * (r - k + 1) / k;
    row[k] = (int)v;
  }
}
