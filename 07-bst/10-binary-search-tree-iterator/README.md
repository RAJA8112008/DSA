# Binary Search Tree Iterator

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Meta · Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/binary-search-tree-iterator/)
- [GFG](https://www.geeksforgeeks.org/problems/bst-iterator/1)

## Problem

Implement next() and hasNext() for the inorder walk of a BST. next() returns the next smallest key. Both calls should be average O(1) time and use O(h) memory if you can.

Brute dumps the whole inorder array up front. Optimal keeps a stack of the left spine and pushes the right child's left spine after each next(). More optimal threads Morris links so extra memory is O(1) besides the output of next.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n) init, O(1) next
- **Space:** O(n)

Flatten inorder into an array at construction. next/hasNext are index moves. Simple, but you pay linear memory before the first call.

### 2. Optimal

- **Time:** O(h) init, amortized O(1) next
- **Space:** O(h)

Stack holds the path to the next node. Construction pushes the left spine. next() pops, then pushes the left spine of the right child.

### 3. More optimal

- **Time:** amortized O(1) next
- **Space:** O(1)

Morris: thread predecessor.right to the current node, walk without a stack. Unthread before yielding so the tree is restored. Extra memory is a handful of pointers.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
