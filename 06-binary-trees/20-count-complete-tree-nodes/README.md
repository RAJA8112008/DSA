# Count Complete Tree Nodes

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/count-complete-tree-nodes/)
- [GFG](https://www.geeksforgeeks.org/count-complete-tree-nodes/)

## Problem

Count nodes in a complete binary tree: every level full except possibly the last, which is filled left to right. Naive O(n) is accepted; the trick is O(log² n).

A perfect tree of height h has 2^h - 1 nodes. If left height equals right height, the subtree is perfect. Otherwise add 1 and recurse both sides.

Visit everyone. Recurse with the perfect-tree shortcut. Binary search which nodes exist on the last level.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(h)

Classic 1 + count(left) + count(right). Ignores the complete-tree promise. Fine for small n.

### 2. Optimal

- **Time:** O(log² n)
- **Space:** O(log n)

Measure leftmost and rightmost depths. If equal, subtree is perfect: (1 << h) - 1. Else 1 + count(left) + count(right). Each level does O(log n) height work.

### 3. More optimal

- **Time:** O(log² n)
- **Space:** O(1)

Height of leftmost path, then binary search the last level: exists(index) walks h-1 bits from the root. Count = full upper levels + how many last-level nodes exist. Iterative, O(1) extra besides the tree.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
