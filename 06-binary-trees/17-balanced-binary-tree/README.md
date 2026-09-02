# Balanced Binary Tree

**Topic:** Binary Trees  
**Level:** beginner  
**Asked at:** Amazon · Microsoft · Adobe · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/balanced-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/check-for-balanced-tree-1587115620/1)

## Problem

A tree is balanced if at every node |height(left) - height(right)| <= 1, and both subtrees are balanced. Return true or false.

A complete small tree is balanced. A stick of four nodes is not.

Calling height separately at every node is O(n²). A DFS that returns height or -1 on failure is O(n). Iterative postorder with a height map is the stack version.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(h)

At each node recompute both heights and recurse isBalanced on children. Height work repeats on the same nodes.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Postorder returns height. If a child is already unbalanced or |lh-rh|>1, return -1 and bubble up. One visit per node.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Iterative postorder with a height map. After both children, check |lh-rh| and store height. No recursion.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
