# Path Sum II

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Google

## Practice

- [LeetCode](https://leetcode.com/problems/path-sum-ii/)
- [GFG](https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1)

## Problem

Return every root-to-leaf path whose values sum to targetSum. A leaf has no children.

DFS with a path list: push the node, recurse, pop (backtrack). When you hit a leaf and remain is 0, copy the path into the answer.

Brute generates every root-to-leaf path then filters. Optimal backtracks with remaining sum. More optimal is an explicit stack of (node, path copy, remain) — same idea, iterative.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n²)

Collect every root-to-leaf path, then keep those whose sum equals target. Path copies dominate memory.

### 2. Optimal

- **Time:** O(n²)
- **Space:** O(h)

Backtracking. remain starts at targetSum. At a leaf, if remain == node.val, snapshot the path. Copying a path is O(h); total output can be O(n²).

### 3. More optimal

- **Time:** O(n²)
- **Space:** O(n²)

Iterative stack of {node, remain, path}. Same snapshots at leaves. Avoids call-stack overflow on a stick, still copies paths.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
