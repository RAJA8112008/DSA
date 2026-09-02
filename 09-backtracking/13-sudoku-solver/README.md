# Sudoku Solver

**Topic:** Recursion & Backtracking  
**Level:** advanced  
**Asked at:** Amazon · Google · Uber · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/sudoku-solver/)
- [GFG](https://www.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1)

## Problem

Fill a 9x9 Sudoku board. Empty cells are '.'. A digit 1-9 may appear once in each row, column, and 3x3 box. Mutate the board in place. There is exactly one solution.

Tiny picture: one empty cell in a valid board has only one legal digit. A harder board needs search.

The brute copies the whole board on every guess. Standard backtrack writes a digit, recurses, erases it, and scans the row/col/box each time. Bitmasks plus picking the emptiest cell (MRV) fail illegal digits sooner.

Open Brute, Optimal, and More optimal for board copies, in-place scan, and bitmasks with MRV.

## Methods of solving

### 1. Brute

- **Time:** O(9^{e})
- **Space:** O(e)

e empty cells. Each guess clones the board and scans from scratch. Extra copies on every node. Correct but memory-heavy.

### 2. Optimal

- **Time:** O(9^{e})
- **Space:** O(e)

Write a digit in place, recurse, write '.'. isValid scans the row, column, and box. No extra boards. First empty cell, left to right.

### 3. More optimal

- **Time:** O(9^{e})
- **Space:** O(e)

row[], col[], box[] bitmasks. Pick the empty cell with the fewest remaining digits (MRV) so dead ends die sooner. Toggle bits instead of scanning 9 cells.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
