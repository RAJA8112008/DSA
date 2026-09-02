# Maximum Depth of Binary Tree

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Google · Apple · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/height-of-binary-tree/1)

## Problem

Depth is the number of nodes on the longest root-to-leaf path. Return that number. Empty tree is 0.

A root with two leaves has depth 2. A stick of three nodes has depth 3.

BFS counts how many levels you drain. Recursion is 1 + max(left, right). Iterative DFS stores depth next to each node on a stack.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Collect every root-to-leaf path into arrays, return the longest length. Extra memory for all paths.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Recursive height: null is 0, else 1 + max of children. One visit per node. Stack O(h).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Iterative stack of {node, depth}. Track the max depth seen. Same complexity, no engine recursion. BFS would use O(width) instead of O(h).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
