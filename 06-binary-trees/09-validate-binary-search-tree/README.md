# Validate Binary Search Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/validate-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/check-for-bst/1)

## Problem

Return true if the tree is a valid BST: every node in the left subtree is strictly less, every node in the right subtree is strictly greater.

[2,1,3] is valid. [5,1,4,null,null,3,6] is not, because 3 sits in the right subtree of 5.

Inorder into an array and check increasing. Recursion with (min, max) bounds. Iterative inorder tracking the previous value.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Inorder dump into an array, then check each pair is strictly increasing. Extra O(n) array.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Each node must lie in (low, high). Left child gets high = node.val. Right child gets low = node.val. Use -Infinity / Infinity at the root. Recursion O(h).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Iterative inorder. prev holds the last visited value. If node.val <= prev, fail. No extra values array.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
