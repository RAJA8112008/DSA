# Invert Binary Tree

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Google · Apple · Uber

## Practice

- [LeetCode](https://leetcode.com/problems/invert-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/mirror-tree/1)

## Problem

Swap left and right children at every node. Return the root of the mirrored tree.

A tree with 2 left of 4 and 7 right of 4 becomes 7 left and 2 right, and the same swap happens deeper.

Collect all nodes then swap each. Recursion swaps then inverts children. BFS/DFS iterative swap is the stack/queue twin.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

BFS into an array of every node, then swap left/right on each. Extra list of n pointers.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Recurse: invert children, then swap this node's left and right (order of swap vs recurse both work). Stack O(h).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Iterative stack. Pop a node, swap children, push non-null children. Same work, no recursion. Queue instead of stack is also fine.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
