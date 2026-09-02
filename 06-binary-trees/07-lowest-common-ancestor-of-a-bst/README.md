# Lowest Common Ancestor of a BST

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1)

## Problem

p and q are nodes in a BST. Return their lowest common ancestor: the deepest node that has both in its subtree. A node can be an ancestor of itself.

In BST 6 with left 2 and right 8, LCA of 2 and 8 is 6. LCA of 2 and 4 is 2.

Record paths from root to each target, last shared node. Recursion: if both values are less, go left; both greater, go right; else this node. Iteration is the same walk without a stack.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(h)
- **Space:** O(h)

Walk BST paths into two arrays of nodes, then scan from the start until they differ. Extra path arrays.

### 2. Optimal

- **Time:** O(h)
- **Space:** O(h)

Recursive BST walk. Split point is the LCA. Stack O(h).

### 3. More optimal

- **Time:** O(h)
- **Space:** O(1)

Same split logic in a loop. No recursion. Constant extra space.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
