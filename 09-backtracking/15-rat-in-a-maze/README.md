# Rat in a Maze

**Topic:** Recursion & Backtracking  
**Level:** beginner  
**Asked at:** Amazon · Adobe · Microsoft · Flipkart

## Practice

- [GFG](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)

## Problem

An n x n grid. 1 is open, 0 is a wall. A rat starts at (0,0) and must reach (n-1, n-1). Moves are D, L, R, U (down, left, right, up). Return every path string. You may not step on a wall or reuse a cell on the current path.

Tiny example: [[1,0],[1,1]]. One path is DR (down, then right). DL is blocked by the 0.

The brute copies the visited grid and the path string on every step. Standard search marks, appends a letter, unmarks. Prune a cell with no open neighbor, and skip the start if it is 0.

Open Brute, Optimal, and More optimal for extra copies, mark/unmark, and dead-end prune.

## Methods of solving

### 1. Brute

- **Time:** O(4^{n^2})
- **Space:** O(n^2)

Each step clones visited and concatenates a new path string. Exponential walks, extra copies at every node. Fine on n = 2, painful on n = 5.

### 2. Optimal

- **Time:** O(4^{n^2})
- **Space:** O(n^2)

Mark grid[r][c] = 0 (or a visited flag), append D/L/R/U, recurse, restore 1. One path buffer. Copy the string only when you hit the end.

### 3. More optimal

- **Time:** O(4^{n^2})
- **Space:** O(n^2)

Same mark/unmark, plus skip a blocked start immediately. Try directions in DLRU order so the output is already sorted, no extra sort. Dead walls never enter the stack.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
