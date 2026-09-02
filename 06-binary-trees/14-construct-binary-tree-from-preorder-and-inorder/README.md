# Construct Binary Tree from Preorder and Inorder

**Topic:** Binary Trees  
**Level:** intermediate  
**Asked at:** Amazon · Microsoft · Google · Adobe

## Practice

- [LeetCode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- [GFG](https://www.geeksforgeeks.org/problems/construct-tree-1/1)

## Problem

Preorder lists root then left then right. Inorder lists left then root then right. Build the unique tree. Values are unique.

preorder [3,9,20,15,7] and inorder [9,3,15,20,7] rebuild the usual 3 / 9 / 20 tree.

Each time search inorder linearly for the root (O(n²)). Map inorder value to index and recurse with bounds. Consume preorder with a pointer and inorder with a stop value, O(n) and no index map lookups.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Root is preorder[0]. Scan inorder for it, slice left/right arrays, recurse. Slicing and scanning are O(n) per node.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

HashMap of inorder indexes. Recurse with (preL, preR, inL, inR) bounds. Each node created once; map lookup O(1).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(h)

Advance a preorder index and an inorder index. build(stop) creates a node, builds left until inorder hits this val, then right until stop. No hashmap; O(h) stack only besides the tree.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
