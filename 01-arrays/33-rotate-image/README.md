# Rotate Image

**Topic:** Arrays  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/rotate-image/)
- [GFG](https://www.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1)

## Problem

Rotate an n by n matrix 90 degrees clockwise, in place.

Example: [[1,2,3],[4,5,6],[7,8,9]] becomes [[7,4,1],[8,5,2],[9,6,3]].

Brute writes into a new matrix. Optimal transposes then reverses each row. More optimal rotates 4-cycles on each layer so you never allocate n² extra cells.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n²)

new[c][n-1-r] = old[r][c]. Copy back. Clear picture, extra matrix.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(1)

Transpose (swap across the diagonal) then reverse each row. Two easy passes, in place.

### 3. More optimal

- **Time:** O(n²)
- **Space:** O(1)

Layer by layer. For each offset, rotate the four cells of the cycle in one temp. Same work, no transpose helper. Nice to draw on a whiteboard.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
