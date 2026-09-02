# Convert Sorted Array to Binary Search Tree

**Topic:** BST  
**Level:** beginner  
**Asked at:** Microsoft · Amazon · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/array-to-bst/1)

## Problem

nums is sorted ascending. Build a height-balanced BST (left and right heights differ by at most 1).

The middle of a range is the root; the left half becomes the left subtree, the right half the right subtree.

Brute inserts keys one by one into an empty BST (a stick). Optimal picks mid with array slices. More optimal passes lo/hi indices so you never copy the array.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Insert 0..n-1 in order into an empty BST. Each insert walks a growing right spine, so you get a linked list of height n.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Slice the array around mid each call. Balanced, but each slice copies O(n) elements across the tree of calls.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(log n)

Pass inclusive indices. Each node is created once. Recursion depth is the height of the balanced tree.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
