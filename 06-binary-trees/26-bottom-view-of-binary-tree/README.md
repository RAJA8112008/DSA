# Bottom View of Binary Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Apple · Uber

## Practice

- [GFG](https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1)
- [GFG](https://www.geeksforgeeks.org/bottom-view-binary-tree/)

## Problem

Standing below the tree, you see the last (deepest) node at each horizontal distance. If two nodes share hd and depth, GFG keeps the one visited later (usually the right one in BFS).

BFS overwrite: every time you see hd, replace the value. DFS must keep the larger depth, and on a tie prefer the later visit.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

Collect (hd, depth, index, val), sort, keep the last per hd.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

BFS overwrite per hd. Last write is the deepest (or the right one on a tie). Emit min..max.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

DFS: keep val for hd when depth >= stored depth (overwrite on tie so right-later wins if you visit right after left).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
