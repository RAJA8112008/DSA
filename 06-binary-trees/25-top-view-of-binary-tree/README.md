# Top View of Binary Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Apple

## Practice

- [GFG](https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1)
- [GFG](https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/)

## Problem

Standing above the tree, you see the first node at each horizontal distance. Root is hd 0. Left child hd-1, right hd+1. If two nodes share an hd, the shallower one wins.

BFS from the root visits shallow nodes first, so the first time you see an hd is the top view. DFS must also track depth and keep the smaller depth.

Brute stores (hd, depth, val) and picks min depth. Optimal BFS first-write. More optimal DFS with a depth map.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

Collect every (hd, depth, val), sort, keep the first (smallest depth) per hd.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

BFS. The first time an hd appears, record it. Then emit from min hd to max hd.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

DFS with depth. Keep a node for hd only if this depth is smaller. Then scan min..max hd. No queue.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
