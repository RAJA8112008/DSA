# Left View of Binary Tree

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Apple

## Practice

- [GFG](https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1)
- [GFG](https://www.geeksforgeeks.org/print-left-view-binary-tree/)

## Problem

The left view is the first node you see at each depth when you stand on the left. Root is always included.

BFS: the first node of every level. DFS: the first time you visit a new depth (preorder, left before right).

Brute stores whole levels and takes index 0. Optimal BFS takes the first of the queue size. More optimal DFS records when depth equals the answer length.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Full level-order lists, then pick the first value of each list.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(w)

BFS. When i == 0 in the level loop, that node is the left view. w is the widest level.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

DFS left-first. If depth == out.length this is the first node at that depth. Recursion stack only.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
