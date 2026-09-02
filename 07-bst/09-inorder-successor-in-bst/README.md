# Inorder Successor in BST

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Microsoft · Amazon · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/inorder-successor-in-bst/)
- [GFG](https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1)

## Problem

Given a BST and a node p, return the next node in inorder (the smallest key greater than p), or null if p is the maximum.

If p has a right child, the successor is the leftmost node in that right subtree. Otherwise walk from the root and remember the last node that was greater than p.

Brute dumps inorder. Optimal uses the BST walk from the root. More optimal branches on whether p.right exists so you often never start at the root.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Inorder list of nodes, find p, return the next entry. Extra linear memory.

### 2. Optimal

- **Time:** O(h)
- **Space:** O(1)

Walk from the root. Whenever the current node is greater than p, it is a candidate successor — go left to hunt a closer one. Otherwise go right.

### 3. More optimal

- **Time:** O(h)
- **Space:** O(1)

If p has a right child, successor is leftmost there — O(h) on that spine only. Else fall back to the root walk. Same worst case, often shorter.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
