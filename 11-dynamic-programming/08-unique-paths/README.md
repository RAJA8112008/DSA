# Unique Paths

**Topic:** Dynamic Programming  
**Level:** beginner  
**Asked at:** Google · Amazon · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/unique-paths/)
- [GFG](https://www.geeksforgeeks.org/problems/number-of-unique-paths5339/1)

## Problem

A robot starts at the top-left of an m by n grid. It may move only right or down. Return how many paths reach the bottom-right.

Tiny example: m = 3, n = 2. Paths: down-down-right, down-right-down, right-down-down. Answer 3.

A cell is reached from above or from the left, so ways[r][c] = ways[r-1][c] + ways[r][c-1]. The first row and first column are 1.

Open the Brute, Optimal, and More optimal tabs for recursion on (r, c), the 2D grid, and one rolling row.

## Methods of solving

### 1. Brute

- **Time:** O(2^{m+n})
- **Space:** O(m + n)

Each cell branches right and down. Paths share prefixes but nothing is cached. Depth is m+n-2 moves. Fine only for tiny grids.

### 2. Optimal

- **Time:** O(m * n)
- **Space:** O(m * n)

One cell per grid square, filled from two neighbors in O(1). First row and column are the corridor of 1s. This is the table you draw in an interview.

### 3. More optimal

- **Time:** O(m * n)
- **Space:** O(n)

A cell only needs the previous row. One row: ways[c] is “from above” before you add ways[c-1] (from the left). Extra memory is one row of width n.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
