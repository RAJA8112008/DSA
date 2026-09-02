# Method 1: Brute
# Time: O(m·n) | Space: O(m·n)
# You still visit each cell once, but a boolean grid of the same size is extra memory.
# How it works: start at (0,0) facing right. If the next cell is out of bounds or visited, turn right. Push each value.

def spiral_order(matrix):
    if not len(matrix): return []
    rows = len(matrix)
    cols = matrix[0].length
    seen = []
    for r in range(rows):
        seen.append([False] * cols)
    dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    out = []
    r = 0
    c = 0
    d = 0
    for k in range(rows * cols):

        out.append(matrix[r][c])
        seen[r][c] = True
        nr = r + dirs[d][0]
        nc = c + dirs[d][1]
        if nr < 0 or nr >= rows or nc < 0 or nc >= cols or seen[nr][nc]:
            d = (d + 1) % 4
        r += dirs[d][0]
        c += dirs[d][1]

    return out


# Method 2: Optimal
# Time: O(m·n) | Space: O(1)
# Output list is required. Extra memory is a few bound integers, treated as O(1).
# How it works: peel a layer: walk top row left->right, right col top->bottom, bottom row right->left, left col bottom->top, then shrink the four bounds.

def spiral_order(matrix):
    if not len(matrix): return []
    out = []
    top = 0
    bottom = len(matrix) - 1
    left = 0
    right = matrix[0].length - 1
    while top <= bottom and left <= right:
        for c in range(left, = right):
            out.append(matrix[top][c])
        top += 1
        for r in range(top, = bottom):
            out.append(matrix[r][right])
        right -= 1
        if top <= bottom:
            for c in range(right, (left) - 1, -1):
                out.append(matrix[bottom][c])
            bottom -= 1
        if left <= right:
            for r in range(bottom, (top) - 1, -1):
                out.append(matrix[r][left])
            left += 1
    return out


# Method 3: More optimal
# Time: O(m·n) | Space: O(1)
# Same bounds idea in one counted loop: visit exactly rows*cols cells, turn when the next step would leave the remaining rectangle.
# How it works: after a turn, shrink the bound you just finished (top, right, bottom, or left) so the next lap is the inner layer.

def spiral_order(matrix):
    if not len(matrix): return []
    rows = len(matrix)
    cols = matrix[0].length
    out = []
    top = 0
    bottom = rows - 1
    left = 0
    right = cols - 1
    dirs = [[0, 1], [1, 0], [0, -1], [-1, 0]]
    d = 0
    r = 0
    c = 0
    for k in range(rows * cols):

        out.append(matrix[r][c])
        nr = r + dirs[d][0]
        nc = c + dirs[d][1]
        if nr < top or nr > bottom or nc < left or nc > right:
            if d == 0: top += 1
            elif d == 1: right -= 1
            elif d == 2: bottom -= 1
            else: left += 1
            d = (d + 1) % 4
            r += dirs[d][0]
            c += dirs[d][1]
        else:
            r = nr
            c = nc

    return out
