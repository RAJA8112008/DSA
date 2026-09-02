# Symmetric Tree

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/symmetric-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/symmetric-tree/1)

## Problem

Return true if the tree is a mirror of itself around the center.

[1,2,2,3,4,4,3] is symmetric. [1,2,2,null,3,null,3] is not, because the inner 3s do not face each other.

Dump left and right halves into arrays with a mirrored walk. Recursion checks whether two subtrees are mirrors. A queue of pairs (left, right) does the same iteratively.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Encode the left subtree left-to-right with nulls, encode the right subtree right-to-left with nulls, compare. Extra arrays.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

mirror(a,b): both null ok; one null fail; vals equal and mirror(a.left,b.right) and mirror(a.right,b.left). Recurse from root.left and root.right.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Queue of node pairs. Dequeue a and b, check, enqueue a.left with b.right and a.right with b.left. Iterative mirror test.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
