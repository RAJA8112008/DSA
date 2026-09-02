# Method 1: Brute
# Time: O(2^{m+n}) | Space: O(m + n)
# Each cell branches right and down. Paths share prefixes but nothing is cached. Depth is m+n-2 moves. Fine only for tiny grids.

def uniquePaths(m, n):
    def go(r, c):
        if r == m - 1 and c == n - 1:
            return 1
        if r >= m or c >= n:
            return 0
        return go(r + 1, c) + go(r, c + 1)
    return go(0, 0)


# Method 2: Optimal
# Time: O(m * n) | Space: O(m * n)
# One cell per grid square, filled from two neighbors in O(1). First row and column are the corridor of 1s. This is the table you draw in an interview.

def uniquePaths(m, n):
    ways = [[0] * n for _ in range(m)]
    for r in range(m):
        ways[r][0] = 1
    for c in range(n):
        ways[0][c] = 1
    for r in range(1, m):
        for c in range(1, n):
            ways[r][c] = ways[r - 1][c] + ways[r][c - 1]
    return ways[m - 1][n - 1]


# Method 3: More optimal
# Time: O(m * n) | Space: O(n)
# A cell only needs the previous row. One row: ways[c] is “from above” before you add ways[c-1] (from the left). Extra memory is one row of width n.

def uniquePaths(m, n):
    ways = [1] * n
    for r in range(1, m):
        for c in range(1, n):
            ways[c] += ways[c - 1]
    return ways[n - 1]
