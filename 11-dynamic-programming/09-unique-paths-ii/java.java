// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Same path tree as Unique Paths, with extra dead ends on stones. No cache, so overlapping cells are walked many times.

class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        return go(grid, 0, 0);
    }
    private int go(int[][] grid, int r, int c) {
        int rows = grid.length, cols = grid[0].length;
        if (r >= rows || c >= cols || grid[r][c] == 1) return 0;
        if (r == rows - 1 && c == cols - 1) return 1;
        return go(grid, r + 1, c) + go(grid, r, c + 1);
    }
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// Each cell is filled once. Stones store 0. Start is 1 only if it is free. Neighbors that do not exist contribute 0. Classic 2D DP on a grid.

class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        if (grid[0][0] == 1) return 0;
        int[][] ways = new int[rows][cols];
        ways[0][0] = 1;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    ways[r][c] = 0;
                    continue;
                }
                if (r == 0 && c == 0) continue;
                int up = r > 0 ? ways[r - 1][c] : 0;
                int left = c > 0 ? ways[r][c - 1] : 0;
                ways[r][c] = up + left;
            }
        }
        return ways[rows - 1][cols - 1];
    }
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// Reuse one row of width cols. A stone zeros ways[c]. A free cell adds the left cell in this row (already updated) onto the old ways[c] (the cell above). Same time, linear extra memory.

class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int rows = grid.length, cols = grid[0].length;
        int[] ways = new int[cols];
        ways[0] = grid[0][0] == 1 ? 0 : 1;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) ways[c] = 0;
                else if (c > 0) ways[c] += ways[c - 1];
            }
        }
        return ways[cols - 1];
    }
}
