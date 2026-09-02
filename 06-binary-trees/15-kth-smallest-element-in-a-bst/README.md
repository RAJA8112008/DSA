# Kth Smallest Element in a BST

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Google · Uber · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
- [GFG](https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1)

## Problem

Return the kth smallest value in a BST (1-based). Inorder of a BST is sorted, so the kth visit is the answer.

BST 3 with left 1 (right child 2) and right 4, k = 1 yields 1.

Dump inorder to an array and index k-1. Recursion counts visits and stops early. Iterative inorder with a stack pops k times.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Full inorder into an array, return vals[k-1]. Always walks the whole tree.

### 2. Optimal

- **Time:** O(h+k)
- **Space:** O(h)

Recursive inorder with a counter. When count hits k, record val and stop expanding. Better when k is small.

### 3. More optimal

- **Time:** O(h+k)
- **Space:** O(h)

Iterative inorder. Each pop is the next smallest. After k pops, return that val. Easy to stop early; no extra values array.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
