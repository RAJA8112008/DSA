// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Each cell branches right and down. Paths share prefixes but nothing is cached. Depth is m+n-2 moves. Fine only for tiny grids.

int pathsGo(int m, int n, int r, int c) {
    if (r == m - 1 && c == n - 1) return 1;
    if (r >= m || c >= n) return 0;
    return pathsGo(m, n, r + 1, c) + pathsGo(m, n, r, c + 1);
}
int uniquePaths(int m, int n) {
    return pathsGo(m, n, 0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// One cell per grid square, filled from two neighbors in O(1). First row and column are the corridor of 1s. This is the table you draw in an interview.

int uniquePaths(int m, int n) {
    int **ways = (int **)malloc(m * sizeof(int *));
    int r, c, ans;
    for (r = 0; r < m; r++) ways[r] = (int *)calloc(n, sizeof(int));
    for (r = 0; r < m; r++) ways[r][0] = 1;
    for (c = 0; c < n; c++) ways[0][c] = 1;
    for (r = 1; r < m; r++) {
        for (c = 1; c < n; c++) {
            ways[r][c] = ways[r - 1][c] + ways[r][c - 1];
        }
    }
    ans = ways[m - 1][n - 1];
    for (r = 0; r < m; r++) free(ways[r]);
    free(ways);
    return ans;
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// A cell only needs the previous row. One row: ways[c] is “from above” before you add ways[c-1] (from the left). Extra memory is one row of width n.

int uniquePaths(int m, int n) {
    int *ways = (int *)malloc(n * sizeof(int));
    int r, c, ans;
    for (c = 0; c < n; c++) ways[c] = 1;
    for (r = 1; r < m; r++) {
        for (c = 1; c < n; c++) {
            ways[c] += ways[c - 1];
        }
    }
    ans = ways[n - 1];
    free(ways);
    return ans;
}
