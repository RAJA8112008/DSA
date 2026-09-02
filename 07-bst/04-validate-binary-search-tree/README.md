# Validate Binary Search Tree

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Amazon · Meta · Microsoft · Google

## Practice

- [LeetCode](https://leetcode.com/problems/validate-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/check-for-bst/1)

## Problem

Return true if the tree is a BST: every node is strictly greater than the entire left subtree and strictly smaller than the entire right subtree.

Checking only the two children is wrong. Carry a (min, max) window, or dump inorder and require a strictly increasing sequence.

Brute is inorder into an array. Optimal is recursive ranges with long bounds (node.val can be INT_MIN). More optimal is iterative inorder with a previous pointer.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Inorder dump all values, then check each pair is strictly increasing. Extra array holds the whole walk.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Each node must lie in (lo, hi). Left child inherits hi = node.val; right inherits lo = node.val. Use a type wider than int so INT_MIN / INT_MAX are legal node values.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Iterative inorder. Track the previous value. If the current node is not greater, the tree is invalid. No extra value array.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
