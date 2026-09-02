# Set Matrix Zeroes

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/set-matrix-zeroes/)
- [GFG](https://www.geeksforgeeks.org/problems/boolean-matrix-problem-1587115620/1)

## Problem

If a cell is 0, set its whole row and whole column to 0. Do this using the original zeros, not the zeros you just wrote.

Example: [[1, 1, 1], [1, 0, 1], [1, 1, 1]] becomes [[1, 0, 1], [0, 0, 0], [1, 0, 1]].

A full copy of the matrix is the safe slow extra-memory version. Row and column boolean arrays are the usual O(m+n) extra. The first row and first column can store those flags, with two booleans for whether those lines started with a zero.

Open the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(m·n)
- **Space:** O(m·n)

You copy the whole grid so newly written zeros do not trigger more rows. Memory is the full matrix.
How it works: scan the copy; if copy[r][c] is 0, zero row r and column c in the original.

### 2. Optimal

- **Time:** O(m·n)
- **Space:** O(m + n)

Two flag arrays instead of a full copy. Time is still a few passes over the grid.
How it works: mark which rows and columns contain a zero, then write zeros in a second pass.

### 3. More optimal

- **Time:** O(m·n)
- **Space:** O(1)

Flags live in the first row and first column. Only two extra booleans.
How it works: record whether row 0 and col 0 need to be cleared. For the rest, matrix[r][0] and matrix[0][c] mark zeros. Clear the interior, then the first row/col if needed.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
