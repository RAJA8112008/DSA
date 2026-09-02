# Binary Tree Vertical Order Traversal

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Meta · Amazon · Microsoft · Google

## Practice

- [LeetCode](https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1)

## Problem

Group nodes by column (horizontal distance). Root is column 0, left is -1, right is +1. Within a column, go top to bottom; LeetCode also sorts by value when two nodes share a row and column. GFG prints left-to-right in BFS order without that extra sort.

Brute DFS records (col, row, val) then sorts. Optimal BFS into a map of columns. More optimal tracks min/max column and uses an array instead of a tree map.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

DFS push [col, row, val]. Sort by col, then row, then val. Group into lists. Matches LeetCode 987.

### 2. Optimal

- **Time:** O(n log w)
- **Space:** O(n)

BFS so row order is natural. TreeMap / sorted map of columns. GFG order (no value sort). w is the number of columns.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Same BFS. Record min and max hd, then emit columns in a plain loop. No log w map.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
