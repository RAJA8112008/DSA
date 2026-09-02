# Minimum Absolute Difference in BST

**Topic:** BST  
**Level:** beginner  
**Asked at:** Amazon · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/minimum-absolute-difference-in-bst/)
- [GFG](https://www.geeksforgeeks.org/find-minimum-absolute-difference-between-any-two-elements-in-bst/)

## Problem

Return the smallest |a - b| over any two distinct nodes. In a BST the closest values are neighbors in inorder, so you never need all pairs.

Brute checks every pair. Optimal inorders and tracks the previous value. More optimal is Morris inorder so extra memory is O(1).

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Dump all values, then compare every pair. Extra array and quadratic checks.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Inorder. Compare each node with the previous inorder value. The min of those adjacent gaps is the global min.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Morris inorder with a previous pointer. Same adjacent-gap logic, no stack.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
