# Lowest Common Ancestor of a Binary Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Meta · Microsoft · Google

## Practice

- [LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1)

## Problem

Same LCA idea, but the tree is not a BST. You cannot compare values to choose a side. p and q exist in the tree. A node may be the ancestor of itself.

On a general tree, LCA of two leaves is the fork where their paths split.

Store parent pointers or full paths, then walk ancestors. Recursion: if left and right both find a target, root is LCA. Iterative: parent map plus a set of p's ancestors.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

DFS records the path to p and the path to q as arrays. Last common entry is the LCA. Extra path storage.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

If node is null, p, or q, return node. Recurse left and right. If both sides return non-null, node is LCA. Else return the non-null side. One DFS.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Iterative stack builds a parent map. Collect ancestors of p in a Set. Walk q's parent chain until a node is in the set. No recursion; extra map of n parents.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
