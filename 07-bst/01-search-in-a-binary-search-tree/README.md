# Search in a Binary Search Tree

**Topic:** BST  
**Level:** beginner  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/search-in-a-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1)

## Problem

Return the subtree rooted at the node whose value equals val, or null if that key is missing.

The BST property lets you walk one path: go left when val is smaller, right when it is larger.

Brute collects every node and scans. Optimal recurses on one child. More optimal is the same walk in a loop with O(1) extra memory.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Ignore the BST. DFS every node into a list, then scan for val. Correct on any binary tree, but you throw away the ordering.

### 2. Optimal

- **Time:** O(h)
- **Space:** O(h)

Recurse on one child. Each call compares val with the node and drops a whole subtree. Stack depth is the height.

### 3. More optimal

- **Time:** O(h)
- **Space:** O(1)

Same comparisons in a while loop. No call stack. Returns the node or null when the walk falls off.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
