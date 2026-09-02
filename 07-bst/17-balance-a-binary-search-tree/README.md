# Balance a Binary Search Tree

**Topic:** BST  
**Level:** intermediate  
**Asked at:** Amazon · Google · Microsoft

## Practice

- [LeetCode](https://leetcode.com/problems/balance-a-binary-search-tree/)
- [GFG](https://www.geeksforgeeks.org/convert-normal-bst-into-balanced-bst/)

## Problem

Return a height-balanced BST with the same keys. A tree is balanced if every node's two subtrees differ in height by at most 1.

Inorder dumps the keys in sorted order. Then build from the middle, same as sorted-array-to-BST.

Brute inserts those keys one by one (can stay skewed if you pick poorly). Optimal rebuilds from mid. More optimal is Day-Stout-Warren: vine (right spine) then compress in place.

Use the Brute, Optimal, and More optimal tabs for the three codes.

## Methods of solving

### 1. Brute

- **Time:** O(n²)
- **Space:** O(n)

Inorder keys, then insert in sorted order into a fresh BST. That rebuilds a stick. Shows why you must pick mids, not insert in order.

### 2. Optimal

- **Time:** O(n)
- **Space:** O(n)

Inorder into an array, then mid-as-root rebuild. Height is log n. Extra array of keys (or of nodes if you reuse them).

### 3. More optimal

- **Time:** O(n)
- **Space:** O(1)

DSW: rotate every left child to the right to make a vine (linked list of right pointers). Then repeatedly rotate the vine to fold it into a balanced tree. In-place, O(1) extra besides recursion-free loops.

## Code files

- [javascript.js](./javascript.js)
- [python.py](./python.py)
- [java.java](./java.java)
- [cpp.cpp](./cpp.cpp)
- [c.c](./c.c)
