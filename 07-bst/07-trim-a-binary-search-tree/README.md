# Trim a Binary Search Tree

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Amazon · Google · Apple

## Practice

- [LeetCode](https://leetcode.com/problems/trim-a-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/remove-bst-keys-outside-the-given-range/)

## Problem

Keep only nodes whose values lie in [low, high]. The remaining nodes must still form a BST, and you should reuse existing nodes (not copy values into new ones).

If the node is below low, the whole left side is too small — return the trimmed right. If it is above high, return the trimmed left. Otherwise keep the node and trim both children.

Brute collects in-range keys and rebuilds. Optimal is the recursive prune. More optimal walks iteratively when the root itself is outside the window, then trims children.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Gather every in-range key, sort, rebuild a balanced tree. Correct values, but new nodes and a different shape.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(h)

Postorder prune using the BST property. Reuse the original nodes. If the root is outside the window, drop it and return one trimmed child.

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Move the root iteratively until it sits inside [low, high], then recursively trim the two sides. Fewer frames when the original root is far outside the window.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
