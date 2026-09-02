# Convert Sorted List to Binary Search Tree

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Meta

## Practice

- [LeetCode](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/sorted-linked-list-to-balanced-bst/)

## Problem

The input is a sorted singly linked list, not an array. Build the same height-balanced BST.

You can copy the list into an array and reuse the array solution. Or cut the list at the middle with slow/fast each time. The linear trick simulates inorder: the list pointer walks left-root-right while you create nodes in that order.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Walk the list into an array, then build from mid indices. Extra O(n) memory for the copy.

### 2. Optimal

- **Time:** O(n log n)
- **Space:** O(log n)

Slow/fast finds the mid. Cut prev.next so the left half is a shorter list. Recurse on left half, mid node, and right half. No array, but each level rescans the list.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(log n)

Count n. Inorder-build: recurse left of size n/2, consume the current list node as the root, then recurse right. The list pointer only moves forward. Each node is visited once.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
