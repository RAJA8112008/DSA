# Search a 2D Matrix

**Topic:** Binary Search  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Facebook · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/search-a-2d-matrix/)
- [GFG](https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1)

## Problem

Each row is sorted left to right. The first value of the next row is larger than the last value of this row. Return whether target exists.

Tiny example: [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], target 3 -> true. Target 13 -> false.

The grid is one sorted list of length rows*cols. Flatten index mid maps to [mid / cols][mid % cols]. You can also binary search the row, then the column.

Open Brute, Optimal, and More optimal for a full scan, flatten binary search, and row-then-column binary search.

## Methods of solving

### 1. Brute

- **Time:** O(rc)
- **Space:** O(1)

Compare every cell. Correct on any matrix. Ignores both sorted properties.

### 2. Optimal

- **Time:** O(log(rc))
- **Space:** O(1)

Treat the grid as one sorted array of length rows*cols. Ordinary binary search. This uses the stronger 'next row starts after this row' rule.

### 3. More optimal

- **Time:** O(log r + log c)
- **Space:** O(1)

Overflow-safe mid. First find the last row whose first cell is <= target (or the unique row that can hold it). Then binary search that row. Same log(rc) probes, often clearer in an interview sketch.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
