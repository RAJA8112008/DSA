# Method 1: Brute
# Time: O(2^{m+n}) | Space: O(m + n)
# Same path tree as Unique Paths, with extra dead ends on stones. No cache, so overlapping cells are walked many times.

def uniquePathsWithObstacles(grid):
    rows, cols = len(grid), len(grid[0])
    def go(r, c):
        if r >= rows or c >= cols or grid[r][c] == 1:
            return 0
        if r == rows - 1 and c == cols - 1:
            return 1
        return go(r + 1, c) + go(r, c + 1)
    return go(0, 0)


# Method 2: Optimal
# Time: O(m * n) | Space: O(m * n)
# Each cell is filled once. Stones store 0. Start is 1 only if it is free. Neighbors that do not exist contribute 0. Classic 2D DP on a grid.

def uniquePathsWithObstacles(grid):
    rows, cols = len(grid), len(grid[0])
    if grid[0][0] == 1:
        return 0
    ways = [[0] * cols for _ in range(rows)]
    ways[0][0] = 1
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                ways[r][c] = 0
                continue
            if r == 0 and c == 0:
                continue
            up = ways[r - 1][c] if r > 0 else 0
            left = ways[r][c - 1] if c > 0 else 0
            ways[r][c] = up + left
    return ways[rows - 1][cols - 1]


# Method 3: More optimal
# Time: O(m * n) | Space: O(n)
# Reuse one row of width cols. A stone zeros ways[c]. A free cell adds the left cell in this row (already updated) onto the old ways[c] (the cell above). Same time, linear extra memory.

def uniquePathsWithObstacles(grid):
    rows, cols = len(grid), len(grid[0])
    ways = [0] * cols
    ways[0] = 0 if grid[0][0] == 1 else 1
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                ways[c] = 0
            elif c > 0:
                ways[c] += ways[c - 1]
    return ways[cols - 1]
