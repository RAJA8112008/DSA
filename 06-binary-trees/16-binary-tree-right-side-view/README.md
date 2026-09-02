# Binary Tree Right Side View

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/binary-tree-right-side-view/)
- [GFG](https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1)

## Problem

Return the values you see standing on the right side, top to bottom: the last node of each level.

[1,2,3,null,5,null,4] yields [1,3,4]. A left child that sticks out below can appear if the right is missing.

Level-order, take the last of each row. DFS right-first: first time you reach a depth, record it. BFS that writes queue[n-1] is the compact iterative form.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Full level-order into rows, then map each row to its last value. Extra storage for every node value.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

DFS visit right child first. If depth === ans.length, this is the first node seen at that depth from the right. Recursion O(h).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(w)

BFS. For each level of size n, the last shifted node is the right-side value. Only the answer plus the queue, no full row arrays.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
