# Valid Sudoku

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Apple · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/valid-sudoku/)
- [GFG](https://www.geeksforgeeks.org/problems/is-sudoku-valid4825/1)

## Problem

A 9 by 9 board of digits and '.'. Return true if every filled row, column, and 3 by 3 box has no duplicate digit. Empty cells are ignored. The board does not have to be a completed puzzle.

Example: a standard valid (partial) grid returns true. Two 8s in the same box returns false.

Brute, for each filled cell, rescans its row, column, and box. Optimal uses 27 sets. More optimal packs the same idea into bitmasks.

## Methods of solving

### 1. Brute

- **Time:** O(1) for 9x9
- **Space:** O(1)

For every filled cell, walk its row, column, and 3x3 box looking for the same digit elsewhere. On a 9x9 this is constant, but the nested scans are noisy.

### 2. Optimal

- **Time:** O(1)
- **Space:** O(1)

Nine sets for rows, nine for columns, nine for boxes. Box id is (r/3)*3 + c/3. Fail on the first repeat.

### 3. More optimal

- **Time:** O(1)
- **Space:** O(1)

Nine ints for rows, columns, boxes. Bit (1 << digit) marks a used number. A second hit on the same bit is a duplicate. Same logic, no hash sets.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
