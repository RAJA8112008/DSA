# Method 1: Brute
# Time: O(m·n) | Space: O(m·n)
# You copy the whole grid so newly written zeros do not trigger more rows. Memory is the full matrix.
# How it works: scan the copy; if copy[r][c] is 0, zero row r and column c in the original.

def set_zeroes(matrix):
    rows = len(matrix)
    cols = matrix[0].length
    copy = []
    for r in range(rows):
        copy.append(matrix[r].slice())
    for r in range(rows):

        for c in range(cols):

            if copy[r][c] == 0:
                for x in range(cols):
                    matrix[r][x] = 0
                for y in range(rows):
                    matrix[y][c] = 0

    return matrix


# Method 2: Optimal
# Time: O(m·n) | Space: O(m + n)
# Two flag arrays instead of a full copy. Time is still a few passes over the grid.
# How it works: mark which rows and columns contain a zero, then write zeros in a second pass.

def set_zeroes(matrix):
    rows = len(matrix)
    cols = matrix[0].length
    zeroRow = [False] * rows
    zeroCol = [False] * cols
    for r in range(rows):

        for c in range(cols):

            if matrix[r][c] == 0:
                zeroRow[r] = True
                zeroCol[c] = True

    for r in range(rows):

        for c in range(cols):

            if zeroRow[r] or zeroCol[c]: matrix[r][c] = 0

    return matrix


# Method 3: More optimal
# Time: O(m·n) | Space: O(1)
# Flags live in the first row and first column. Only two extra booleans.
# How it works: record whether row 0 and col 0 need to be cleared. For the rest, matrix[r][0] and matrix[0][c] mark zeros. Clear the interior, then the first row/col if needed.

def set_zeroes(matrix):
    rows = len(matrix)
    cols = matrix[0].length
    firstRow = False
    firstCol = False
    for c in range(cols):
        if matrix[0][c] == 0: firstRow = True
    for r in range(rows):
        if matrix[r][0] == 0: firstCol = True
    for r in range(1, rows):

        for c in range(1, cols):

            if matrix[r][c] == 0:
                matrix[r][0] = 0
                matrix[0][c] = 0

    for r in range(1, rows):

        for c in range(1, cols):

            if matrix[r][0] == 0 or matrix[0][c] == 0: matrix[r][c] = 0

    if firstRow: for c in range(cols):
        matrix[0][c] = 0
    if firstCol: for r in range(rows):
        matrix[r][0] = 0
    return matrix
