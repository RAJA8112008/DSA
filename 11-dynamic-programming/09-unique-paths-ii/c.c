// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Same path tree as Unique Paths, with extra dead ends on stones. No cache, so overlapping cells are walked many times.

int obsGo(int **grid, int rows, int cols, int r, int c) {
    if (r >= rows || c >= cols || grid[r][c] == 1) return 0;
    if (r == rows - 1 && c == cols - 1) return 1;
    return obsGo(grid, rows, cols, r + 1, c) + obsGo(grid, rows, cols, r, c + 1);
}
int uniquePathsWithObstacles(int **grid, int rows, int cols) {
    return obsGo(grid, rows, cols, 0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// Each cell is filled once. Stones store 0. Start is 1 only if it is free. Neighbors that do not exist contribute 0. Classic 2D DP on a grid.

int uniquePathsWithObstacles(int **grid, int rows, int cols) {
    int **ways, r, c, ans;
    if (grid[0][0] == 1) return 0;
    ways = (int **)malloc(rows * sizeof(int *));
    for (r = 0; r < rows; r++) ways[r] = (int *)calloc(cols, sizeof(int));
    ways[0][0] = 1;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            if (grid[r][c] == 1) {
                ways[r][c] = 0;
                continue;
            }
            if (r == 0 && c == 0) continue;
            ways[r][c] = (r > 0 ? ways[r - 1][c] : 0) + (c > 0 ? ways[r][c - 1] : 0);
        }
    }
    ans = ways[rows - 1][cols - 1];
    for (r = 0; r < rows; r++) free(ways[r]);
    free(ways);
    return ans;
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// Reuse one row of width cols. A stone zeros ways[c]. A free cell adds the left cell in this row (already updated) onto the old ways[c] (the cell above). Same time, linear extra memory.

int uniquePathsWithObstacles(int **grid, int rows, int cols) {
    int *ways = (int *)calloc(cols, sizeof(int));
    int r, c, ans;
    ways[0] = grid[0][0] == 1 ? 0 : 1;
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            if (grid[r][c] == 1) ways[c] = 0;
            else if (c > 0) ways[c] += ways[c - 1];
        }
    }
    ans = ways[cols - 1];
    free(ways);
    return ans;
}
