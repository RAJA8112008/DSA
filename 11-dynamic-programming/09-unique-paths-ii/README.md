# Unique Paths II

**Topic:** Dynamic Programming  
**Level:** intermediate  
**Asked at:** Amazon · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/unique-paths-ii/)
- [GFG](https://www.geeksforgeeks.org/unique-paths-in-a-grid-with-obstacles/)

## Problem

Same grid as Unique Paths, but some cells hold a 1 (a stone). You cannot walk on a stone. Return the number of paths from top-left to bottom-right. If the start is a stone, the answer is 0.

Tiny example: [[0,0,0],[0,1,0],[0,0,0]]. The middle cell is blocked. Two paths remain. Answer 2.

A stone zeros that cell. Other cells still add from above and left. The 1D row overwrites a blocked column with 0 so later cells in that row cannot pick a fake left path.

Open the Brute, Optimal, and More optimal tabs for recursion that rejects stones, a 2D ways grid, and the 1D row.

## Methods of solving

### 1. Brute

- **Time:** O(2^{m+n})
- **Space:** O(m + n)

Same path tree as Unique Paths, with extra dead ends on stones. No cache, so overlapping cells are walked many times.

### 2. Optimal

- **Time:** O(m * n)
- **Space:** O(m * n)

Each cell is filled once. Stones store 0. Start is 1 only if it is free. Neighbors that do not exist contribute 0. Classic 2D DP on a grid.

### 3. More optimal

- **Time:** O(m * n)
- **Space:** O(n)

Reuse one row of width cols. A stone zeros ways[c]. A free cell adds the left cell in this row (already updated) onto the old ways[c] (the cell above). Same time, linear extra memory.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
