# Flatten Binary Tree to Linked List

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Meta · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)
- [GFG](https://www.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1)

## Problem

Flatten the tree into a right-skewed list in preorder. Every left pointer becomes null. Use the same TreeNode objects.

1 with left 2 (3,4) and right 5 (6) becomes 1-2-3-4-5-6 all on the right.

Preorder into an array then relink. Recursion flattens children and stitches. Morris-style: predecessor of the right subtree is the rightmost node of the left, then rotate.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Preorder collect nodes into an array. Then set each left to null and next.right to the following node. Extra array.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Recurse right, then left, keep a tail pointer of the already flattened suffix. Hang this node in front. Stack O(h).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

While cur exists: if it has a left, find rightmost of left, attach cur.right there, move left to right, clear left. Then cur = cur.right. No extra stack.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
