# Binary Tree Maximum Path Sum

**Topic:** Binary Trees  
**Level:** advanced  
**Asked at:** Amazon · Microsoft · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/binary-tree-maximum-path-sum/)
- [GFG](https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1)

## Problem

A path is any node-to-node walk with no node repeated. Return the maximum sum of node values on such a path. Nodes may be negative, so a single node can win.

[1,2,3] yields 6 (2+1+3). A node can use both children in the answer, but the value returned to the parent can continue only one side (or none).

Brute recomputes downward gain at every node. One DFS returns gain and updates a best through-node sum. Returning {gain, best} avoids a shared mutable box.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(h)

At each node, maxDown on left and right is computed from scratch, then visit children. Nested tree walks.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

gain(node) = val + max(0, gain(left), gain(right)) for continuing up. Through-node sum updates a boxed best. One DFS.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Same linear DFS, but dfs returns {gain, best} so there is no outer mutable. Parent combines through, left.best, and right.best. Cleaner to reason about.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
