# Same Tree

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Apple · Adobe · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/same-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1)

## Problem

Return true if two trees have the same shape and the same values at every corresponding node.

Two copies of 1 with left 2 and right 3 are the same. If one has a missing child the other has, they differ.

Serialize both and compare strings. Recursion compares val and both subtrees. Iterative two stacks (or a queue of pairs) does the same walk.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Encode each tree as a preorder array with N for null, then compare the arrays. Extra strings/arrays for both trees.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

If both null, true. If one null or vals differ, false. Else both lefts and both rights. Stack O(h).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Iterative: stack of pairs. Pop two nodes, check null/val, push children pairs. Same complexity, no recursion.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
