# Search a 2D Matrix II

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/search-a-2d-matrix-ii/)
- [GFG](https://www.geeksforgeeks.org/problems/search-in-a-matrix/1)

## Problem

Each row is sorted left to right. Each column is sorted top to bottom. The next row does NOT have to start after this row. Return whether target exists.

Tiny example: [[1, 4, 7], [2, 5, 8], [3, 6, 9]], target 5 -> true. Target 10 -> false. Notice 2 sits under 1, so you cannot flatten the grid into one sorted list.

Binary search each row is O(r log c). The staircase from the top-right (or bottom-left) is O(r + c): too big, move left; too small, move down.

Open Brute, Optimal, and More optimal for a scan, per-row binary search, and the staircase walk.

## Methods of solving

### 1. Brute

- **Time:** O(rc)
- **Space:** O(1)

Visit every cell. Correct, ignores both sorted axes.

### 2. Optimal

- **Time:** O(r log c)
- **Space:** O(1)

Each row is sorted, so binary search that row. Skip a row whose first cell is already larger than target or whose last cell is smaller. Good when there are few rows.

### 3. More optimal

- **Time:** O(r + c)
- **Space:** O(1)

Start at top-right. The cell is the largest in its row prefix and the smallest in its column suffix. Larger than target: nothing in this column below can be smaller in a useful way — move left. Smaller: move down. Each step drops a row or a column.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
