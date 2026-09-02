// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Each cell branches right and down. Paths share prefixes but nothing is cached. Depth is m+n-2 moves. Fine only for tiny grids.

class Solution {
    public int uniquePaths(int m, int n) {
        return go(m, n, 0, 0);
    }
    private int go(int m, int n, int r, int c) {
        if (r == m - 1 && c == n - 1) return 1;
        if (r >= m || c >= n) return 0;
        return go(m, n, r + 1, c) + go(m, n, r, c + 1);
    }
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// One cell per grid square, filled from two neighbors in O(1). First row and column are the corridor of 1s. This is the table you draw in an interview.

class Solution {
    public int uniquePaths(int m, int n) {
        int[][] ways = new int[m][n];
        for (int r = 0; r < m; r++) ways[r][0] = 1;
        for (int c = 0; c < n; c++) ways[0][c] = 1;
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                ways[r][c] = ways[r - 1][c] + ways[r][c - 1];
            }
        }
        return ways[m - 1][n - 1];
    }
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// A cell only needs the previous row. One row: ways[c] is “from above” before you add ways[c-1] (from the left). Extra memory is one row of width n.

class Solution {
    public int uniquePaths(int m, int n) {
        int[] ways = new int[n];
        java.util.Arrays.fill(ways, 1);
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                ways[c] += ways[c - 1];
            }
        }
        return ways[n - 1];
    }
}
