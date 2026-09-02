# Recover Binary Search Tree

**Topic:** BST  
**Level:** advanced  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/recover-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/fix-two-swapped-nodes-of-bst/)

## Problem

Exactly two nodes in a BST had their values swapped. Restore the tree without changing the structure. Do it in O(1) extra space if you can.

Inorder of a BST should be sorted. Two swapped values make either two drops (non-adjacent swap) or one drop (adjacent swap). Find the first and last node that break increasing order, then swap their values.

Brute copies inorder, sorts, writes back. Optimal finds the two nodes while walking. More optimal is Morris inorder so the walk itself uses O(1) extra pointers.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n log n)
- **Space:** O(n)

Store every node in inorder, copy values, sort the copy, write sorted values back. Structure is unchanged; you sort instead of finding the pair.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Inorder with a prev pointer. first is the previous node at the first drop. second is the current node at every drop (so adjacent swaps still work). Swap first.val and second.val.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

Morris inorder with the same first/second logic. Thread and unthread predecessor links so you do not keep a stack.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
