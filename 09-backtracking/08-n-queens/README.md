# N-Queens

**Topic:** Recursion & Backtracking  
**Level:** advanced  
**Asked at:** Amazon · Google · Microsoft · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/n-queens/)
- [GFG](https://www.geeksforgeeks.org/problems/n-queen-problem-1587115620/1)

## Problem

Place n queens on an n x n board so none share a row, column, or diagonal. Return every board as n strings of '.' and 'Q'.

Tiny example: n = 4 has two solutions. One is queens at (0,1), (1,3), (2,0), (3,2) in 0-based row, col.

The brute tries every permutation of columns (one queen per row and column) and only then checks diagonals. Standard backtrack checks col/diag before placing. Bitmasks make those checks O(1) with shifts.

Open Brute, Optimal, and More optimal for permutations, arrays, and bitmasks.

## Methods of solving

### 1. Brute

- **Time:** O(n * n!)
- **Space:** O(n^2)

Generate every permutation of columns with extra copies. After a full permutation, scan every pair for a shared diagonal. Most permutations fail only at the end.

### 2. Optimal

- **Time:** O(n!)
- **Space:** O(n^2)

Place one queen per row. col[], d1[], d2[] mark attacks. If the square is free, mark, recurse row+1, unmark. Failures die as soon as a row has no square.

### 3. More optimal

- **Time:** O(n!)
- **Space:** O(n^2)

cols, diag, anti as bitmasks. available bits are the free columns. Take the lowest set bit, recurse with shifted diagonals. Same search, O(1) updates.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
