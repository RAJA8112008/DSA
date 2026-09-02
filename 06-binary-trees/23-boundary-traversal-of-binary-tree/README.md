# Boundary Traversal of Binary Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Uber

## Practice

- [GFG](https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1)
- [GFG](https://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/)

## Problem

Print the boundary anti-clockwise: root, left boundary (top to bottom, no leaves), all leaves left to right, right boundary (bottom to top, no leaves). Do not print the root twice on a one-node tree.

Left boundary is the walk that prefers left, then right if left is missing. Right boundary prefers right. Leaves are a standard DFS.

Brute marks every node with flags. Optimal is three dedicated walks. More optimal is one DFS with (isLeftBound, isRightBound, isLeaf) flags.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Collect all nodes with (isLeft, isRight, isLeaf). Then emit left bound, leaves, reverse right bound, skipping duplicates via a seen set.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Three passes: left edge (stop before a leaf), all leaves, right edge into a stack then pop. Clear and classic interview split.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

One DFS. Pass whether this node is on the left bound, right bound, or a leaf. Append left-bound before children, leaves in the middle, right-bound after children (so they reverse themselves).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
