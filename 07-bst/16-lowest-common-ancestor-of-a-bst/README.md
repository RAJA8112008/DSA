# Lowest Common Ancestor of a BST

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Amazon · Google · Meta · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1)

## Problem

p and q are nodes in a BST. Return their lowest common ancestor — the deepest node that has both in its subtree (a node can be an ancestor of itself).

On a general tree you search both sides. On a BST, if both keys are smaller, LCA is on the left; both larger, on the right; otherwise this node splits them and is the answer.

Brute is the general-tree LCA. Optimal recurses with the BST rule. More optimal is a single while loop.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n)
- **Space:** O(n)

Treat it as a binary tree: recurse. If both sides return a node, this is LCA. If one side does, that node is LCA. Ignores ordering.

### 2. Optimal

- **Time:** O(h)
- **Space:** O(h)

If both values are less than root, recurse left. Both greater, recurse right. Else root is the split point.

### 3. More optimal

- **Time:** O(h)
- **Space:** O(1)

Same split rule in a loop. No recursion. Walk until p and q sit on different sides (or one equals the node).

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
