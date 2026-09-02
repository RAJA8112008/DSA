# Insert into a Binary Search Tree

**Topic:** BST  
**Level:** beginner  
**Asked at:** Amazon · Meta · Apple · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/insert-into-a-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1)

## Problem

Insert val as a new leaf so the tree stays a BST. LeetCode guarantees val is not already present.

Walk like search until you hit null, then create the node. Return the (unchanged) root.

Brute dumps keys, adds val, and rebuilds. Optimal recurses. More optimal inserts with a parent pointer in a loop.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Collect every key, append val, sort, and rebuild a balanced tree from the middle. Extra arrays; you never use the existing shape.

### 2. Optimal

- **Time:** O(h)
- **Space:** O(h)

Recurse left or right and assign the returned child. When the child is null, allocate the new leaf. Root is returned unchanged unless the tree was empty.

### 3. More optimal

- **Time:** O(h)
- **Space:** O(1)

Iterative: if the tree is empty, return a new root. Else walk until the next child is null and attach there. No recursion.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
