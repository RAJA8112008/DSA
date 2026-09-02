# Diameter of Binary Tree

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/diameter-of-binary-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1)

## Problem

Diameter is the number of edges on the longest path between any two nodes. The path may not pass through the root.

A node with left height 2 and right height 1 has a path of 3 edges through that node. Take the max over all nodes.

Brute recomputes height at every node, O(n²). One DFS returns height and updates diameter. Iterative postorder with a height map avoids recursion.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(h)

At every node, diameter candidate is height(left)+height(right). height itself walks the subtree, so nested walks are quadratic on a skewed tree.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

DFS returns height. While returning, update best with leftHeight + rightHeight. Each node once.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(n)

Iterative postorder. A Map stores height after both children are done. Update diameter from those heights. No call stack; extra map of n heights.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
